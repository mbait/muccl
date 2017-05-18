#include <stdlib.h>
#include "llist.h"


struct llist *
llist_insert (struct llist * restrict head, const void *data)
{
  struct llist *node;
  if (!(node = malloc (sizeof *node))) {
    return NULL;
  }
  node->next = node;
  node->data = data;

  head = head ?: node;
  node->prev = head;
  node->next = head->next;
  head->next->prev = node;
  head->next = node;
  return node;
}


struct llist *
llist_remove (struct llist *node)
{
  struct llist *prev = node->prev;
  struct llist *next = node->next;
  next->prev = prev;
  prev->next = next;
  free (node);

  return prev == next ? NULL : next;
}
