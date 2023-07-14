# StudentManagerSystem
学生成绩管理系统（Student Grade Management System）是一个使用 C 语言开发的课程设计项目，旨在提供一个全面的学生成绩管理解决方案。该系统支持以下核心功能：

1. 学生信息录入：管理员可以通过系统录入学生的基本信息，包括学号、姓名、年龄和成绩。

2. 打印学生信息：管理员可以录入学生的成绩，并支持将学生成绩打印成绩单，以便于查阅和分发给学生和家长。

3. 信息保存与读取：系统支持将学生信息和成绩数据保存到文件中，以便在需要时进行读取和导入，确保数据的长期保存和可持续使用。

4. 学生信息统计：系统能够对学生人数进行统计，并提供相应的报告或摘要信息，包括总学生人数。

5. 学生信息查找：管理员可以通过学号或姓名等关键字进行学生信息的快速查找，便于定位和管理特定学生的信息。

6. 学生信息修改与删除：管理员可以对学生的信息进行修改和更新，包括姓名、年龄等字段，也可以删除学生的信息，以实现数据的准确性和及时性。

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

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E7%BB%9F%E8%AE%A1%E5%AD%A6%E7%94%9F%E6%80%BB%E6%95%B0.gif)

设计思路：
1. 首先，定义一个整型变量 `count`，用于存储学生的总数。
2. 初始化 `count` 为 0，表示初始时学生总数为 0。
3. 使用指针 `p` 遍历链表，从头节点开始，每遍历一个节点，将 `count` 值加一。
4. 遍历结束后，`count` 的值即为链表中学生的总数。
5. 返回 `count`，表示学生总数。

以上是这段代码的设计思路，通过遍历链表并统计遍历的次数，可以得到链表中学生的总数。函数返回学生总数作为结果。



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

设计思路：
1. 首先，定义字符数组 `nStuNum` 和 `nStuName`，用于存储用户输入的学生学号和姓名。
2. 提示用户输入需要查找的学生的学号和姓名。
3. 使用指针 `p` 遍历链表，判断当前节点的学号和姓名与用户输入的学号和姓名是否匹配。如果匹配成功，说明找到了目标学生节点。
4. 在找到匹配的学生节点后，返回该节点的指针，表示学生信息查找成功。
5. 如果遍历结束仍未找到匹配的学生节点，则返回 `NULL`，表示未找到目标学生信息。

以上是这段代码的设计思路，通过遍历链表查找与用户输入的学号和姓名匹配的学生节点，以实现学生信息的查找功能。返回找到的节点指针或 `NULL` 来表示查找结果。



## 修改学生信息

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

设计思路：
1. 首先，定义一个字符数组 `nStuNum`，用于存储需要修改的学生的学号。
2. 提示用户输入需要修改的学生信息的学号。
3. 使用指针 `p` 遍历链表，判断当前节点的学号与目标学号是否匹配。如果匹配成功，说明找到了需要修改的学生节点。
4. 在找到匹配的学生节点后，提示用户输入需要修改的学生的姓名、年龄和成绩。
5. 使用 `scanf` 函数分别读取用户输入的姓名、年龄和成绩，并将对应的值保存到匹配的学生节点的相应字段中。
6. 输出 "修改成功" 提示信息，表示学生信息修改完成。
7. 如果遍历结束仍未找到匹配的学生节点，则输出 "没有找到该学生信息" 提示信息。

以上是这段代码的设计思路，通过遍历链表查找目标学生节点并修改其信息，以实现学生信息的修改操作。



## 删除学生信息

