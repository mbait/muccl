#include <stdatomic.h>
#include "ref.h"

void *
ref_add_ref (struct ref *ref)
{
  atomic_fetch_add ((size_t *) &ref->count, 1);
  return ref;
}


void 
ref_release (struct ref *ref)
{
  if (atomic_fetch_sub ((size_t *) &ref->count, 1) == 1) {
    ref->free (ref);
  }
}
