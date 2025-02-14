#include <stdio.h>
#include <stdlib.h>

#include "include/queue.h"
#include "include/queue_linked_list.h"


int main() {

    // Regular Queue
    printf("\nThe Regular Queue Test In Main:\n\n");

	RegularQueue *regularQ;
	regularQ = initialRegular(5);
	enqueue(regularQ, 1);
	enqueue(regularQ, 3);

	printf("\n\tBefore Deletion Action:\n");
	printf("\tSize:%d\t\tFront:%d\t\tRear:%d\t\tCapacity:%d\n", regularQ->size, regularQ->front, regularQ->rear, regularQ->capacity);

	printf("\tItem %d Deleted.\n", dequeue(regularQ));

	printf("\n\tAfter Deletion Action:\n");
	printf("\tSize:%d\t\tFront:%d\t\tRear:%d\t\tCapacity:%d\n", regularQ->size, regularQ->front, regularQ->rear, regularQ->capacity);

	free(regularQ);

    // Circular Queue
    printf("\nThe Circular Queue Test In Main:\n\n");

    CircularQueue *circularQ;
	circularQ = initialCicular(4);
	enqueueCicular(circularQ, 3);
	enqueueCicular(circularQ, 6);
	enqueueCicular(circularQ, 9);
	printf("\tBefore Deletion Action:");
	show(circularQ);

	printf("\n\n\tAfter Deletion Action:");
	int item = dequeueCicular(circularQ);
	show(circularQ);
	printf("\n\n");

	free(circularQ);


	// Regular Queue Linked List
	printf("\nThe Regular Queue Linked List, Test In Main:\n\n");

	RegularQueueLinkedList *regularQLL;	// initialize a new Regular Queue Linked List
	regularQLL = initialRegularQueueLinkedList(4);
	enqueueLinkedList(regularQLL, 7);
	enqueueLinkedList(regularQLL, 9);
	enqueueLinkedList(regularQLL, 2);
	printf("\tThe Front Of Queue: %d\n", getFront(regularQLL));
	printf("\tThe Rear Of Queue: %d\n", getRear(regularQLL));

	dequeueLinkedList(regularQLL);
	printf("\n\tThe Front Of Queue After Deletion: %d\n", getFront(regularQLL));

	printf("\n");

    return 0;
}
