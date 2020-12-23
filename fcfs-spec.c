#include <assert.h>
#include "scheduler.h"
#include <stdio.h>

void fcfs_scheduler()
{
    Process p1 = process_new(1,0,5);
    Process p2 = process_new(2,2,8);
    Process p3 = process_new(3,4,2);
    Process p4 = process_new(4,4,4);



    Queue q = queue_new(10);
    QueueResult res;

    queue_add(&q,&p1,&res);
    queue_add(&q,&p2,&res);
    queue_add(&q,&p3,&res);
    queue_add(&q,&p4,&res);


    fcfs_algorithm(&q,&res);

    //queue_remove(&q,&res);
    assert(res.pid == 1);
    assert(res.wt  == 0);
    assert(res.tat == 5);

    fcfs_algorithm(&q,&res);
   // queue_remove(&q,&res);
    assert(res.pid == 2);
    assert(res.wt  == 3);
    assert(res.tat == 11);

    fcfs_algorithm(&q,&res);
    //queue_remove(&q,&res);
    assert(res.pid == 3);
    assert(res.wt  == 9);
    assert(res.tat == 11);

    fcfs_algorithm(&q,&res);
    //queue_remove(&q,&res);
    assert(res.pid == 4);
    assert(res.wt  == 11);
    assert(res.tat == 15);

    assert(queue_empty(&q));

}

int main()
{
    fcfs_scheduler();

    return 0;
}
