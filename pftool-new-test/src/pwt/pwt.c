#include <stdio.h>
#include <stdlib.h>
#include "pwt.h"
#include "worker.h"
#include "manager.h"

static void set_pwt_instance_to_worker(pwt *pwt_instance);
static void set_pwt_instance_to_manager(pwt *pwt_instance);

int pwt_mpi_debug = 0;				// Global MPI debug flag. Declared in libpwt.h
int pwt_poll_debug = 0;				// Global POLL debug flag. Declared in libpwt.h
int pwt_sched_debug = 0;			// Global SCHED debug flag. Declared in libpwt.h

pwt *
pwt_new(pwt_type t){
  pwt *pwt_instance = NULL;

  if (NULL == (pwt_instance = (pwt *)malloc(sizeof(pwt)))){
    PWT_IERR_MSG("out of resources\n");
    printf("pwt::pwt_new out of resources\n");
    return NULL;
  }

  printf("pwt::pwt_new\n");


  switch(t){
    case MANAGER_TYPE:
      printf("pwt::pwt_new MANAGER TYPE\n");
      set_pwt_instance_to_manager(pwt_instance);
      break;
    case WORKER_TYPE:
      printf("pwt::pwt_new WOrKEr TYPE\n");
      set_pwt_instance_to_worker(pwt_instance);
      break;
    default:
      break;
  }

  return pwt_instance;

}

int 
pwt_del(pwt *pwt_instance){
  if (NULL != pwt_instance){
    pwt_instance->fini();
  }
  return PWT_SUCCESS;
}

static void 
set_pwt_instance_to_worker(pwt *pwt_instance){
  printf("pwt::set_pwt_instance_to_worker\n");
  printf("pwt::set_pwt_instance_to_worker\n");
  printf("pwt::set_pwt_instance_to_worker, w_init: %d\n", worker_init);
  printf("pwt::set_pwt_instance_to_worker, w_run: %d\n", worker_run);
  printf("pwt::set_pwt_instance_to_worker, w_fini: %d\n", worker_fini);

  pwt_instance->init = worker_init;
  pwt_instance->run = worker_run;
  pwt_instance->fini = worker_fini;
  return;
}

static void 
set_pwt_instance_to_manager(pwt *pwt_instance){
  printf("pwt::set_pwt_instance_to_manager\n");
  printf("pwt::set_pwt_instance_to_manager, manage_init: %d\n", manager_init);
  printf("pwt::set_pwt_instance_to_manager, manage_run: %d\n", manager_run);
  printf("pwt::set_pwt_instance_to_manager, manage_fini: %d\n", manager_fini);

  pwt_instance->init = manager_init;
  pwt_instance->run = manager_run;
  pwt_instance->fini = manager_fini;
  return;
}
