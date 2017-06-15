#include "rbuf.h"

#include <stdlib.h>
#include <string.h>

struct rbuf *
rbuf_alloc (size_t size)
{
  struct rbuf *rbuf;
  if (!(rbuf = malloc (sizeof *rbuf + size))) {
    return NULL;
  }

  rbuf->cap = size;
  rbuf->len = 0;
  rbuf->src = 0;
  return rbuf;
}

#define MIN(a, b) ((a) <= (b) ? (a) : (b))

size_t
rbuf_read (struct rbuf *rbuf, void *ptr, size_t size)
{
  char *restrict dest = ptr;
  size = MIN (rbuf->len, size);
  size_t nread = MIN (rbuf->cap - rbuf->src, size);
  memcpy (dest, rbuf->buf + rbuf->src, nread);
  memcpy (dest + nread, rbuf->buf, size - nread);
  rbuf->src = (rbuf->src + size) % rbuf->cap;
  rbuf->len -= size;
  return size;
}

size_t
rbuf_write (struct rbuf *rbuf, const void *ptr, size_t size)
{
  const char *restrict src = ptr;
  size = MIN (rbuf->cap - rbuf->len, size);
  size_t offset = (rbuf->src + rbuf->len) % rbuf->cap;
  size_t nwrit = MIN (rbuf->cap - offset, size);
  memcpy (rbuf->buf + offset, src, nwrit);
  memcpy (rbuf->buf, src + nwrit, size - nwrit);
  rbuf->len += size;
  return size;
}
