/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if(q == NULL) {
      return NULL;
    } else {
      q->head = NULL;
      q->tail = NULL;
      q->size = 0;
      return q;
    }
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    if(q == NULL) {
      return;
    } else {
      list_ele_t *temp;
      while(q->head != NULL) {
        temp = q->head->next;
        free(q->head->value);
        free(q->head);
        q->head = temp;
      }
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newhead;
    /* What should you do if the q is NULL? */
    if(q != NULL) {
    newhead = malloc(sizeof(list_ele_t));
    if(newhead == NULL) {
      return false;
    }
    /* Don't forget to allocate space for the string and copy it */
    size_t strlength = strlen(s) + 1;
    newhead->value = malloc(strlength*sizeof(char));
    /* What if either call to malloc returns NULL? */
    if(newhead->value == NULL) {
      free(newhead);
      return false;
    }
    strcpy(newhead->value, s);
    newhead->next = q->head;
    q->head = newhead;
    if(q->size != 0) {
    } else {
      q->tail = newhead;
    }
    q->size = q->size + 1;
    return true;
    } else {
      return false;
    }
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if(q != NULL) {
    list_ele_t *newt;
    newt = malloc(sizeof(list_ele_t));
    if(newt == NULL) {
      return false;
    }
    size_t strlength = strlen(s) + 1;
    newt->value = malloc(strlength*sizeof(char));
    if(newt->value == NULL) {
      free(newt);
      return false;
    }

    strcpy(newt->value, s);

    if(q->size == 0) {
      q->head = newt;

    }
    else {
      q->tail->next = newt;
    }
    q->tail = newt;
    newt->next = NULL;
    q->size = q->size + 1;
    return true;
    } else {
      return false;
    }
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
  if(q != NULL  && bufsize >= 1 && q->head != NULL) {
  if(sp != NULL) {
    strncpy(sp, q->head->value, bufsize - 1);
    sp[bufsize - 1] = (char) 0;
  }  
  /* You need to fix up this code. */
  list_ele_t *newh = q->head->next;
  free(q->head->value);
  free(q->head);
  q->head = newh;
  q->size = q->size - 1;
  return true;
  } else {
    return false;
  }
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if(q != NULL && q->head != NULL) {
      return q->size;
    } else {
      return 0;
    }
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if(q == NULL || q->size <= 1) {

    } else {
      list_ele_t *next;
      list_ele_t *prev = NULL;
      list_ele_t *curr = q->head;
      q->tail = q->head;
      while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      q->head = prev;
    }
}

