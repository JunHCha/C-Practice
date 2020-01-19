//
//  main.c
//  20강 리스트
//
//  Created by 차준형 on 25/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int list[100], count = 0;

void addBack(int data) {
    list[count] = data;
    count ++;
}

void addFront(int data) {
    for(int i = count; i > 0; i--)
        list[i] = list[i - 1];
    list[0] = data;
    count++;
}

void printList() {
    for(int i = 0; i < count; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void removeNode(int index) {
    for(int i = index; i < count - 1; i++) {
        list[i] = list[i + 1];
    }
    count--;
}
//The Linked List functions based on Array

typedef struct Node {
    int data;
    struct Node *next;
} Node ;

Node *head;

void addNodeFront(Node *root, int dt) {
    Node *new = (Node*)malloc(sizeof(Node));
    Node *temp = root->next;
    new->data = dt;
    root->next = new;
    new->next = temp;
}

void removeNodeFront(Node *root) {
    Node *temp = root->next;
    root->next = temp->next;
    free(temp);
}

void showAll(Node *root) {
    Node *cur = root->next;
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

void freeAll(Node *root) {
    Node *cur = root->next;
    while(cur != NULL) {
        free(cur);
        cur = cur->next;
    }
    free(root);
}

int main(int argc, const char * argv[]) {
    addBack(1);
    addBack(2);
    addBack(3);
    addBack(4);
    addBack(5);
    addBack(6);
    addFront(2);
    addFront(3);
    addFront(4);
    addFront(5);
    addFront(6);
    addFront(7);
    addFront(8);
    printList();
    removeNode(0);
    removeNode(7);
    printList();
    //Array List
    
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    addNodeFront(head, 1);
    addNodeFront(head, 2);
    addNodeFront(head, 3);
    addNodeFront(head, 4);
    addNodeFront(head, 5);
    removeNodeFront(head);
    showAll(head);
    freeAll(head);
    //Linked List
    return 0;
}
