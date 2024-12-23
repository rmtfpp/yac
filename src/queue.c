#include "queue.h"

struct queue *queue_init (void)
{
    struct queue *q = malloc(sizeof *q);
    if(q)
    {
	q->front = NULL;
	q->back = NULL;
	q->queueSize = 0;
    }
    return q;
}


void enqueue (struct queue *q, char *value)
{
    struct queue_entry *entry = malloc(sizeof *entry);
    if(entry)
    {
	entry->data = strdup(value);
	entry->next = NULL;

	if (q->back) // se non e' vuota
	{
	    q->back->next = entry;
	}
	else
	{
	    q->front = entry;
	}

	q->back = entry;
	q->queueSize++;
    }
    else
    {
	exit(EXIT_FAILURE);
    }
}

char *front (struct queue *q)
{
    if (q && q->front) return q->front->data;
    else return NULL;
}

void popQueue (struct queue *q)
{
    if (q->front != NULL)
    {
	struct queue_entry *tmp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
        {
            q->back = NULL;
        }
	
	free(tmp->data);
	free(tmp);
	q->queueSize--;
    }
}

void clearQueue (struct queue *q)
{
    if (q)
    {
        while (q->front != NULL) popQueue(q);
    }
}

void destroyQueue (struct queue **q)
{
    clearQueue(*q);
    free(*q);
    *q = NULL;
}
