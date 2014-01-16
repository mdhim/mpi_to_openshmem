#ifndef      __APP_DEBUG_H
#define      __APP_DEBUG_H

#define PRINT_FILE_DEBUG(format, args...) { if(app_file_debug) fprintf(stderr, "FILE_DEBUG: "format, ##args);}

// See fileinfo.c for definitions of app_file_debug. See fileinfo.h for declarations of debug variables.
#define AppFileDebug(val) {app_file_debug = val;}

#endif
