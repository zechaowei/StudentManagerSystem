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





## InputStudent函数

```c
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
```

![](https://raw.githubusercontent.com/Anson-zechaoWei/photos_blog/main/img/%E5%BD%95%E5%85%A5%E5%AD%A6%E7%94%9F%E4%BF%A1%E6%81%AF%E6%A8%A1%E5%9D%97.gif)




