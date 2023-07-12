#include <stdio.h>
#include "StudentManagerSystem.h"
#include "stdlib.h"

int main() {
    while (1) {
        Welcome();      //欢迎界面
        char ch;
        scanf(" %c", &ch);  // 在%c之前添加空格,必不可少的空格

        switch (ch) {
            case '1':
                InputStudent(); // 录入学生信息
                break;
            case '2':
                PrintStudent(); // 打印学生信息
                break;
            case '3':
                SaveStudent();  // 保存学生信息
                break;
            case '4':
                // 读取学生信息
                break;
            case '5':
                // 统计所有学生人数
                break;
            case '6':
                // 查找学生信息
                break;
            case '7':
                // 修改学生信息
                break;
            case '8':
                // 删除学生信息
                break;
            case '0':
                // 退出系统
                break;
        }
    }
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
    Node *pNewNode = malloc(sizeof(Node));        //创建新的节点
    pNewNode->next = NULL;

    //插入-----> 头插法、尾插法
    //头插法
    if (head == NULL) {
        head = pNewNode;
    } else {
        pNewNode->next = head;  //采用头插法，将新创建的节点加入到头节点前面
        head = pNewNode;         //将新创建的节点设置为头节点
    }

    printf("请输入学生姓名：\n");
    scanf("%s", pNewNode->student.name);     //不需要设置&符号，name是数组
    printf("请输入学生年龄：\n");
    scanf("%d", &pNewNode->student.age);     //设置&符号，name是数组
    printf("请输入学生学号：\n");
    scanf("%s", pNewNode->student.stuNum);
    printf("请输入学生成绩：\n");
    scanf("%d", &pNewNode->student.score);

    printf("学生信息录入成功.\n");
    //    system("pause");        //win暂停
    //    system("cls");          //win清屏
    system("clear");    //清屏
}

void PrintStudent() {
    system("clear");
    printf("*************************************\n");
    printf("*\t欢迎使用高校学生成绩管理系统v1.0\t*\n");
    printf("*************************************\n");
    printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\t*\n");

    //遍历链表  ----> 单链表
    Node *p = head;
    while (p != NULL) {
        printf("*\t%s\t\t*\t%s\t*\t%d\t\t*\t%d\t\t*\n", p->student.stuNum, p->student.name, p->student.age,
               p->student.score);
        p = p->next;
    }
    printf("*************************************\n");
//    system("pause");        //win暂停
//    system("cls");          //win清屏
    system("clear");        //mac清屏
}

void SaveStudent() {
    //打开文件
    FILE *fp = fopen("/Users/zechaowei/Documents/003-Project/008-C/StudentManagerSystem/data.csv", "w");

    if (fp == NULL){
        printf("文件打开失败.\n");
        return;
    }

    //遍历链表
    Node* p = head;
    while (p != NULL){
        fwrite(&p->student,1,sizeof(Student),fp);
        p = p->next;
    }

    //关闭文件
    fclose(fp);
    printf("\n数据保存成功.\n");

//    system("pause");          //win暂停
//    system("cls");            //win清屏
}