/**************************************************************
* �ļ���: main.c
* ����ժҪ��ͨ����ͬ��ѡ���ͬѧ������ӣ�ɾ������ʾ��
* ��ǰ�汾��version0.1
* ���ߣ���԰��
* ������ڣ�2017.1.10
* �޸�����       �汾��        �޸���         �޸�����
* ------------------------------------------------------
* 2017.1.10    version0.1      ��԰��
***************************************************************/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#include"list.h"
#include"classmates.h"

int main(int argc, char **argv)
{
    char cChoice;

    while (1)
    {
        printf("\n");
        printf("<l> List the classmates\n");
        printf("<a> Add one classmate\n");
        printf("<d> Delete one classmate\n");
        printf("<q> Quit\n");

        printf("Enter your choice:");
        cChoice = getchar();

        switch (cChoice)
        {
            case 'l':
            {
                //printf("case 'l':");
                list_all_classmates();
                break;
            }
            case 'a':
            {
                //printf("case 'a':");
                add_one_classmate();
                break;
            }
            case 'd':
            {
                //printf("case 'd':");
                del_one_classmate();
                break;
            }
            case 'q':
            {
                //printf("case 'q':");
                return 0;
                break;
            }
            default:
            {
                //printf("case 'default:':");
                break;
            }

        }/*end of switch (cChoice)*/

    }/*end of while (1)*/



    return 0;
}
