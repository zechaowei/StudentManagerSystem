#include <stdio.h>
#include "StudentManagerSystem.h"
#include <stdlib.h>
#include <string.h>

int main() {
    while (1) {
        Welcome();      //欢迎界面
        char ch;
        scanf(" %c", &ch);  // 在%c之前添加空格,必不可少的空格

        switch (ch) {
            case '1':   // 录入学生信息
                InputStudent();
                break;
            case '2':   // 打印学生信息
                PrintStudent();
                break;
            case '3':   // 保存学生信息
                SaveStudent();
                break;
            case '4':   // 读取学生信息
                ReadStudent();
                break;
            case '5':   // 统计所有学生人数
                printf("学生总数为：%d\n", CountStudent());
                system("clear");        //mac清屏
//                system("pause");        //win暂停
//                system("cls");          //win清屏
                break;
            case '6':   // 查找学生信息
            {
                Node *p = FindStudent();
                if (p != NULL) {
                    printf("学号：%s\t姓名：%s\t年龄：%d\t成绩：%d\t\n", p->student.stuNum, p->student.name, p->student.age,
                           p->student.score);
                } else {
                    printf("查无此人！\n");
                }
                break;
            }
            case '7':   // 修改学生信息
                ModifyStudent();
                break;
            case '8':   // 删除学生信息
                DeleteStudent();
                break;
            case '0':   // 退出系统
                sayGoodbye();
                exit(0);
            default:
                printf("您的输入有无，请重新输入.\n");
//                system("pause");        //win暂停
//                system("cls");          //win清屏
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

    if (fp == NULL) {
        printf("文件打开失败.\n");
        return;
    }

    //遍历链表
    Node *p = head;
    while (p != NULL) {
        fwrite(&p->student, 1, sizeof(Student), fp);
        p = p->next;
    }

    //关闭文件
    fclose(fp);
    printf("\n数据保存成功.\n");

//    system("pause");          //win暂停
//    system("cls");            //win清屏
}

//读取学生信息
void ReadStudent() {
    //打开文件
    FILE *fp = fopen("/Users/zechaowei/Documents/003-Project/008-C/StudentManagerSystem/data.csv", "r");
    if (fp == NULL) {
        printf("文件打开失败.\n");
        return;
    }

    Student stu;
    //读文件
    while (fread(&stu, 1, sizeof(Student), fp)) {
        //创建一个新的节点
        Node *pNewNode = (Node *) malloc(sizeof(Node));


        pNewNode->next = NULL;

        memcpy(pNewNode, &stu, sizeof(Student));

        //头插法
        if (head == NULL) {
            head = pNewNode;
        } else {
            pNewNode->next = head;
            head = pNewNode;
        }
    }
    //关闭文件
    fclose(fp);
    //    system("pause");          //win暂停
    //    system("cls");            //win清屏
    printf("加载数据成功.\n");
}


int CountStudent() {
    int count = 0; //学生总数

    //遍历
    Node *p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

Node *FindStudent() {
    char nStuNum[20];
    char nStuName[20];
    printf("请输入需要查找的学生的学号:\n");
    scanf("%s", nStuNum);
    printf("请输入需要查找的学生的姓名:\n");
    scanf("%s", nStuName);

    Node *p = head;
    while (p != NULL) {
        if (0 == strcmp(p->student.name, nStuName) && 0 == strcmp(p->student.stuNum, nStuNum)) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

void ModifyStudent() {
    char nStuNum[20];
    printf("请输入需要修改的学生信息的学号：\n");
    scanf("%s", nStuNum);

    Node *p = head;
    while (p != NULL) {
        if (0 == strcmp(p->student.stuNum, nStuNum)) {
            printf("请输入需要修改的学生的姓名 年龄 成绩：\n");
            scanf("%s %d %d", p->student.name, &p->student.age, &p->student.score);
            printf("修改成功.\n");
            break;
        }
        p = p->next;
    }

    if (p == NULL)
        printf("没有找到该学生信息.\n");
}

void DeleteStudent() {
    char nStuNum[20];
    printf("请输入要删除的学生的学号:\n");
    scanf("%s", nStuNum);

    Node *p1, *p2;

    //判断是否为头节点
    if (0 == strcmp(head->student.stuNum, nStuNum)) {
        p1 = head;          //临时存放节点
        head = head->next;
        free(p1);
        printf("学生信息删除成功.\n");
//        system("pause");        //win暂停
//        system("cls");          //清屏
        return;
    }

    //不是头节点
    Node *p = head;
    while (p->next != NULL) {
        if (0 == strcmp(p->next->student.stuNum, nStuNum)) {
            p2 = p->next;
            p->next = p->next->next;
            free(p2);
            printf("学生信息删除成功.\n");
//        system("pause");        //win暂停
//        system("cls");          //清屏
            return;
        }
        p = p->next;

        if (p->next == NULL) {
            break;
        }
    }

    if (p->next == NULL) {
        printf("没有找到该学生.\n");
    }
}

void sayGoodbye() {
    printf("Goodbye!\n");
    printf("   ____        _\n");
    printf("  / __ )____  (_)___  ____  _____\n");
    printf(" / __  / __ \\/ / __ \\/ __ \\/ ___/\n");
    printf("/ /_/ / /_/ / / /_/ / /_/ (__  ) \n");
    printf("\\____/\\____/_/\\____/\\____/____/  \n");
}