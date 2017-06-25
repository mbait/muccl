#include "list.h"

struct list *
list_insert (struct list *head, struct list *node)
{
  node->prev = head;
  node->next = head->next;
  head->next->prev = node;
  return head->next = node;
}

struct list *
list_remove (struct list *node)
{
  struct list *prev = node->prev;
  struct list *next = node->next;
  next->prev = prev;
  return prev->next = next;
}
