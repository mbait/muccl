#pragma once

/**
 * Intrusive doubly-linked list.
 *
 * The list is looped.
 * Users can check for NULL or use so called "sentinel" in order to check if the list is empty.
 * The sentinel is simply created as
 *
 *   struct llist *null_node = llist_insert (NULL, NULL);
 */
struct llist
{
  struct llist *prev;
  struct llist *next;
};

/**
 * Inserts new element into the list.
 * @return new list head.
 */
struct llist *
llist_insert (struct llist *, struct llist *);
/**
 * Remove element from the list.
 * @return new list head or NULL.
 */
struct llist *
llist_remove (struct llist *);
