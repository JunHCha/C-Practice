//
//  main.c
//  11강~ 문자열
//
//  Created by 차준형 on 10/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main(void) {
    
    char str[100];
    gets(str);
    printf("%s : size is %li\n", str, strlen(str));
    
    char str_2[100];
    gets(str_2);
    printf("%s : size is %li\n\n", str_2, strlen(str_2));
    
    if(strcmp(str, str_2) == -1 )
        printf("'%s' is former order than '%s'\n", str, str_2);
    else
        printf("'%s' is former order than '%s'\n", str_2, str);
    
    printf("str + str_2 = %s\n\n", strcat(str, str_2));
    
    int a[5] = {1, 2, 3, 4, 5 };
    int *ptr = a;
    
    printf("%d\n", *(ptr++)); // 1 , ptr = &a[1]
    printf("%d\n", 1);
    printf("%d\n", *(++ptr)); // ptr = &a[2]
    printf("%d\n", 3);
    printf("%d\n", *(ptr+2)); // ptr = &a[4]
    printf("%d\n", 5);
    
    int b[5][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int (*_ptr)[2] = &b[3];
    printf("\n");
    for(int i = 0; i < 20; i++ ) {
        for(int j = 0; j < 2; j++) {
            printf("%d\n", _ptr[i][j]);
        }
        printf("\n");
    }
    
    
    
    return 0;
}

