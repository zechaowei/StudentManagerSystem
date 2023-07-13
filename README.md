# StudentManagerSystem
学生成绩管理系统（Student Grade Management System）是一个使用 C 语言开发的课程设计项目，旨在提供一个全面的学生成绩管理解决方案。该系统支持以下核心功能：

1. 学生信息录入：管理员可以通过系统录入学生的基本信息，包括学号、姓名、班级等，以建立学生信息数据库。

2. 成绩录入与打印：管理员可以录入学生的各科成绩，并支持将学生成绩打印成绩单或成绩报告，以便于查阅和分发给学生和家长。

3. 信息保存与读取：系统支持将学生信息和成绩数据保存到文件中，以便在需要时进行读取和导入，确保数据的长期保存和可持续使用。

4. 学生信息统计：系统能够对学生人数进行统计，并提供相应的报告或摘要信息，包括总学生人数、男女比例等，以便于教务管理和决策。

5. 学生信息查找：管理员可以通过学号或姓名等关键字进行学生信息的快速查找，便于定位和管理特定学生的信息。

6. 学生信息修改与删除：管理员可以对学生的信息进行修改和更新，包括姓名、班级等字段，也可以删除学生的信息，以实现数据的准确性和及时性。

7. 退出信息：系统提供清晰的退出选项，使管理员可以安全地退出系统，确保数据的完整性和安全性。

学生成绩管理系统的设计旨在简化学生信息和成绩管理的流程，提供高效、可靠的数据管理和操作功能。通过支持录入、打印、保存、读取、统计学生人数、查找、修改、删除学生信息和退出信息等功能，该系统能够满足学校、教育机构或教师对学生成绩管理的需求，提升管理效率和数据可视化分析能力。


# 开发日志
程序启动画面
```c
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
```
程序运行后画面展示
<img src="https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/image-20230710195301134.png" alt="image-20230710195301134" style="zoom:50%;" />

完成基本的选择功能
```c
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
```
利用while无限循环，以实现在此系统中不断的执行，知道选择退出程序，即输入`0`





## 录入学生信息

```c
void InputStudent() {
    Node* pNewNode =  malloc(sizeof (Node));        //创建新的节点
    pNewNode->next = NULL;

    //插入-----> 头插法、尾插法
    //头插法
    if (head == NULL){
        head = pNewNode;
    } else{
        pNewNode->next = head;  //采用头插法，将新创建的节点加入到头节点前面
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
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E5%BD%95%E5%85%A5%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF%E6%A8%A1%E5%9D%97.gif)

到目前为止，这个程序看起来好像没有什么问题，但是当我们执行完录入学生信息，按下回车键以后，就出现了第一个bug 了，该程序会执行两次 welcome() 函数😲😲😲。那么是什么导致的这个问题呢？这个问题的原因是scanf("%c", &ch);会读取上一个输入中留在输入缓冲区的换行符（\n）。

要解决这个问题，你可以在 scanf 语句中%c之前添加一个空格。这个空格告诉scanf跳过任何空白字符，包括换行符。所以，在这里需要对 main 函数修改，只需要修改 scanf 函数即可；

```c
scanf(" %c", &ch);  // 在%c之前添加空格,必不可少的空格
```

测试案例

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E6%89%93%E5%8D%B0%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF%E6%A8%A1%E5%9D%97.gif)

打印出来格式可能不是那么的美观，大家可以自己调整成自己喜欢的模样。



## 打印学生信息

打印学生信息函数

```c
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
```

![](https://raw.githubusercontent.com/zechaowei/photos_blog/main/img/%E6%89%93%E5%8D%B0%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF%E6%A8%A1%E5%9D%97.gif)

> ⚠️：在输入姓名或者学号的时候，尽可能的短，不是程序会出现bug，而是最后打印出来的效果不是很美观。大家可以自己尝试一下，这里不做过多演示操作了。

## 保存学生信息

保存学生信息函数

```c
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
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E4%BF%9D%E5%AD%98%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF.gif)







## 读取学生信息

```c
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
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E8%AF%BB%E5%8F%96%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF.gif)

首先，我们正常演示，录入学生信息（这里录入两个学生信息），然后选择打印学生信息，结果显示出学生信息录入，最后选择保存学生信息，将学生信息写入到文件中（我这里写入到`data.csv`中）。然后重新运行程序，选择 4 读取学生信息，然后按 2 打印学生信息，此时就可以看见学生信息了；如果重新运行程序后，没有选择读取学生信息，直接打印学生信息，不会展示任何结果。（`gif`动画中已经全部演示过了，仔细观看）









## 统计所有学生人数

```c
int CountStudent(){
    int count = 0; //学生总数

    //遍历
    Node *p = head;
    while (p != NULL){
        count++;
        p = p->next;
    }

    return count;
}
```

设计思路：使用单链表保存学生信息，因此每一个节点代表一个学生，只需要统计有多少个节点即可。前面已经经常执行遍历节点操作，因此只需要在遍历过程中增加一个 `count 计数器`统计节点数即可解决这个问题。

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E7%BB%9F%E8%AE%A1%E5%AD%A6%E7%94%9F%E6%80%BB%E6%95%B0.gif)

输入两个测试案例，并且执行了前面的功能，功能正常；然后点击保存学习信息，这样在结束程序后，再次运行程序后，读取学生数据后，即可再次统计学生，如果没有点击读取学生信息，则统计的学生的人数为 0。（以上描述均已演示，自行观看）





## 查找学生信息

```c
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
```

利用学生的姓名和学号共同查找学生的信息，只有输入的学号和姓名同时匹配才会输出结果，否则显示查无此人。

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E6%9F%A5%E6%89%BE%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF.gif)

该段C语言程序实现了一项学生信息查询功能。当用户输入学生的学号和姓名时，程序会读取已保存的学生信息文件，并与输入的学号和姓名进行匹配。如果找到匹配的学生信息，程序会输出该学生的学号、姓名、年龄和成绩。如果输入的学号和姓名与任何保存的学生信息不匹配，则程序会输出"查无此人"。（为了方便演示，此处使用了之前已经保存了的学生信息，此处跳过学生录入信息）



## 修改学生信息







## 删除学生信息







## 退出系统
