#pragma once

#include <stddef.h> 

struct ref
{
  size_t count;
  void (*free) (void *);
};

void * ref_add_ref (struct ref *);
void   ref_release (struct ref *);

// TODO: weak references
