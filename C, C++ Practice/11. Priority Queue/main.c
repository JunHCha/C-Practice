//
//  main.c
//  31강 우선순위 큐
//
//  Created by 차준형 on 18/02/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct {
    int heap[MAX_SIZE];
    int count;
} priorityQueue;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(priorityQueue* pq, int data) {
    if(pq->count >= MAX_SIZE) return;
    pq->heap[pq->count] = data;
    int now = pq->count;
    int parent = (now - 1)/2;
    while (now > 0 && pq->heap[parent] < pq->heap[now] ) {
        if (pq->heap[parent] < pq->heap[now]) {
            swap(&pq->heap[parent], &pq->heap[now]);
            now = parent;
            parent = (now - 1) / 2;
        }
    }
    pq->count++;
}

int pop(priorityQueue* pq) {
    if (pq->count <= 0) return -9999;
    int head = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;
    //하향식 힙 구성
    while (leftChild < pq->count) { // 종료 시점은 자식노드가 Max heap을 초과하는 인덱스를 갖기 전까지.
        // target, leftChild, rightChilde 세 값을 비교하는 알고리즘.
        if(pq->heap[target] < pq->heap[leftChild]) target = leftChild; //1. target과 leftchild 값을 비교한다.
        if(pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
        //2. leftchild의 인덱스를 target으로 받아와서 leftChild 값과 rightChild 값을 비교한다.
        if(target == now) break; // 위의 조건문들에서 target 값에 Child 값을 넣고 있으므로 조건문이 안걸린다면 당 조건문으로 들어오게 된다. 즉 target값이 제자리를 찾은 시점.
        else {
            swap(&pq->heap[target], &pq->heap[now]);
            now = target;
            leftChild = 2 * now + 1;
            rightChild = 2 * now + 2;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    priorityQueue pq;
    pq.count = 0;
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("index %d : ", i + 1);
        scanf("%d", &data);
        push(&pq, data);
    }
    for (int i = 0; i < n; i++) {
        int data = pop(&pq);
        printf("%d ", data);
    }
    return 0;
}
