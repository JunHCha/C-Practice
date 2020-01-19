//
//  main.c
//  22강 스택
//
//  Created by 차준형 on 29/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define INF 99999

int stack[SIZE];
int idx = -1;

void push(int data) {
    if(idx == SIZE - 1) {
        printf("stack overflowed. \n");
        return;
    }
    stack[++idx] = data;
}

int pop() {
    if(idx == -1) {
        printf("stack underflowed.\n");
        return -INF;
    }
    return stack[idx--];
}

void show() {
    printf("Top of the stack------\n");
    int i = 0;
    while(i <= idx) {
        printf("%d\n", stack[i++]);
    }
    printf("Bottom of the stack------\n\n");
}
//Stack using array

typedef struct Node {
    int data;
    struct Node* next;
} Node ;

typedef struct {
    Node *top;
} Stack;

void s_push(Stack *stack, int dt) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = dt;
    node->next = stack->top;
    stack->top = node;
}

int s_pop(Stack* stack) {
    if(stack->top == NULL) {
        printf("Stack underflowed.\n");
        return -INF;
    }
    Node* cur = stack->top;
    int dt = cur->data;
    stack->top = cur->next;
    return dt;
}

void s_show(Stack* stack) {
    Node* cur = stack->top;
    printf("Top of the stack------\n");
    while(cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("Bottom of the stack------\n");
}

void s_freestack(Stack* stack){
    Node* cur = stack->top;
    while(cur != NULL) {
        free(cur);
        cur = cur->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
  
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    push(5);
    push(6);
    pop();
    show();
    //Stack using array
    
    Stack s;
    s.top = NULL;
    s_push(&s, 1);
    s_push(&s, 2);
    s_push(&s, 3);
    s_push(&s, 4);
    s_push(&s, 5);
    s_push(&s, 6);
    s_pop(&s);
    s_push(&s, 7);
    s_show(&s);
    s_freestack(&s);
    
    return 0;
}
