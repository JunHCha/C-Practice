//
//  main.c
//  25강 ~ 28강 정렬
//
//  Created by 차준형 on 30/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

#define SIZE 100

int a[SIZE];

void a_reset() {
    for (int i = 0; i < SIZE; i++) {
        a[i] = 0;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Selection sort
int selectionSort() {
    printf("Selection Sort.\n");
    int n, min, index;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
        min = INT_MAX;
        for (int j = i; j < n; j++) {
            if (min > a[j]) {
                min = a[j];
                index = j;
            }
        }
        swap(&a[index], &a[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    return 0;
}
//Selection sort

//Insertion sort
int insertionSort() {
    printf("Insertion Sort.\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        while (j >= 0 && a[j] > a[j + 1]) {
            swap(&a[j], &a[j + 1]);
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    return 0;
}
//Insertion sort

//Quicksort
void sort(int start, int end) {
    if (start >= end) return;
    int pivot = start, i = start + 1, j = end;
    while (i <= j) {
        while (i <= end && a[i] >= a[pivot]) i++;
        while (j > start && a[j] < a[pivot]) j--;
        if (i >= j) swap(&a[start], &a[j]);
        else swap(&a[i], &a[j]);
    }
    sort(start, j - 1);
    sort(j + 1, end);
}
int quickSort() {
    printf("Quicksort.\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n\n");
    return 0;
}
//Quicksort

//Counting Sort
int countingSort() {
    printf("Counting Sort.\n");
    int n, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if(m >= 100) while (m >= 100) { printf("Too large. insert smaller integer\n"); scanf("%d", &m); }
        else scanf("%d", &m);
        a[m]++;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < a[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    return 0;
}
//Counting Sort

//Radix Sort
void r_sort(int* a, int n) {
    int res[SIZE], max_value = 0;
    int exp = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_value) max_value = a[i];
    }
    while (max_value / exp > 1) {
        int temp[10] = {0};
        for (int i = 0; i < n; i++) temp[a[i] / exp % 10] ++;
        for (int i = 1; i < 10; i++) temp[i] += temp[i - 1];
        for (int i = n - 1; i >= 0; i--) res[--temp[a[i] / exp % 10]] = a[i];
        for (int i = 0; i < n; i++) a[i] = res[i];
        exp *= 10;
    }
}

int radixSort() {
    printf("Radix Sort.\n");
    int n, a[SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    r_sort(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
//Radix Sort

int main(int argc, const char * argv[]) {
    selectionSort();
    a_reset();
    insertionSort();
    a_reset();
    quickSort();
    a_reset();
    countingSort();
    a_reset();
    radixSort();
    a_reset();
    return 0;
}
