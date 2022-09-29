#pragma once
#include "tcube.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;
class T_Cube;

class Cube {
	friend T_Cube expandCube(Cube cube, int index, T_Cube& cubeSet);	// ��Ԫ����, ��һ��������չ��
																		// ��: 1xx չ��Ϊ100, 101, 110, 111
public:
	Cube();

	Cube(string cubeString);

	~Cube();

	bool judgeContain(const Cube& child) const;	// �ж��������Ƿ����

	bool judgeHelper(char child, char parent) const;

	bool contain(char ch);	// �ж��������Ƿ��������ch
	
	bool checkCube();	// ����������Ƿ�Ϸ�

	bool checkCubeHelper(char ch);	

	bool isEmpty() const;	// �ж��������Ƿ�Ϊ��

	void getCube();	// ����������и���, �����������ô˺���

	string strCube() const;	// ����������ַ���

	void printContain(Cube& child);	// ��ӡ�������Ƿ����

	char crossCubeHelper(char ch1, char ch2);

	Cube crossCube(const Cube& otherCube);	// �����������ཻ

	int getDimension() const;	// ����������ά��

	bool operator==(const Cube& cube);	// ���������==, �ж��Ƿ����

	bool operator!=(const Cube& cube);	// ���������!=

	Cube& operator=(const Cube& otherCube);	// ���������=, �������帳ֵ

	T_Cube operator+(const Cube& otherCube);	// ���������+, ������֮����ӵõ������弯��

	Cube operator+(const char ch);	// ���������, ���������ά��

	Cube& operator+=(const char ch);	// ���������+=

	T_Cube operator*(const Cube& otherCube);	// ���������*, ����Ϊ���

	Cube operator/(const Cube& otherCube);	// ���������/, ����Ϊ������֮��ĺϲ�, ��000��001, �ϲ�Ϊ00x
											//									 ���޷��ϲ��򷵻ؿ�������

	// Cube operator-(const Cube& otherCube);

private:
	string cube;
	int dimension;
	friend std::ostream& operator<<(std::ostream& out, const Cube& cube);
};
