//
//  huffman.c
//
//  Created by Mandeep Singh on 03/07/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
//Utilizing priority queue with huffman coding to make a file compresser
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//Import libraries for usage
#include "pack.h"
#include "pqueue.h"

struct node *mkNode(int data, struct node *left, struct node *right);
int compare(struct node *node1, struct node *node2);
void in(char *fIn, char *fOut);
int depth(struct node *node);
struct node *nodes[257];

//O(1)
int main(int argc, char *argv[]){
    if(argc == 2){
        printf("Wrong args\n");
        return 1;
    }
    
    in(argv[1], argv[2]);
    return 0;
}

//O(1)
struct node *mkNode(int data, struct node *left, struct node *right){
    assert(left != NULL && right != NULL);
    struct node *newNode = malloc(sizeof(struct node));
    assert(newNode != NULL);
    newNode -> count = data;
    left -> parent = newNode;
    right -> parent = newNode;
    return newNode;
}

//O(1)
int compare(struct node *node1, struct node *node2){
    assert(node1 != NULL && node2 != NULL);
    return (node1 -> count < node2 -> count) ? -1 : (node1 -> count > node2 -> count);
}

//O(1)
int depth(struct node *node){
    if(node -> parent == NULL)
        return 0;
    return 1 + depth(node -> parent);
}

//O(n)
void in(char *fIn, char *fOut){
    FILE *fp;
    
    fp = fopen(fIn, "r"); //Opens file
    if (fp == NULL)
        return;
    
    int arr[257]; //Creating array with each index holding the number of occurences for a different character
    
    for(int i = 0; i < 257; i++){
        arr[i] = 0;
        nodes[i] = NULL;
    }
    
    int j;
    while((j = fgetc(fp)) != EOF){ //Count number of occurences of each character
        arr[j]++;
    }
    
    for(int k = 0; k < 256; k++){ //creating leaves
        if(arr[k] != 0){
            struct node *leaf = malloc(sizeof(struct node));
            assert(leaf != NULL);
            leaf -> count = arr[k];
            nodes[k] = leaf;
        }
    }
    
    struct node *eLeaf = malloc(sizeof(struct node)); //creating the end leaf of the file
    assert(eLeaf != NULL);
    eLeaf -> count = 0;
    nodes[256] = eLeaf;
    fclose(fp);
    
    PQ *priorityQueue = createQueue(compare); //Creating the heap pq
    for(int l = 0; l < 257; l++) {
        if (nodes[l] != NULL) {
            addEntry(priorityQueue, nodes[l]);
        }
    }
    
    while(numEntries(priorityQueue) > 1) { //Creating the huffman tree with pq
        struct node *node1 = removeEntry(priorityQueue);
        struct node *node2 = removeEntry(priorityQueue);
        struct node *temp = mkNode((node1 -> count) + (node2 -> count), node1, node2);
        addEntry(priorityQueue, temp);
    }
    
    for(int m = 0; m < 257; m++) { //printing the data
        if (nodes[m] != NULL) {
            if (isprint(m)) {
                printf("\'%c\': ", m);
            } else {
                printf("%o: ", m);
            }
            printf("%d x %d bits = %d bits\n", arr[m], depth(nodes[m]), arr[m] * depth(nodes[m]));
        }
    }
    
    pack(fIn, fOut, nodes); //pack nodes
    destroyQueue(priorityQueue); //destroy the queue
}
