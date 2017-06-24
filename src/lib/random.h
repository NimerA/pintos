#ifndef __LIB_RANDOM_H
#define __LIB_RANDOM_H

#include <stddef.h>

void random_init (unsigned seed);
void random_bytes (void *, size_t);
unsigned long random_ulong (void);
unsigned int random_uint (void);

#endif /* lib/random.h */
