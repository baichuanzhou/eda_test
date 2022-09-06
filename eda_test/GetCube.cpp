#include "GetCube.h"

bool IsLegal(char ch)
{
	switch (ch)
	{
		case '1':
			return true;
		case '0':
			return true;
		case 'x':
			return true;
	}
	return false;
}

bool CheckCube(char* cube)
{
	int len = strlen(cube);
	for (int i = 0; i < len; i++)
		if (!IsLegal(cube[i]))
			return false;
	return true;
}

char* GetCube()
{
	char cube[100];
	static int count = 1;
	cout << "请输入第" << count << "个:)" << endl;
	count++;
	cin >> cube;
	if (!CheckCube(cube))
	{
		cout << "输入的" << cube << "不合法" << endl;
		cout << "请重新输入" << endl;
		cin >> cube;
		return cube;
	}
	return cube;
}