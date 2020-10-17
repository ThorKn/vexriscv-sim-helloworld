#include <stdio.h>

#include <stdint.h>
#include <stddef.h>

#include <errno.h>
#undef errno
extern int errno;

#include "hal.h"

void _putchar(char c) {
    hal_send((uint8_t*)&c, 1);
}

void _write(int fd, const void* ptr, size_t len) {
    // Don't care about the fd.  Just put everything on the UART console.
    (void)fd;
    hal_send(ptr, len);
}

