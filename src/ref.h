#pragma once

#include <stddef.h> 

struct ref
{
  void (*free) (const void *);
  size_t count;
};

void * ref_add_ref (struct ref *);
void   ref_release (struct ref *);

// TODO: weak references
