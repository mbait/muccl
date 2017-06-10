#pragma once

#include <stddef.h>

struct ref
{
  size_t count;
  void (*free) (void *);
};

// clang-format off
void * ref_add_ref (struct ref *);
void   ref_release (struct ref *);
// clang-format on

// TODO: weak references
