
#ifndef __FCHUNKTBL_H
#define __FCHUNKTBL_H

#include<stdlib.h>

typedef size_t hash_size;

typedef struct hashtbl {
    hash_size size;
    struct hashtbl_entry **nodes;
    hash_size (*hashfunc)(const char *);
} FchunkTbl;

typedef struct hashtbl_entry {
    char *key;
    int data;
    struct hashtbl_entry *next;
} FchunkTblEntry;

FchunkTbl *fchunktbl_create(hash_size size, hash_size (*hashfunc)(const char *));
void fchunktbl_destroy(FchunkTbl *hashtbl);
int fchunktbl_insert(FchunkTbl *hashtbl, const char *key, int data);
int fchunktbl_remove(FchunkTbl *hashtbl, const char *key);
int fchunktbl_update(FchunkTbl *hashtbl, const char *key, int data);
int fchunktbl_get(FchunkTbl *hashtbl, const char *key);
int fchunktbl_resize(FchunkTbl *hashtbl, hash_size size);

/* hash function */
hash_size def_hashfunc(const char *key);

#endif

