/**************************************************************
* �ļ���: list.c
* ����ժҪ��ʵ���������ز���
* ��ǰ�汾��version 0.1
* ���ߣ���԰��
* ������ڣ�2017.1.10
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
***************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include"list.h"

/*
* ��������g_ptListHead
* �������ã�����ͷ
* ������Χ��list.c classmates.c
*/
PT_Classmates g_ptListHead = NULL;

/****************************************************
* ��������PT_Classmates creat_one_node(void)
* �������ܣ�����һ������ڵ�
* �����������
* ���������ptCur
* ����ֵ��PT_Classmates
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
PT_Classmates creat_one_node(void)
{
    //printf("creat_one_node\n");
    PT_Classmates ptCur;
    ptCur = (PT_Classmates)malloc(sizeof(T_Classmates));

    return ptCur;
}

/****************************************************
* ��������void init_one_node(PT_Classmates ptClassmates)
* �������ܣ���ʼ��һ���ڵ�
* ���������PT_Classmates ptClassmates
* �����������
* ����ֵ��void
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
void init_one_node(PT_Classmates ptClassmates)
{
    //printf("init_one_node\n");
    PT_Classmates ptTmp = ptClassmates;
    char* str;          //�ǳ���
    char name[128];     //���NB��name[]�൱��һ��buffer��

    printf("Enter the name: ");
    scanf("%s", name);

    str = (char*)malloc(sizeof(name)+1);        //�ڶ�������ռ�
    strcpy(str, name);
    ptTmp->name = str;

    printf("Enter the age: ");
    scanf("%d", &ptTmp->age);

    printf("Enter the number: ");
    scanf("%d", &ptTmp->number);

    ptTmp->next = NULL;     //ǰһ�ڵ�ͺ�һ�ڵ�δ��
    ptTmp->pre = NULL;
}

/****************************************************
* ��������void add_node(PT_Classmates ptNewElemet)
* �������ܣ�������β�����һ���ڵ�
* ���������PT_Classmates ptDelElement
* �����������
* ����ֵ��void
* ����˵�������ܻ��޸�ȫ�ֱ��� g_ptListHead
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
void add_node(PT_Classmates ptNewElemet)
{
    printf("add_node\n");
    PT_Classmates ptCur;

    if (g_ptListHead == NULL)  //�������Ϊ��
    {
        //printf("this list is empty!\n");
        g_ptListHead = ptNewElemet;
    }
    else                    //�������Ϊ��
    {
        ptCur = g_ptListHead;   //�õ�����ͷ������Ȩ

        while (ptCur->next)     //�ж��Ƿ������һ��Ԫ�أ�������ǽ���
        {
            ptCur = ptCur->next;
        }

        ptCur->next = ptNewElemet;      //������β����
        ptNewElemet->pre = ptCur;
    }/*end of if (g_ptListHead == NULL)*/
}

/****************************************************
* ��������void del_node(PT_Classmates ptDelElement)
* �������ܣ�ɾ��һ���ڵ�
* ���������PT_Classmates ptDelElement
* �����������
* ����ֵ��void
* ����˵�������ܻ��޸�ȫ�ֱ��� g_ptListHead
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
void del_node(PT_Classmates ptDelElement)
{
    PT_Classmates ptCur;
    PT_Classmates ptPre;
    PT_Classmates ptNext;

    if (g_ptListHead == NULL)           //�������Ϊ��
    {
        printf("The list is empty!\n");
        return;
    }

    if (g_ptListHead == ptDelElement)   //�������ĵ�һ���ڵ����Ҫɾ���Ľڵ�
    {
        g_ptListHead = g_ptListHead->next;
        return;
    }
    else                                //������ǵ�һ���ڵ�
    {
        ptCur = g_ptListHead;
        while (ptCur != NULL)
        {
            if (ptCur == ptDelElement)  //�����ǰ����ɾ��Ԫ��
            {
                ptNext = ptCur->next;
                ptPre = ptCur->pre;

                ptPre->next = ptNext;
                if (ptNext != NULL)     //��������������һ��Ԫ��
                {
                    ptNext->pre = ptPre;
                }
                break;
            }
            ptCur = ptCur->next;
        }/*end of while(ptCur)*/
    }/*end of if(g_ptListHead == ptDelElement)*/

    free(ptDelElement->name);   //�ܾ���
    free(ptDelElement);
}

/****************************************************
* ��������PT_Classmates find_node(char* name)
* �������ܣ����� �����Ա name �ҵ���Ӧ�Ľڵ�
* ���������char* name
* ���������ptCur
* ����ֵ��PT_Classmates ptCur
* ����˵�������ܻ��޸�ȫ�ֱ��� g_ptListHead
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
PT_Classmates find_node(char* name)
{
    PT_Classmates ptCur;

    if (g_ptListHead == NULL)       //�������Ϊ��
    {
        printf("The list is empty!");
        return NULL;
    }
    else
    {
        ptCur = g_ptListHead;
        do{
            if (strcmp(ptCur->name, name) == 0)     //��ǰ�ڵ������ҵĽڵ�
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
* ��������void list_all_node(void)
* �������ܣ���ӡ��������
* �����������
* �����������
* ����ֵ��void
* ����˵������
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
void list_all_node(void)
{
    PT_Classmates ptCur;
    int i = 0;
    ptCur = g_ptListHead;

    if (ptCur == NULL)  //�������Ϊ��
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
