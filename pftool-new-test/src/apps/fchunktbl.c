
#include "fchunktbl.h"

#include <string.h>
#include <stdio.h>

static char *mystrdup(const char *s) {
    char *b;
    if(!(b=malloc(strlen(s)+1))) {
        return NULL;
    }
    strcpy(b, s);
    return b;
}

/**
* Computes the hash key for the File Chunk table.
* Current algorithm is simply to add up the characters
* in the given key - typically a file path.
*
* @param key	a character-based key that identifies the
* 		file.
*
* @return a single number, used to identify an entry
* 	into the File Chunk Table.
*/
hash_size def_hashfunc(const char *key) {
    hash_size hash=0;
    while(*key) {
        hash+=(unsigned char)*key++;
    }
    return hash;
}


FchunkTbl *fchunktbl_create(hash_size size, hash_size (*hashfunc)(const char *)) {
    FchunkTbl *hashtbl;
    if(!(hashtbl=malloc(sizeof(FchunkTbl)))) {
        return NULL;
    }
    if(!(hashtbl->nodes=calloc(size, sizeof(FchunkTblEntry *)))) {
        free(hashtbl);
        return NULL;
    }
    hashtbl->size=size;
    if(hashfunc) {
        hashtbl->hashfunc=hashfunc;
    }
    else {
        hashtbl->hashfunc=def_hashfunc;
    }
    return hashtbl;
}

void fchunktbl_destroy(FchunkTbl *hashtbl) {
    hash_size n;
    FchunkTblEntry *node, *oldnode;
    for(n=0; n<hashtbl->size; ++n) {
        node=hashtbl->nodes[n];
        while(node) {
            free(node->key);
            oldnode=node;
            node=node->next;
            free(oldnode);
        }
    }
    free(hashtbl->nodes);
    free(hashtbl);
}

/**
* Inserts a record into the given file chunk table. If the
* record already exists, then the node is updated with the
* data, and returns.
*
* @param hashtbl	the FchunkTbl to add the record to
* @param key		the un-hashed key to the record. This
* 			is a file path string
* @param data		the data for the record. This is the number
* 			of unprocessed file chunks.
*
* @return 0 if successfully added (or found). < 0 if there are
* 	problems, like allocating memory, or storing the key
* 	in the record.
*/
int fchunktbl_insert(FchunkTbl *hashtbl, const char *key, int data) {
    FchunkTblEntry *node;
    hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
    /*  fprintf(stderr, "fchunktbl_insert() key=%s, hash=%d, data=%s\n", key, hash, (char*)data);*/
    node=hashtbl->nodes[hash];
    while(node) {
        if(!strcmp(node->key, key)) {
            node->data=data;
            return 0;
        }
        node=node->next;
    }
    if(!(node=malloc(sizeof(FchunkTblEntry)))) {
        return -1;
    }
    if(!(node->key=mystrdup(key))) {
        free(node);
        return -1;
    }
    node->data=data;
    node->next=hashtbl->nodes[hash];
    hashtbl->nodes[hash]=node;
    return 0;
}

/**
* Removes the specified record from the file chunk table.
*
* @param hashtbl	the FchunkTbl to access
* @param key		the un-hashed key to the record. This
* 			is a file path string
*
* @return 0 if there are no problems removing the record.
* 	Otherwise a negative number is returned.
*/
int fchunktbl_remove(FchunkTbl *hashtbl, const char *key) {
    FchunkTblEntry *node, *prevnode=NULL;
    hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
    node=hashtbl->nodes[hash];
    while(node) {
        if(!strcmp(node->key, key)) {
            free(node->key);
            if(prevnode) {
                prevnode->next=node->next;
            }
            else {
                hashtbl->nodes[hash]=node->next;
            }
            free(node);
            return 0;
        }
        prevnode=node;
        node=node->next;
    }
    return -1;
}

/**
* Returns the data of a hashed record. If no record
* exists, a negative number is returned.
*
* @param hashtbl	the FchunkTbl to access
* @param key		the un-hashed key to the record. This
* 			is a file path string
*
* @return the data value of the record, if successful. This
* 	should be >= 0. (-1) is returned if the record does
* 	not exist.
*/
int fchunktbl_get(FchunkTbl *hashtbl, const char *key) {
    FchunkTblEntry *node;
    hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
    /*  fprintf(stderr, "fchunktbl_get() key=%s, hash=%d\n", key, hash);*/
    node=hashtbl->nodes[hash];
    while(node) {
        if(!strcmp(node->key, key)) {
            return node->data;
        }
        node=node->next;
    }
    return -1;
}
/**
* Update a hash table record with the given data.
*
* @param hashtbl	the FchunkTbl holding the record to update
* @param key		the un-hashed key to the record. This
* 			is a file path string
* @param data		the data for the record. This is the number
* 			of unprocessed file chunks.
*
* @return 0 if successfully found and updated). < 0 if there is
* 	not record to update.
*/
int fchunktbl_update(FchunkTbl *hashtbl, const char *key, int data) {
    FchunkTblEntry *node;
    hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
    /*  fprintf(stderr, "fchunktbl_get() key=%s, hash=%d\n", key, hash);*/
    node=hashtbl->nodes[hash];
    while(node) {
        if(!strcmp(node->key, key)) {
            node->data = data;
            return 0;
        }
        node=node->next;
    }
    return -1;
}

int fchunktbl_resize(FchunkTbl *hashtbl, hash_size size) {
    FchunkTbl newtbl;
    hash_size n;
    FchunkTblEntry *node,*next;
    newtbl.size=size;
    newtbl.hashfunc=hashtbl->hashfunc;
    if(!(newtbl.nodes=calloc(size, sizeof(FchunkTblEntry *)))) {
        return -1;
    }
    for(n=0; n<hashtbl->size; ++n) {
        for(node=hashtbl->nodes[n]; node; node=next) {
            next = node->next;
            fchunktbl_insert(&newtbl, node->key, node->data);
            fchunktbl_remove(hashtbl, node->key);
        }
    }
    free(hashtbl->nodes);
    hashtbl->size=newtbl.size;
    hashtbl->nodes=newtbl.nodes;
    return 0;
}


