//
//  main.c
//  30강 이진 트리
//
//  Created by 차준형 on 14/02/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* initNode(int dt, Node* l_Child, Node* r_Child) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = dt;
    node->leftChild = l_Child;
    node->rightChild = r_Child;
    return node;
}

void pr_order(Node* node) {
    if (node) {
        printf("%d ", node->data);
        pr_order(node->leftChild);
        pr_order(node->rightChild);
    }
}

void inorder(Node* node) {
    if (node) {
        inorder(node->leftChild);
        printf("%d ", node->data);
        inorder(node->rightChild);
    }
}

void pst_order(Node* node) {
    if (node) {
        pst_order(node->leftChild);
        pst_order(node->rightChild);
        printf("%d ", node->data);
    }
}

int main(int argc, const char * argv[]) {
    Node* n7 = initNode(7, NULL, NULL);
    Node* n6 = initNode(6, NULL, NULL);
    Node* n5 = initNode(5, NULL, NULL);
    Node* n4 = initNode(4, NULL, NULL);
    Node* n3 = initNode(3, n6, n7);
    Node* n2 = initNode(2, n4, n5);
    Node* n1 = initNode(1, n2, n3);
    pr_order(n1);
    inorder(n1);
    pst_order(n1);
    return 0;
}
