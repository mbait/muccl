#include "llist.h"

#include <stdio.h>
#include <stdlib.h>

struct intnode
{
  struct llist node;
  int val;
};

void
print_list (struct llist *head)
{
  size_t count = 0;
  struct llist *node = head->next;
  while (node != head)
    {
      ++count;
      node = node->next;
    }
  printf ("List size is %zu\nElements (go forward) :", count);
  node = head->next;
  while (node != head)
    {
      printf (" %2d", ((struct intnode *)node)->val);
      node = node->next;
    }
  printf ("\nElements (go backward):");
  node = head->prev;
  while (node != head)
    {
      printf (" %2d", ((struct intnode *)node)->val);
      node = node->prev;
    }
  printf ("\n");
}

int
main ()
{
  struct llist head = llist_head (head);
  struct intnode *node;
  size_t i;
  for (i = 0; i < 10; ++i)
    {
      node = malloc (sizeof *node);
      node->val = i * i + 1;
      llist_insert (&head, (struct llist *)node);
      print_list (&head);
    }
  while (head.prev != head.next)
    {
      llist_remove (head.next);
      print_list (&head);
    }
  _Exit (0);
}
