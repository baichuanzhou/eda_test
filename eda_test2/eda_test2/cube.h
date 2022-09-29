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
	friend T_Cube expandCube(Cube cube, int index, T_Cube& cubeSet);	// 友元函数, 将一个立方体展开
																		// 如: 1xx 展开为100, 101, 110, 111
public:
	Cube();

	Cube(string cubeString);

	~Cube();

	bool judgeContain(const Cube& child) const;	// 判断立方体是否包含

	bool judgeHelper(char child, char parent) const;

	bool contain(char ch);	// 判断立方体是否包含变量ch
	
	bool checkCube();	// 检查立方体是否合法

	bool checkCubeHelper(char ch);	

	bool isEmpty() const;	// 判断立方体是否为空

	void getCube();	// 对立方体进行复制, 析构函数调用此函数

	string strCube() const;	// 获得立方体字符串

	void printContain(Cube& child);	// 打印立方体是否包含

	char crossCubeHelper(char ch1, char ch2);

	Cube crossCube(const Cube& otherCube);	// 获得立方体的相交

	int getDimension() const;	// 获得立方体的维度

	bool operator==(const Cube& cube);	// 重载运算符==, 判断是否相等

	bool operator!=(const Cube& cube);	// 重载运算符!=

	Cube& operator=(const Cube& otherCube);	// 重载运算符=, 对立方体赋值

	T_Cube operator+(const Cube& otherCube);	// 重载运算符+, 立方体之间相加得到立方体集合

	Cube operator+(const char ch);	// 重载运算符, 对立方体加维度

	Cube& operator+=(const char ch);	// 重载运算符+=

	T_Cube operator*(const Cube& otherCube);	// 重载运算符*, 定义为锐积

	Cube operator/(const Cube& otherCube);	// 重载运算符/, 定义为立方体之间的合并, 如000与001, 合并为00x
											//									 若无法合并则返回空立方体

	// Cube operator-(const Cube& otherCube);

private:
	string cube;
	int dimension;
	friend std::ostream& operator<<(std::ostream& out, const Cube& cube);
};
