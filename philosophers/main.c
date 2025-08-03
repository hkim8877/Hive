#include <unistd.h> 

int usleep(useconds_t microseconds);

#include <sys/time.h> 
int gettimeofday(struct timeval *restrict tp, void *restrict tzp); 

_STRUCT_TIMEVAL 
{ 
__darwin_time_t tv_sec; /* seconds */ 
__darwin_suseconds_t tv_usec; /* and microseconds */ 
};

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

int pthread_join(pthread_t thread, void **value_ptr);

int pthread_detach(pthread_t thread);

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);
