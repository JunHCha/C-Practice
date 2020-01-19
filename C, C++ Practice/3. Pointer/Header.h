//
//  Header.h
//  15강 ~ 19강
//
//  Created by 차준형 on 17/01/2019.
//  Copyright © 2019 차준형. All rights reserved.
//
#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

#define double db

typedef struct {
    char studentID[20];
    char name[20];
    int grade;
    char major[30];
} Student;

void clearBuffer(void);
int add(int a, int b);
void myFunction(void);
void yourFunction(void);
void printFunctionPtr(void);
Student *createStudentInf(int num, bool isFile);
void studentPrint(Student *s);
void fileRead(Student *target);


#endif
