//
//  main.c
//  21강 양방향 리스트
//
//  Created by 차준형 on 28/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//Auto - ascending double directed list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

void insert(int dt) {
    Node* node = (Node*)malloc(sizeof(Node));
    Node* cur = head->next;
    node->data = dt;
    while(cur->data < dt && cur != tail) {
        cur = cur->next;
    }
    Node* cPrev = cur->prev;
    cPrev->next = node;
    node->prev = cPrev;
    cur->prev = node;
    node->next = cur;
}

void removeMinimum() {
    Node* cur = head->next;
    Node* cNext = cur->next;
    head->next = cNext;
    cNext->prev = head;
    free(cur);
}

void removeMaximum() {
    Node* cur = tail->prev;
    Node* cPrev = cur->prev;
    tail->prev = cPrev;
    cPrev->next = tail;
    free(cur);
}

void removeNthSmall(int index) {
    Node* cur = head->next;
    while(--index) {
        cur = cur->next;
    }
    Node* cNext = cur->next;
    Node* cPrev = cur->prev;
    cPrev->next = cNext;
    cNext->prev = cPrev;
    free(cur);
}

void removeNthLarge(int index) {
    Node* cur = tail->prev;
    while(--index) {
        cur = cur->prev;
    }
    Node* cNext = cur->next;
    Node* cPrev = cur->prev;
    cPrev->next = cNext;
    cNext->prev = cPrev;
    free(cur);
}

void showAll() {
    Node* cur = head->next;
    while(cur != tail) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    cur = tail->prev;
    while(cur != head) {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n\n");
}

void freeAll() {
    Node* cur = head->next;
    while(cur != tail) {
        free(cur);
        cur = cur->next;
    }
    free(head);
    free(tail);
}



int main(int argc, const char * argv[]) {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
    insert(2);
    insert(3);
    insert(1);
    insert(4);
    showAll();
    removeMinimum();
    showAll();
    removeMaximum();
    insert(0);
    insert(8);
    insert(5);
    insert(9);
    insert(22);
    insert(-3);
    showAll();
    removeNthSmall(2);
    removeNthLarge(2);
    showAll();
    freeAll();
    
    return 0;
}
