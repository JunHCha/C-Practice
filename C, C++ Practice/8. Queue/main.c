//
//  main.c
//  24강 큐
//
//  Created by 차준형 on 29/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define INF 999999
#define size 1000

int queue[size];
int front, rear = 0;

void push(int data) {
    if (rear >= size) {
        printf("Stack overflowed.");
        return;
    }
    queue[rear++] = data;
}

int pop() {
    if (front == rear) {
        printf("Stack underflowed.");
        return -INF;
    }
    return queue[front++];
}

void show() {
    printf("-----Front-----\n");
    for (int i = front; i < rear; i++) {
        printf("%d\n", queue[i]);
    }
    printf("-----Rear-----\n\n");
}
// Queue using array

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

void q_push(Queue *queue, int dt) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = dt;
    node->next = NULL;
    if (queue->count == 0) {
        queue->front = node;
    }
    else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int q_pop(Queue *queue) {
    if (queue->front == NULL) {
        printf("Stack Underflowed.\n");
        return -INF;
    }
    Node* node = queue->front;
    int dt = node->data;
    queue->front = node->next;
    free(node);
    queue->count--;
    return dt;
}

void q_show(Queue *queue) {
    Node* cur = queue->front;
    printf("------Front------\n");
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("------Rear------\n\n");
}

void q_free(Queue *queue) {
    Node* cur = queue->front;
    while (cur != NULL) {
        free(cur);
        cur = cur->next;
    }
}

int main(int argc, const char * argv[]) {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    show();
    pop();
    pop();
    show();
    //Queue using array
    
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    queue.count = 0;
    q_push(&queue, 1);
    q_push(&queue, 2);
    q_push(&queue, 3);
    q_push(&queue, 4);
    q_push(&queue, 5);
    q_push(&queue, 6);
    q_show(&queue);
    q_pop(&queue);
    q_pop(&queue);
    q_show(&queue);
    q_free(&queue);
    //Queue using linked list
    return 0;
}
