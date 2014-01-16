
#ifndef __FILEINFO_H
#define __FILEINFO_H

#include "../pwt/pwt.h"
#include "app_types.h"		

extern int app_file_debug;			// Global debug flag. See app/debug.h and fileinfo.c

#define _FILEINFO_TYPE_      ((long)19641111)	// value used to mark structure as a FileInfo
#define _FILEPAIR_TYPE_	     ((long)19640704)	// value used to mark structure as a FilePair
#define _FILEWORK_TYPE_	     ((long)19641225)	// value used to mark structure as a FileWork
#define _FILEWORKSTAT_TYPE_  ((long)19641019)	// value used to mark structure as a FileWorkStat
#define FILE_BUFFER_MAX 50			// maximum number of FileInfo structures in a FileWork buffer

/* structure to hold file information */
struct file_info {
    long type;					// holds a value that marks this structure as a FileInfo
    int exists;					// a flag to indicate that the file exists (-1) means stat() has not been run for file
    char path[PATHSIZE_PLUS];
    struct stat st;
    off_t offset;
    size_t length;
};

/* structure to define a source/destination pair of files */
struct file_pair {
    long type;					// holds a value that marks this structure as a FilePair
    int chunknum;				// the number of the chunk to be processed from this FilePair. (-1) means file is not chunked!
    int matched;				// a flag which indicates if the pair is matched/same or not
    FileInfo src;				// the source file for the pair
    FileInfo dest;				// the destination file for the pair
};
typedef struct file_pair FilePair;

struct file_workbuffer {
    long type;					// holds a value that marks this structure as a FileWork
    int size;					// size or number of items in buffer
    FileInfo buf[FILE_BUFFER_MAX];		// the buffer of FileInfo structures
};
typedef struct file_workbuffer FileWork;

/* structure to hold the raw stats from processing a pair of files */
struct file_work_stat {
    long type;					// holds a value that marks this structure as a FileWorkStat
    FilePair files;				// the FilePair structure of the files (or portion of files) that are/were processed
    PerfStat perf;				// the PerfStat structure holding performance information regarding the processing of these files
};
typedef struct file_work_stat FileWorkStat;

/* functions to create and manage file info structures */
FileInfo *fileinfo_new(char *pname, struct stat *statinfo);
FileInfo *fileinfo_del(FileInfo *finfo);
void fileinfo_init(FileInfo *finfo, char *pname, struct stat *statinfo);
int fileinfo_isChunkable(FileInfo *finfo, AppOptions *app_o); 
int fileinfo_lstat(FileInfo *finfo);

/* functions to create and manage file pair structures */
FilePair *filepair_new(FileInfo *src, FileInfo *dest);
FilePair *filepair_del(FilePair *fpair);

/* functions to create and manage file work status structures */
FileWorkStat *fileworkstat_new(FilePair *fpair, PerfStat *perf);
FileWorkStat *fileworkstat_del(FileWorkStat *fstat);
void fileworkstat_init(FileWorkStat *fstat, FilePair *fpair, PerfStat *perf);


/* WorkItem support functions */
void fileinfo_attach(FileInfo *finfo, WorkItem *item);
void filepair_attach(FilePair *fpair, WorkItem *item);
void fileworkstat_attach(FileWorkStat *fstat, WorkItem *item);
FileInfo *workitem_get_fileinfo(WorkItem *item);
FilePair *workitem_get_filepair(WorkItem *item);
FileWorkStat *workitem_get_fileworkstat(WorkItem *item);
int workitem_hasFileinfo(WorkItem *item);
int workitem_hasFilepair(WorkItem *item);
int workitem_hasFileworkstat(WorkItem *item);

#endif
