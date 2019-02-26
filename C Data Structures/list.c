//
//  list.c
//
//  Created by Mandeep Singh on 02/14/19.
//  Copyright © 2019 Mandeep Singh. All rights  .
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"  //Import libraries for usage

typedef struct list{ //Define our struct list
    int count; //Number of elements in list
    struct node *head; //Pointer to node structure
    int (*compare)(); //Pointer to compare function passed through
}LIST;

typedef struct node{ //Define out struct node
    void *data; //pointer to data
    struct node *next; //pointer to next list elt
    struct node *prev; //pointer to prev list elt
}NODE;

//O(1)
LIST *createList(int(*compare)()){ //Creates out set using variables initialized in struct list
    struct list *lp;
    lp = malloc(sizeof(struct list)); //Allocate memory for list
    assert(lp != NULL); //Make sure list memory allocation is not NULL
    lp -> count = 0; //Initially set count to 0
    lp -> compare = compare;
    lp -> head = malloc(sizeof(struct node)); //Allocate memory for dummy node
    assert(lp -> head != NULL);
    lp -> head -> next = lp -> head; //Initially set head next pointer to head
    lp -> head -> prev = lp -> head; //Initially set head prev pointer to head
    return lp;
}

//O(n)
void destroyList(LIST *lp){
    assert(lp != NULL);
    NODE *pDel = lp -> head -> prev; //Set pDel to node we want to delete
    NODE *pPrev;
    while(pDel != lp -> head){ //Starting from first node to last each node is freed
        pPrev = pDel -> prev;
        free(pDel);
        pDel = pPrev;
    }
    free(pDel); //Free pDel
    free(lp); //free list
}

//O(1)
int numItems(LIST *lp){ //Return number of items in list
    return lp -> count;
}


//O(1)
void addFirst(LIST *lp, void *item){
    NODE *pNew;
    pNew -> next = lp -> head;
    pNew -> prev = lp -> head;
    lp -> head -> next = pNew;
    if(lp -> count == 0)
        lp -> head -> prev = pNew;
    lp -> count++; //Add one from count to account for adding an elt
}

//O(1)
void addLast(LIST *lp, void *item){
    NODE *pNew;
    NODE *pPrev = lp -> head -> prev;
    pNew -> next = lp -> head;
    pNew -> prev = pPrev;
    lp -> head -> prev = pNew;
    pPrev -> next = pNew;
    lp -> count++; //Add one from count to account for adding an elt
}

//O(1)
void *removeFirst(LIST *lp){
    NODE *pDel = lp -> head -> next;
    NODE *pNext = pDel -> next;
    lp -> head -> next = pNext;
    pNext -> prev = lp -> head;
    void* x = pDel -> data;
    free(pDel);
    lp -> count--; //Subtract one from count to account for deleting an elt
    return x;
}

//O(1)
void *removeLast(LIST *lp){
    NODE *pDel = lp -> head -> prev;
    NODE *pPrev = pDel -> prev;
    lp -> head -> next = pPrev;
    pPrev -> next = lp -> head;
    void* x = pDel -> data;
    free(pDel);
    lp -> count--; //Subtract one from count to account for deleting an elt
    return x;
}

//O(1)
void *getFirst(LIST *lp){ //Use head next to return first elt
    return lp -> head -> next -> data;
}

//O(1)
void *getLast(LIST *lp){ //Use head prev to return first elt
    return lp -> head -> prev -> data;
}

//O(n)
void removeItem(LIST *lp, void *item){
    NODE *pSearch = lp -> head -> next;
    
    while(pSearch -> data != NULL){ //Dummy node head has no data
        if(lp -> compare(pSearch -> data, item) == 0){ // error possibility
            NODE *pPrev = pSearch -> prev;
            NODE *pNext = pSearch -> next;
            pPrev -> next = pNext;
            pNext -> prev = pPrev;
            free(pSearch);
            lp -> count--;
        }else
            pSearch = pSearch -> next;
    }
}

//O(n)
void *findItem(LIST *lp, void *item){
    NODE *pSearch = lp -> head -> next;
    
    while(pSearch -> data != NULL){
        if(lp -> compare(pSearch -> data, item) == 0)
            return pSearch -> data;
        else
            pSearch = pSearch -> next;
    }
    return NULL;
}

//O(n)
void *getItems(LIST *lp){
    NODE *pSearch = lp -> head -> next;
    void** ret = malloc(sizeof(void*)* lp -> count); //Allocate memory for array size of count
    assert(ret != NULL);
    int i = 0;
    
    while(pSearch -> data != NULL){
        ret[i] = pSearch -> data;
        i++;
        pSearch = pSearch -> next;
    }
    return ret;
}
