/**************************************************************
* 文件名: classmates.c
* 内容摘要：完成 同学 相关的 显示，添加，删除，操作。
* 但前版本：version 0.1
* 作者：果园耕
* 完成日期：2017.1.10
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
***************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include"list.h"
#include"classmates.h"

/****************************************************
* 函数名：void add_one_classmate(void)
* 函数功能：添加同学
* 输入参数：无
* 输出参数：无
* 返回值：void
* 其他说明：无
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void add_one_classmate(void)
{
    PT_Classmates ptCur = creat_one_node();
    init_one_node(ptCur);

    add_node(ptCur);
}

/****************************************************
* 函数名：void del_one_classmate(void)
* 函数功能：删除特定同学
* 输入参数：无
* 输出参数：无
* 返回值：void
* 其他说明：无
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void del_one_classmate(void)
{
    PT_Classmates ptFind;
    char name[128];

    printf("Enter the name you want to delete: ");
    scanf("%s", name);

    ptFind = find_node(name);
    if (ptFind == NULL)  //如果没有找到
    {
        printf("Do not have this classmate!");
        return;
    }
    else
    {
        del_node(ptFind);
        return;
    }
}

/****************************************************
* 函数名：void list_all_classmates(void)
* 函数功能：列出所有同学
* 输入参数：无
* 输出参数：无
* 返回值：void
* 其他说明：无
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void list_all_classmates(void)
{
    list_all_node();
}
