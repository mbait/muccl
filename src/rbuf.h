#pragma once

struct rbuf
{
  size_t cap; // Capacity.
  size_t len; // Length.
  size_t src; // Offset.
  char buf[]; // Data.
};


struct rbuf * rbuf_alloc (size_t size) __attribute__ ((malloc));

size_t rbuf_write (struct rbuf *, const void * , size_t);
size_t rbuf_read (struct rbuf *, void * , size_t);
