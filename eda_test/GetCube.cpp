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
	cout << "�������" << count << "��:)" << endl;
	count++;
	cin >> cube;
	if (!CheckCube(cube))
	{
		cout << "�����" << cube << "���Ϸ�" << endl;
		cout << "����������" << endl;
		cin >> cube;
		return cube;
	}
	return cube;
}