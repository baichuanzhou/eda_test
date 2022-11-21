#pragma once
#ifndef CUBE_H
#define CUBE_H

#include "tcube.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;
class TCube;

class Cube {
    friend TCube expandCube(Cube cube, int index, TCube& cubeSet);	// 友元函数, 将一个立方体展开
                                                                        // 如: 1xx 展开为100, 101, 110, 111

public:

    Cube(string cubeString); // check

    ~Cube(); // check

    bool judgeContain(const Cube& child) const;	// 判断立方体是否包含 check

    bool contain(char ch);	// 判断立方体是否包含变量ch    check

    bool isEmpty() const;	// 判断立方体是否为空 check

    Cube crossCube(const Cube& otherCube);	// 获得立方体的相交 check

    Cube crossMerge(Cube& otherCube);   // check

    int getDimension() const;	// 获得立方体的维度 check

    bool operator==(const Cube& cube);	// 重载运算符==, 判断是否相等 check

    bool operator!=(const Cube& cube);	// 重载运算符!= check

    Cube& operator=(const Cube& otherCube);	// 重载运算符=, 对立方体赋值 check

    TCube operator+(const Cube& otherCube);	// 重载运算符+, 立方体之间相加得到立方体集合 check

    TCube operator*(const Cube& otherCube);	// 重载运算符*, 定义为锐积

    TCube operator*(const TCube& TCube);

    Cube operator/(const Cube& otherCube);	// 重载运算符/, 定义为立方体之间的合并, 如000与001, 合并为00x
                                            //									 若无法合并则返回空立方体

    // Cube operator-(const Cube& otherCube);

private:
    string cube;
    int dimension;


    friend std::ostream& operator<<(std::ostream& out, const Cube& cube); // check
    bool checkCube(string cubeString);	// 检查立方体是否合法
    bool checkCubeHelper(char ch);
    bool judgeHelper(char child, char parent) const;
    char crossCubeHelper(char ch1, char ch2);   // check
    Cube operator+(const char ch);	// 重载运算符, 对立方体加维度   check
    Cube& operator+=(const char ch);	// 重载运算符+=  check
    
};
#endif // CUBE_H
