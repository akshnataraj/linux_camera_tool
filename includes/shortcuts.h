/*****************************************************************************
  This sample is released as public domain.  It is distributed in the hope it
  will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  
  This is the sample code for Leopard USB3.0 camera, shortcut.h stores all the
  useful macro functions, common libraries, global data structures

  Author: Danyu L
  Last edit: 2019/07
*****************************************************************************/
#pragma once

//#include <pthread.h>
#include <sys/types.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h> 
#include <linux/videodev2.h>
#include <linux/usb/video.h>
#include <errno.h>
#include <linux/uvcvideo.h>
#include <sys/fcntl.h>      /** for open() syscall */ 
#include <sys/mman.h>       /** for using mmap */
#include <math.h>           /** pow */
#include "hardware.h"

#define CLEAR(x) memset(&(x), 0, sizeof(x))

/** Get number of elements in an array */
#define SIZE(a) (sizeof(a) / sizeof(*a)) 


/** Loop over an array of given size */
#define FOREACH_NELEM(array, nelem, iter)       \
	for (__typeof__(*(array)) *iter = (array);    \
		iter < (array) + (nelem);                   \
		iter++)

/** Loop over an array of known size */
#define FOREACH(array, iter)                    \
	FOREACH_NELEM(array, SIZE(array), iter)

/**clip value between 0 and 255*/
#define CLIP(value) (uint8_t)(((value)>0xFF)?0xff:(((value)<0)?0:(value)))

#define __THREAD_TYPE pthread_t
#define __THREAD_CREATE(t,f,d) (pthread_create(t,NULL,f,d))
#define __THREAD_CREATE_ATTRIB(t,a,f,d) (pthread_create(t,a,f,d))
#define __THREAD_JOIN(t) (pthread_join(t, NULL))

#define __MUTEX_TYPE pthread_mutex_t
#define __STATIC_MUTEX_INIT PTHREAD_MUTEX_INITIALIZER
#define __INIT_MUTEX(m) ( pthread_mutex_init(m, NULL) )
#define __CLOSE_MUTEX(m) ( pthread_mutex_destroy(m) )
#define __LOCK_MUTEX(m) ( pthread_mutex_lock(m) )
#define __UNLOCK_MUTEX(m) ( pthread_mutex_unlock(m) )

#define _1MS    1
#define _ESC_KEY 27


typedef enum { FALSE, TRUE } BOOL;

struct device
{
    int fd;
    struct buffer *buffers;
    enum v4l2_buf_type type;
    enum v4l2_memory memtype;
    unsigned int nbufs;
    unsigned int width;
    unsigned int height;
    unsigned int bytesperline;
    unsigned int imagesize;
};


