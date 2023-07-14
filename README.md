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
程序运行画面
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

<img src="https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/image-20230710195301134.png" alt="image-20230710195301134" style="zoom:50%;" />

循环执行主菜单操作：使用 `while` 循环可以实现在此系统中的持续执行，直到用户选择退出程序，即输入 `0`。这样的循环结构能够保持程序的运行，直到指定条件满足。
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

到目前为止，这个程序似乎没有太多问题，但是在执行完录入学生信息后，按下回车键后会出现一个令人意外的 bug，即程序会执行两次 `welcome()` 函数😲😲😲。这个问题的原因是 `scanf("%c", &ch);` 会读取之前输入中保留在输入缓冲区中的换行符（`\n`）。

要解决这个问题，您可以在 `scanf` 语句中 `%c` 之前添加一个空格。这个空格告诉 `scanf` 跳过任何空白字符，包括换行符。因此，在 `main` 函数中只需要修改 `scanf` 语句即可。

```c
scanf(" %c", &ch);  // 在%c之前添加空格,必不可少的空格
```

测试案例

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E6%89%93%E5%8D%B0%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF%E6%A8%A1%E5%9D%97.gif)

打印结果的美观程度可能会因个人喜好而有所不同，因此可以根据个人偏好进行格式调整，以获得更满意的打印效果。每个人都可以根据自己的审美标准进行样式定制，使输出结果更符合个人喜好。这样，每个人都可以得到自己喜欢的打印样式。



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

> ⚠️：在输入姓名或学号时，尽量使用简短的输入，这样可以确保最终打印出的结果更美观。虽然不会导致程序出现错误或缺陷，但较长的输入可能会影响最终打印结果的美观程度。建议大家自行尝试并体验，本文中不再进行详细演示。

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

首先，我们进行正常的演示，录入学生信息（这里录入两个学生信息）。然后选择打印学生信息，结果会显示出已录入的学生信息。最后，选择保存学生信息，将学生信息写入到文件中（在这个例子中，我们将其写入到名为 `data.csv` 的文件中）。

接着，重新运行程序，并选择选项 4 以读取学生信息。然后按 2 以打印学生信息，这样就可以看到学生信息被成功读取并展示出来。但是如果重新运行程序后，没有选择读取学生信息而直接选择打印学生信息，则不会显示任何结果。

请注意，以上过程已在动画中进行了演示，您可以仔细观看动画以获得更详细的理解。









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

设计思路：使用单链表保存学生信息，其中每个节点代表一个学生。为了统计学生数量，我们可以在遍历节点的过程中增加一个 `count` 计数器。每遍历一个节点，计数器就加一，最终得到的计数器的值就是节点的数量。这样，我们就可以解决统计学生数量的问题。

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

该段C语言程序实现了学生信息查询功能。当用户输入学生的学号和姓名时，程序会读取已保存的学生信息文件，并与输入的学号和姓名进行匹配。如果找到匹配的学生信息，程序会输出该学生的学号、姓名、年龄和成绩。如果输入的学号和姓名与任何保存的学生信息不匹配，则程序会输出"查无此人"。请注意，为了方便演示，此处假设已经保存了学生信息，因此跳过了学生录入信息的步骤。

```c
case '6':   // 查找学生信息		实现选择查询学生信息时的逻辑顺序
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
```





## 修改学生信息

设计思路：通过检索学生的学号来修改信息。如果输入的学号 `nStuNum` 存在，则进行修改；如果不存在，则输出没有找到该学生的信息。通过遍历单链表，检索输入的学号是否与单链表中存储的学号相匹配。如果存在匹配项，则输入需要修改的学生的姓名、年龄和成绩，即可成功进行修改。

```c
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
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E4%BF%AE%E6%94%B9%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF.gif)





## 删除学生信息







## 退出系统
