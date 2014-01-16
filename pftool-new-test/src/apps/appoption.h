
#ifndef __APPOPTION_H
#define __APPOPTION_H

#include "../pwt/pwt.h"
#include "../str.h"
#include "app_types.h"

/* Declaration of processfile function type - to be used after a stat call */
typedef int (*processfile_t)(FileInfo *finfo, PerfStat *perf, options o);

/* holds options for treewalking */
struct app_options {
    char start_path[PATHSIZE_PLUS];			// starting path
    char dest_path[PATHSIZE_PLUS];			// destination path
    int quiet;						// quiet flag
    int recursive;					// recursive operation flag
    int meta_only;					// meta data flag
    int verbose;					// verbose flag
    size_t buffersize;					// I/O buffer size - used for compares and transfers
    size_t start_chunking;				// a size in bytes when a single file will be processed in parallel
    processfile_t processfile;				// a function to process a stat-ed file
    int argc;						// count of non-option arguments
    char **args;					// non-option arguments - usually paths
};

/* Declaration of processargs function type - to be used to evaluate application's command line arguments */
typedef int (*processarg_t)(AppOptions *app_o);

#endif
