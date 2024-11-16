#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../include/binary_tree.h"


Node *initializeNode(int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Couldn't Allocate...\n");
        return NULL;    // return NULL if memory allocation fails
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;    // return the new node
}

int heightNode(Node *node) {
    /*  finds the height of the binary tree node

        @node: pointer to the node to find the height of

        return -1 if the node is NULL (no heigh),
        return 0 if the node has no children (leaf node),
        otherwise, return 1 plus the height of the greater subtree
    */

    int left_height, right_height;  // height of the left and right subtrees

    if(node == NULL) return -1; // return -1 for NULL nodes, indicating no height
    else if( (node->left == NULL) && (node->right == NULL) )
        return 0;   // return 0 for leaf nodes, as they have height 0
    else
    {
        // calculate the heights of left and right subtrees
        left_height = heightNode(node->left);
        right_height = heightNode(node->right);

        /*  return the greater height between left and right subtrees,
            adding 1 to account for the current node level
        */
        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
}

unsigned int leafQuantity(Node *node) {
    /*  return the total quantity of leafs

        @node: pointer to the current node being checked

        return 0 if the node is NULL,
        return 1 if the node is leaf,
        otherwise, return the sum of leaf counts
        from the left and right subtrees
    */
    
    if(node == NULL) return 0;  // return 0 for NULL nodes
    else if( (node->left == NULL) && (node->right == NULL) ) return 1;  // return 1 for the leaf node

    // count leaf nodes in the left and right subtrees
    else return ( leafQuantity(node->left) + leafQuantity(node->right) );
}

unsigned int nodesQuantity(Node *node) {
    /*  return the total quantity of nodes

        @node: pointer to the current node being checked

        return 0 if the node is NULL,
        otherwise, return the sum of node counts
        from the left and right subtree and at the end plus 1
    */

    return (node == NULL) ? 0 : (1 + nodesQuantity(node->left) + nodesQuantity(node->right));
}

int maxNode(Node *node) {
    /*  find the maximum node of binary tree

        @node: pointer to the node to find the maximum of

        return INT_MIN if the node is NULL,
        otherwise, return the maxium node of the greater subtree
    */
    
    int max, left_max, right_max;   // maximum of the left and right subtrees

    if(node == NULL) return INT_MIN;

    max = node->data;
    // find the maximum node of left and right subtrees
    left_max = maxNode(node->left);
    right_max = maxNode(node->right);

    // save the greater node between left and right subtrees to the `max` variable
    max = (left_max > max ? left_max : max);
    max = (right_max > max ? right_max : max);

    return max; // return the maximum node
}


void deleteTree(Node **node) {
    /*  delete all nodes in the binary tree, delete the whole tree

        @node: pointer to the current node being deleted

        recursively deletes the left and right subtrees, then
        delete the current node itself and each deletion is printed
    */

    if(node == NULL || *node == NULL) return;

    deleteTree(&(*node)->left); // delete all nodes in the left subtree
    deleteTree(&(*node)->right);    // delete all nodes in the right subtree

    printf("\tDelete the node (%d)\n", (*node)->data); // print each node during deletion

    free(*node); // free memory of the current node
    *node = NULL;   // set the root node to the NULL
}
