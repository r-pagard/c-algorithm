#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/singly_linked_list.h"
#include "include/doubly_linked_list.h"
#include "include/circular_singly_linked_list.h"
#include "include/circular_doubly_linked_list.h"


int main() {
	printf("Running Linked List Examples... \n\n");
	
	run_circular_doubly_linked_list_example();

	/*	similarly, can call other example functions for other linked lists here
		e.g.,	run_singly_linked_list_example();
	*/


    return 0;
}
