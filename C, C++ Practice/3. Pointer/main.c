//
//  main.c
//  15강 ~ 19강
//
//  Created by 차준형 on 17/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//


#include "Header.h"

int main(int argc, const char * argv[]) {
    
    printFunctionPtr();
    printAdd();

    Student *s = (Student*)malloc(sizeof(Student)*4);
    
    FILE *fp = fopen("File.txt", "r");
    int num;
    char c[20];
    if(fp == 0) {
        perror("File.txt");
        exit(1);
    }
    fscanf(fp, "%d", &num); //in-readable ㅠㅠ
    fscanf(fp, "%s", c);
        
    
    printf("The first line : %d\n", num);
    printf("%s\n", c);
    
    
    fclose(fp);
    
    return 0;

    
}

