/*
*******************************************
*************��Ŀ**************************
**������: baichuan**************************
**����: �趨һ���򵥵��жϰ�����ϵ�ĳ���******
**ʱ��: 2022��9��6��21:22:01****************
*******************************************
*/
#include "GetCube.h"
#include "All.h"


int main()
{
	while (true)
	{
		char parent[100];
		char child[100];
		strcpy(child, GetCube());
		strcpy(parent, GetCube());
		JudgeContain(child, parent);
	}
	return 0;
}