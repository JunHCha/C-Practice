//
//  main.c
//  32강 순차탐색 이진탐색
//
//  Created by 차준형 on 18/02/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100
#define MAX_SIZE 1000

char **array;
int n1, n2 = 0;
int founded;
int a[MAX_SIZE];

void linearSearch() {
    founded = 0;
    char* word = (char*)malloc(sizeof(char)*LENGTH);
    scanf("%d %s", &n1, word);
    array = (char**)malloc(sizeof(char*) * n1);
    for (int i = 0; i < n1; i++) {
        array[i] = (char*)malloc(sizeof(char) * LENGTH);
        scanf("%s", array[i]);
    }
    for (int i = 0; i < n1; i++) {
        if (!strcmp(word, array[i])) {
            printf("%d 번째 원소입니다.\n\n", i + 1);
            founded = 1;
        }
    }
    if(!founded) printf("원소가 없습니다. \n\n");
}

int search(int start, int end, int data) {
    int mid = (start + end) / 2;
    if (start > end) return -9999;
    else if (a[mid] == data) return mid;
    else if (a[mid] > data) return search(start, mid - 1, data);
    else return search(mid + 1, end, data);
}

void binarySearch() {
    int data;
    scanf("%d %d", &n2, &data);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d 번째 원소입니다.\n\n", search(0, n2 - 1, data) + 1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    linearSearch();
    binarySearch();
    return 0;
}
