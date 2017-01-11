/**************************************************************
* 文件名: list.h
* 内容摘要：实现相关数据类型
* 但前版本：version 0.1
* 作者：果园耕
* 完成日期：2017.1.10
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
***************************************************************/

#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#include"list.h"
#include"classmates.h"

typedef struct T_Classmates
{
    char *name;
    int age;
    int number;
    struct T_Classmates* pre;
    struct T_Classmates* next;
} T_Classmates, *PT_Classmates;

PT_Classmates creat_one_node(void);
void init_one_node(PT_Classmates ptClassmates);
void add_node(PT_Classmates ptNewElemet);
void del_node(PT_Classmates ptDelElement);
PT_Classmates find_node(char* name);
void list_all_node(void);

#endif // _LIST_H
