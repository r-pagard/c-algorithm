#ifndef CIRCULAR_DOUBLY_LINKED_LIST
#define CIRCULAR_DOUBLY_LINKED_LIST

typedef struct node_circular_doubly {
	int data;
	struct node_circular_doubly *next;
	struct node_circular_doubly *previous;
} NodeCircularDoubly;

NodeCircularDoubly *initializeCircularDoubly(int value);
void insertBeginCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last, int value);
void insertLastCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last, int value);

void deleteFirstCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last);
void deleteLastCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last);
void deleteWholeListCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last);

void displayCircularDoubly(NodeCircularDoubly **head, NodeCircularDoubly **last);


void run_circular_doubly_linked_list_example();

#endif // CIRCULAR_DOUBLY_LINKED_LIST
