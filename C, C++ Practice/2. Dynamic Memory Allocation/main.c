//
//  main.c
//  14강 : Dynamic Memory Allocation
//
//  Created by 차준형 on 11/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _3by3UsingMatrix(void);
void _3by3UsingDMA(void);
void N_by_N_UsingDMA(int* size_mtx);
void _3DimensionDMA(int* size_mtx);

int main(int argc, const char * argv[]) {
    // insert code here...
    int *a = malloc(sizeof(int));  // Return data type 'malloc()' is pointer(address). And its data that is pointed to don't have to be zeroed out.
    printf("%p\n", a);
    printf("%d\n", *a);
    free(a);
    /*
    freeing memory doesn't mean the memory that has been pointed have to be zeored out(or NULL).
    The memory can keep storing old values until it reused.(like, re-allocating memory or else)
    */
    
    *a = 19;
    //Although you have freed the memory, it can be writed, but actually it is no longer owned. So don't have to try this.
    printf("%p\n", a);
    printf("%d\n", *a);
    
    //mesmset() : 특정한 범위의 메모리를 일괄적으로 하나의 값으로 처리
    char *str = malloc(100);
    memset(str, 'A', 100); // asci(65) = 'A'
    //content check
    for( int i = 0; i < 100; i++ ) {
        printf("%c ", str[i]);
    }
    printf("\n");
    
    _3by3UsingMatrix();
    _3by3UsingDMA();
    
    printf("insert size of matrix : ");
    int num;
    scanf("%d", &num);
    N_by_N_UsingDMA(&num);
    
    
    
    return 0;
}


void _3by3UsingMatrix(void) {
    int m[3][3];
    for( int i = 0; i < 3; i++ ) {
        for( int j = 0; j < 3; j++ ) {
            m[i][j] = i * 3 + j;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void _3by3UsingDMA(void) {
    int **p = (int**)malloc(sizeof(int*)*3);
    for(int i = 0; i < 3; i++ ) {
        *(p + i) = (int*)malloc(sizeof(int*)*3);
    }
    //Memory allocattion using DMA
    
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 3; j++ ) {
            *(*(p + i) + j) = i * 3 + j;
        }
    }
    //initiate elements
    
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 3; j++ ) {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    //print
    
    free(p);
}

void N_by_N_UsingDMA(int* size_mtx) {
    int **p = (int **)malloc(sizeof(int*) * *size_mtx);
    for(int i = 0; i < *size_mtx; i++)
        *(p + i) = (int*)malloc(sizeof(int*) * *size_mtx);
    
    for(int i = 0; i < *size_mtx; i++)
        for(int j = 0; j < *size_mtx; j++)
            *(*(p + i) + j) = i * *size_mtx + j;
    
    for(int i = 0; i < *size_mtx; i++) {
        for(int j = 0; j < *size_mtx; j++) {
            printf("%d  ", *(*(p + i) + j));
        }
        printf("\n");
    }
    
    free(p);
}

void _3dimensionDMA(int* size_mtx) {
    int **p = (int**)malloc(sizeof(int*) * 2 * *size_mtx);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < *size_mtx; j++) {
            *(p + 2 * j + i ) = (int*)malloc(sizeof(int) * *size_mtx);
        }
    }
}
