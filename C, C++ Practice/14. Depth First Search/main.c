//
//  main.c
//  34강 깊이 우선 탐색
//
//  Created by 차준형 on 27/02/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node {
    int index;
    struct Node* next;
} Node;

Node** a;

void addFront(Node* root, int idx) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = idx;
    node->next = root->next;
    root->next = node;
}

Node** a; //이중 포인터 == 2차원 배열로 선언하였기 때문에 그래프구조 처리 가능
Node* c;

void dfs(int x) {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
