/**************************************************************
* �ļ���: classmates.c
* ����ժҪ����� ͬѧ ��ص� ��ʾ�����ӣ�ɾ����������
* ��ǰ�汾��version 0.1
* ���ߣ���԰��
* ������ڣ�2017.1.10
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
*
***************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include"list.h"
#include"classmates.h"

/****************************************************
* ��������void add_one_classmate(void)
* �������ܣ�����ͬѧ
* �����������
* �����������
* ����ֵ��void
* ����˵������
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
*
****************************************************/
void add_one_classmate(void)
{
    PT_Classmates ptCur = creat_one_node();
    init_one_node(ptCur);

    add_node(ptCur);
}

/****************************************************
* ��������void del_one_classmate(void)
* �������ܣ�ɾ���ض�ͬѧ
* �����������
* �����������
* ����ֵ��void
* ����˵������
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
void del_one_classmate(void)
{
    PT_Classmates ptFind;
    char name[128];

    printf("Enter the name you want to delete: ");
    scanf("%s", name);

    ptFind = find_node(name);
    if (ptFind == NULL)  //���û���ҵ�
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
* ��������void list_all_classmates(void)
* �������ܣ��г�����ͬѧ
* �����������
* �����������
* ����ֵ��void
* ����˵������
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
****************************************************/
void list_all_classmates(void)
{
    list_all_node();
}