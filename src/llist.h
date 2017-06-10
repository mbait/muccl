#pragma once

/**
 * Intrusive doubly-linked list.
 *
 * The list is looped, and when empty its head node must have both
 * pointers have the same value pointing to the head.
 */
struct llist
{
  struct llist *prev;
  struct llist *next;
};

#define llist_head(head)                                                      \
  {                                                                           \
    .prev = &head, .next = &head                                              \
  }

/**
 * Inserts new element into the list.
 * @return new list head.
 */
struct llist *llist_insert (struct llist *, struct llist *);
/**
 * Remove element from the list.
 * @return new list head or NULL.
 */
struct llist *llist_remove (struct llist *);
