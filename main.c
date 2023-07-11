#include <stdio.h>
#include "StudentManagerSystem.h"
#include "stdlib.h"

int main() {
    while (1) {
        Welcome();      //欢迎界面
        char ch;
        scanf("%c", &ch);
        getchar(); // 清空输入缓冲区中的换行符


        switch (ch) {
            case '1'://录入学生信息
                InputStudent();
                break;
            case '2'://打印学生信息
                break;
            case '3'://保存学生信息
                break;
            case '4'://读取学生信息
                break;
            case '5'://统计所有学生人数
                break;
            case '6'://查找学生信息
                break;
            case '7'://修改学生信息
                break;
            case '8'://删除学生信息
                break;
            case '0'://退出系统
                break;
        }
    }
}


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Welcome() {
    printf("*************************************\n");
    printf("*\t欢迎使用高校学生成绩管理系统v1.0\t*\n");
    printf("*************************************\n");
    printf("*\t\t\t1.录入学生信息\t\t\t*\n");
    printf("*\t\t\t2.打印学生信息\t\t\t*\n");
    printf("*\t\t\t3.保存学生信息\t\t\t*\n");
    printf("*\t\t\t4.读取学生信息\t\t\t*\n");
    printf("*\t\t\t5.统计所有学生人数\t\t*\n");
    printf("*\t\t\t6.查找学生信息\t\t\t*\n");
    printf("*\t\t\t7.修改学生信息\t\t\t*\n");
    printf("*\t\t\t8.删除学生信息\t\t\t*\n");
    printf("*\t\t\t0.退出系统\t\t\t\t*\n");
    printf("*************************************\n");
}


void InputStudent() {
    Node* pNewNode =  malloc(sizeof (Node));        //创建新的节点
    pNewNode->pNext = NULL;

    //插入-----> 头插法、尾插法
    //头插法
    if (head == NULL){
        head = pNewNode;
    } else{
        pNewNode->pNext = head;  //采用头插法，将新创建的节点加入到头节点前面
        head = pNewNode;         //将新创建的节点设置为头节点
    }

    printf("请输入学生姓名：\n");
    scanf("%s",pNewNode->student.name);     //不需要设置&符号，name是数组
    printf("请输入学生年龄：\n");
    scanf("%d",&pNewNode->student.age);     //设置&符号，name是数组
    printf("请输入学生学号：\n");
    scanf("%s",pNewNode->student.stuNum);
    printf("请输入学生成绩：\n");
    scanf("%d",&pNewNode->student.score);

    printf("学生信息录入成功.\n");
    system("clear");    //清屏
}