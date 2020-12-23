#ifndef _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_

#include <stdint.h>

#define MAX_QUEUE_LEN 32
struct _process_ {
    uint32_t pid;
    uint32_t a_time;
    uint32_t e_time;
    uint32_t priority;
    uint32_t wait_time;
    uint32_t tat_time;
};

typedef struct _process_ Process;

struct _queue_ {
    uint32_t size;                /* actual size */
    uint32_t count;               /* occupied */
    uint32_t head;                /* removing end */
    uint32_t tail;                /* add new items here */
    Process  q[MAX_QUEUE_LEN];    /* queue data */
};
typedef struct _queue_ Queue;

struct _queue_result_ {
    uint32_t pid;
    uint32_t wt;
    uint32_t tat;
    uint32_t status;
};
typedef struct _queue_result_ QueueResult;


#define QUEUE_OK     1
#define QUEUE_FULL   2
#define QUEUE_EMPTY  4
Process  process_new(uint32_t pid, uint32_t at, uint32_t et);
Queue    queue_new(uint32_t size);
Queue*   queue_add(Queue *q, Process *p, QueueResult *result);
Queue*   queue_remove(Queue *q, QueueResult *result);
uint32_t queue_full(Queue *q);
uint32_t queue_empty(Queue *q);

void fcfs_algorithm(Queue *q, QueueResult *res);

#endif


