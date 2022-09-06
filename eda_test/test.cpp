/*
*******************************************
*************项目**************************
**开发者: baichuan**************************
**内容: 设定一个简单的判断包含关系的程序******
**时间: 2022年9月6日21:22:01****************
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