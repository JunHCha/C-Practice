//
//  function.c
//  15강 ~ 19강
//
//  Created by 차준형 on 17/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//

#include "Header.h"

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int add(int a, int b) {
    return a + b;
}

void myFunction(void) {
    printf("It's my function.\n");
}

void yourFunction(void) {
    printf("It's your function.\n");
}

void printFunctionPtr(void) {
    void(*fp)(void) = myFunction;
    fp();
    fp = yourFunction;
    fp();
}

void printAdd(void) {
    int(*addPtr)(int, int) = add;
    printf("Sum of 6 and 7 is %d\n", addPtr(6, 7));
}

void fileRead(Student *target) {
    int num;
    FILE *fp = fopen("File.txt", "w");
    if(fp == 0 ) {
        perror("File.txt");
        exit(1);
    }
    fscanf(fp, "%d", &num);
    
    for( int i = 0; i < num; i++) {
        fscanf(fp, "%s", ((target + i)->studentID));
        fscanf(fp, "%s", ((target + i)->name));
        fscanf(fp, "%d", &((target + i)->grade));
        fscanf(fp, "%s", ((target + i)->major));
    }
    fclose(fp);
}

int tempNum;

Student *createStudentInf(int num, bool isFile) {
    if( isFile == false ) {
        tempNum = num;
        Student *s = malloc(sizeof(Student)*num);
        for( int i = 0; i < num; i++ ) {
            strcpy((s + i)->studentID, "temp student ID");
            strcpy((s + i)->name, "temp name");
            (s + i)->grade = 00;
            strcpy((s + i)->major, "temp major");
        }
        return s;
    }
    else {
        Student *s = malloc(sizeof(Student)*num);
        fileRead(s);
        return s;
    }
}

void studentPrint(Student *s) {
    for( int i = 0; i < tempNum; i++ ) {
        printf("Student ID is %s\n", (s + i)->studentID);
        printf("The name is %s\n", (s + i)->name);
        printf("The grade is %d\n", (s + i)->grade);
        printf("The major is %s\n\n", (s + i)->major);
    }
    free(s);
}