```c
void DeleteStudent() {
    char nStuNum[20];
    printf("请输入要删除的学生的学号:\n");
    scanf("%s", nStuNum);

    Node *p1, *p2;

    //判断是否为头节点
    if (0 == strcmp(head->student.stuNum,nStuNum)) {
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
        if (0 == strcmp(p->next->student.stuNum, nStuNum)){
            p2 = p->next;
            p->next = p->next->next;
            free(p2);
            printf("学生信息删除成功.\n");
//        system("pause");        //win暂停
//        system("cls");          //清屏
            return;
        }
        p = p->next;

        if (p->next == NULL){
            break;
        }
    }

    if (p->next ==NULL){
        printf("没有找到该学生.\n");
    }
}
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E5%88%A0%E9%99%A4%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF.gif)

1. 首先，定义一个字符数组 `nStuNum`，用于存储要删除的学生的学号。
2. 提示用户输入要删除的学生的学号。
3. 判断要删除的学生是否为头节点，即与链表头节点的学号进行比较。如果匹配成功，说明要删除的学生为头节点，将头节点指针指向下一个节点，并释放原头节点的内存，然后输出 "学生信息删除成功"。
4. 如果要删除的学生不是头节点，则使用指针 `p` 遍历链表，找到要删除的学生的前一个节点。在遍历过程中，依次比较当前节点的下一个节点的学号与目标学号是否匹配。如果匹配成功，将前一个节点的 `next` 指针指向目标学生的下一个节点，并释放目标学生节点的内存，然后输出 "学生信息删除成功"。
5. 如果遍历结束仍未找到匹配的学生，则输出 "没有找到该学生"。
6. 整个删除操作完成后，函数执行完毕。

注意：在代码中添加了 "学生信息删除成功" 的输出，以提供反馈给用户，让用户知道是否成功删除了学生信息。



## 退出系统

```c
void sayGoodbye() {
    printf("Goodbye!\n");
    printf("   ____        _\n");
    printf("  / __ )____  (_)___  ____  _____\n");
    printf(" / __  / __ \\/ / __ \\/ __ \\/ ___/\n");
    printf("/ /_/ / /_/ / / /_/ / /_/ (__  ) \n");
    printf("\\____/\\____/_/\\____/\\____/____/  \n");
}
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E9%80%80%E5%87%BA%E7%B3%BB%E7%BB%9F.gif)

这个函数的设计思路是以友好的方式向用户表示再见，并输出一个使用ASCII艺术字的图案。下面是这个函数的设计思路：

1. 首先，函数名为 `sayGoodbye`，用于表达向用户说再见的意图。
2. 在函数内部，使用 `printf` 函数输出 "Goodbye!"，表示再见的信息。
3. 接下来，使用 `printf` 函数打印一组ASCII艺术字，以形成一个图案。这个图案表示一个带有艺术风格的"再见"字样。
4. 函数的设计目的是通过输出文字和图案，以一种独特而友好的方式告别用户。

这样，当调用 `sayGoodbye` 函数时，它会输出再见信息和相应的ASCII艺术字图案，给用户一个愉快的告别体验。





# 结束语

通过完成这个学生信息管理系统的C语言程序，我深入学习了C语言的各个方面，并获得了宝贵的编程经验和技能。这个项目不仅让我理解了C语言的基本语法和概念，还提高了我的问题解决能力和软件开发的实践技巧。

在这个程序中，我实现了学生信息的录入、打印、保存和读取等功能，同时还包括了学生信息的查找、修改和删除等操作。通过使用数据结构和算法，我能够高效地管理和操作学生信息，提供了一个简单而功能完备的学生信息管理系统。

在项目的过程中，我学会了如何设计模块化的代码结构，合理地划分函数和数据结构，提高了代码的可读性和可维护性。我还加强了对文件操作的理解，以及如何处理用户输入和异常情况的技巧。

通过这个学生信息管理系统的C语言程序，我不仅掌握了C语言的基础知识，还提升了编程思维和解决问题的能力。我深刻意识到编程是一门需要不断学习和实践的艺术，通过实际项目的经验，我在错误和挑战中成长，不断改进和优化自己的代码。

我将这个学生信息管理系统的C语言程序分享给其他人，希望能够帮助他们理解C语言的应用和实践，以及如何构建简单而实用的信息管理系统。无论是初学者还是有一定经验的编程者，这个项目都可以作为一个有益的学习资源，促进他们在C语言编程领域的成长。

