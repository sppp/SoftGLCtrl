/*
 * Memory allocator for TinyGL
 */
#include "ZGl.h"

/* modify these functions so that they suit your needs */

void gl_free(void *p) {
	MemoryFree(p);
}

void *gl_malloc(int size) {
	return MemoryAlloc(size);
}

void *gl_zalloc(int size) {
	void* mem = MemoryAlloc(size);
	memset(mem, 0, size);
	return mem;
}
