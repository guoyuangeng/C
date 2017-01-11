/**************************************************************
* 文件名: list.c
* 内容摘要：实现链表的相关操作
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

/*
* 变量名：g_ptListHead
* 变量作用：链表头
* 变量范围：list.c classmates.c
*/
PT_Classmates g_ptListHead = NULL;

/****************************************************
* 函数名：PT_Classmates creat_one_node(void)
* 函数功能：创建一个链表节点
* 输入参数：无
* 输出参数：ptCur
* 返回值：PT_Classmates
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
PT_Classmates creat_one_node(void)
{
    //printf("creat_one_node\n");
    PT_Classmates ptCur;
    ptCur = (PT_Classmates)malloc(sizeof(T_Classmates));

    return ptCur;
}

/****************************************************
* 函数名：void init_one_node(PT_Classmates ptClassmates)
* 函数功能：初始化一个节点
* 输入参数：PT_Classmates ptClassmates
* 输出参数：无
* 返回值：void
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void init_one_node(PT_Classmates ptClassmates)
{
    //printf("init_one_node\n");
    PT_Classmates ptTmp = ptClassmates;
    char* str;          //非常好
    char name[128];     //这个NB，name[]相当于一个buffer，

    printf("Enter the name: ");
    scanf("%s", name);

    str = (char*)malloc(sizeof(name)+1);        //在堆上申请空间
    strcpy(str, name);
    ptTmp->name = str;

    printf("Enter the age: ");
    scanf("%d", &ptTmp->age);

    printf("Enter the number: ");
    scanf("%d", &ptTmp->number);

    ptTmp->next = NULL;     //前一节点和后一节点未定
    ptTmp->pre = NULL;
}

/****************************************************
* 函数名：void add_node(PT_Classmates ptNewElemet)
* 函数功能：在链表尾部添加一个节点
* 输入参数：PT_Classmates ptDelElement
* 输出参数：无
* 返回值：void
* 其他说明：可能会修改全局变量 g_ptListHead
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void add_node(PT_Classmates ptNewElemet)
{
    printf("add_node\n");
    PT_Classmates ptCur;

    if (g_ptListHead == NULL)  //如果链表为空
    {
        //printf("this list is empty!\n");
        g_ptListHead = ptNewElemet;
    }
    else                    //如果链表不为空
    {
        ptCur = g_ptListHead;   //得到链表头的造作权

        while (ptCur->next)     //判断是否是最后一个元素，如果不是进入
        {
            ptCur = ptCur->next;
        }

        ptCur->next = ptNewElemet;      //在链表尾插入
        ptNewElemet->pre = ptCur;
    }/*end of if (g_ptListHead == NULL)*/
}

/****************************************************
* 函数名：void del_node(PT_Classmates ptDelElement)
* 函数功能：删除一个节点
* 输入参数：PT_Classmates ptDelElement
* 输出参数：无
* 返回值：void
* 其他说明：可能会修改全局变量 g_ptListHead
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void del_node(PT_Classmates ptDelElement)
{
    PT_Classmates ptCur;
    PT_Classmates ptPre;
    PT_Classmates ptNext;

    if (g_ptListHead == NULL)           //如果链表为空
    {
        printf("The list is empty!\n");
        return;
    }

    if (g_ptListHead == ptDelElement)   //如果链表的第一个节点就是要删除的节点
    {
        g_ptListHead = g_ptListHead->next;
        return;
    }
    else                                //如果不是第一个节点
    {
        ptCur = g_ptListHead;
        while (ptCur != NULL)
        {
            if (ptCur == ptDelElement)  //如果当前是欲删除元素
            {
                ptNext = ptCur->next;
                ptPre = ptCur->pre;

                ptPre->next = ptNext;
                if (ptNext != NULL)     //如果不是链表最后一个元素
                {
                    ptNext->pre = ptPre;
                }
                break;
            }
            ptCur = ptCur->next;
        }/*end of while(ptCur)*/
    }/*end of if(g_ptListHead == ptDelElement)*/

    free(ptDelElement->name);   //很精髓
    free(ptDelElement);
}

/****************************************************
* 函数名：PT_Classmates find_node(char* name)
* 函数功能：根据 链表成员 name 找到相应的节点
* 输入参数：char* name
* 输出参数：ptCur
* 返回值：PT_Classmates ptCur
* 其他说明：可能会修改全局变量 g_ptListHead
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
PT_Classmates find_node(char* name)
{
    PT_Classmates ptCur;

    if (g_ptListHead == NULL)       //如果链表为空
    {
        printf("The list is empty!");
        return NULL;
    }
    else
    {
        ptCur = g_ptListHead;
        do{
            if (strcmp(ptCur->name, name) == 0)     //当前节点是欲找的节点
            {
                return ptCur;
            }
            ptCur = ptCur->next;
        }while (ptCur);
        printf("There is no node you want!");
        return NULL;
    }/*end of if(g_ptListHead == NULL)*/
}

/****************************************************
* 函数名：void list_all_node(void)
* 函数功能：打印链表内容
* 输入参数：无
* 输出参数：无
* 返回值：void
* 其他说明：无
* 修改日期       版本号        修改人         修改内容
* ------------------------------------------------------
* 2017.1.10    version0.1      果园耕
****************************************************/
void list_all_node(void)
{
    PT_Classmates ptCur;
    int i = 0;
    ptCur = g_ptListHead;

    if (ptCur == NULL)  //如果链表为空
    {
        printf("This list is empty!!! \n");
        return;
    }

    while (ptCur != NULL)
    {
        printf("%02d : %s\n", i++, ptCur->name);
        printf("     %d\n", ptCur->age);
        printf("     %d\n", ptCur->number);
        ptCur = ptCur->next;
    }
}
