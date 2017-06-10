#include "llist.h"

#include <stddef.h>

struct llist *
llist_insert (struct llist *head, struct llist *node)
{
  node->prev = head;
  node->next = head->next;
  head->next->prev = node;
  return head->next = node;
}

struct llist *
llist_remove (struct llist *node)
{
  struct llist *prev = node->prev;
  struct llist *next = node->next;
  next->prev = prev;
  return prev->next = next;
}
