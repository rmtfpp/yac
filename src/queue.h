#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "string_f.h"

struct queue_entry
{
    char *data;
    struct queue_entry *next;
};

struct queue
{
    struct queue_entry *front;
    struct queue_entry *back;
    size_t queueSize;
};

struct queue *queue_init(void);

void enqueue (struct queue *q, char *value);

char *front (struct queue *q);

void popQueue (struct queue *q);

void clearQueue (struct queue *q);

void destroyQueue (struct queue **q);


#endif
