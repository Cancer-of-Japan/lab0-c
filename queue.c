#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q != NULL) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    } else {
        return NULL;
    }
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    while (q->size) {
        q_remove_head(q, NULL, 0);
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (q == NULL) {
        return false;
    }

    list_ele_t *newh;
    if ((newh = malloc(sizeof(list_ele_t))) == NULL) {
        return false;
    }

    newh->next = NULL;
    // newh = malloc(sizeof(list_ele_t));
    q->head = newh;

    if (q->tail == NULL) {
        q->tail = newh;
    }
    q->size++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt = malloc(sizeof(list_ele_t));
    // When list is empty
    if (q->head == NULL) {
        return false;
    }
    // When newh is NULL
    if ((newt = malloc(sizeof(list_ele_t))) == NULL) {
        return false;
    }
    newt->next = NULL;

    // int len = strlen(s) + 1;

    if (q->tail != NULL) {
        q->tail->next = newt;
    }
    q->tail = newt;
    if (q->head == NULL) {
        q->head = newt;
    }
    q->size++;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (q == NULL || q->size == 0) {
        return false;
    }

    list_ele_t *rm = q->head;
    if (sp != NULL) {
    }
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    q->size--;
    free(rm->value);
    free(rm);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q == NULL) {
        return 0;
    }
    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL || q->size == 0) {
        return;
    }
    /*
     list_ele_t *cursor = q -> head;
     list_ele_t *nxt = cursor -> head;
     q -> head = q -> tail;
     q -> tail = cursor;
     q -> tail -> next = NULL;

     while(nxt != NULL){
         list_ele_t *nxt_nxt = nxt -> next;
         nxt -> next -> cursor;
         cursor = nxt;
         nxt = nxt_nxt;
     }
     */
    list_ele_t *done = NULL, *cursor = q->head, *next;
    q->tail = q->head;
    while (cursor) {
        next = cursor->next;
        cursor->next = done;
        done = cursor;
        cursor = next;
    }
    q->head = done;
    return;
}

/*
 * Sort elements of queue in asctailing order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
