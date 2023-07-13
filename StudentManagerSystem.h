//
// Created by zechaowei on 2023/7/10.
//

#ifndef STUDENTMANAGERSYSTEM_TEST_H
#define STUDENTMANAGERSYSTEM_TEST_H

#endif //STUDENTMANAGERSYSTEM_TEST_H

#include "stdlib.h"

//定义一个学生
typedef struct _Student{
    char name[20];      //姓名
    int age;            //年龄
    char stuNum[20];    //学号(也可以设置为int类型)
    int score;          //成绩
}Student;


typedef struct _Node{
    Student student;    //学生
    struct _Node* next;//指向下一个节点的指针
} Node;

Node *head = NULL;   //定义头节点

void Welcome();             //欢迎界面
void InputStudent();        //输入学生信息
void PrintStudent();        //打印学生信息
void SaveStudent();         //保存学生信息
void ReadStudent();         //读取学生信息
int CountStudent();         //统计所有学生人数
Node* FindStudent();        //查找学生