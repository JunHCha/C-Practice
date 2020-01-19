//
//  main.c
//  33장 그래프의 개념과 구현
//
//  Created by 차준형 on 25/02/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int a[1001][1001];
int n_vertex, n_edge;

typedef struct Node{
    int index;
    int distance;
    struct Node* next;
} Node;

void addFront(Node* root, int idx, int dist) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = idx;
    node->distance = dist;
    node->next = root->next;
    root->next = node;
}

void showAll(Node* root) {
    Node* cur = root->next;
    while (cur != NULL) {
        printf("%d(distance : %d)", cur->index, cur->distance);
        cur = cur->next;
    }
}

void undirectedUnweightedGraph() {
    printf("Undirected Unweighted Graph : \n");
    scanf("%d %d", &n_vertex, &n_edge);
    for (int i = 1; i <= n_edge; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n_vertex; i++) {
        for (int j = 1; j <= n_vertex; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
};

void directedWeightedGraph() {
    printf("Directed Weighted Graph : \n");
    scanf("%d %d", &n_vertex, &n_edge);
    Node** b = (Node**)malloc(sizeof(Node*) * (n_vertex + 1));
    for (int i = 1; i <= n_vertex ; i++) {
        b[i] = (Node*)malloc(sizeof(Node));
        b[i]->next = NULL;
    }
    for (int i = 1; i <= n_edge; i++) {
        int x, y, distance;
        scanf("%d %d %d", &x, &y, &distance);
        addFront(b[x], y, distance);
    }
    for (int i = 1; i <= n_vertex; i++) {
        printf("vertex%d : ", i);
        showAll(b[i]);
        printf("\n");
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    undirectedUnweightedGraph();
    directedWeightedGraph();
    return 0;
}
