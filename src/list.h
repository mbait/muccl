#pragma once

/**
 * Intrusive doubly-linked list.
 *
 * The list is looped, and when empty its head node must have both
 * pointers have the same value pointing to the head.
 */
struct list
{
  struct list *prev;
  struct list *next;
};

#define list_head(head)                                                      \
  {                                                                           \
    .prev = &head, .next = &head                                              \
  }

/**
 * Inserts new element into the list.
 * @return new list head.
 */
struct list *list_insert (struct list *, struct list *);
/**
 * Remove element from the list.
 * @return new list head or NULL.
 */
struct list *list_remove (struct list *);
