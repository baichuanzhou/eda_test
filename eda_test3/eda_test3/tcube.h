#pragma once
#ifndef TCUBE_H
#define TCUBE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Cube;	// 声明, 引入其他文件的自定义类型 -- Cube

//	自定义类型 -- 立方体集合
//	私有变量: 立方体集合T, 容器
//			 立方体集合的立方个数size, int
//			 友元函数, 重载运算符 <<




class TCube {

public:
    TCube(int num);	// constructor check

    TCube(vector<Cube> TCube);

    TCube();

    void compatible(const TCube& otherTCube);

    bool judgeContain(Cube& cube);	// 判断立方体是否被包含   check

    bool judgeContain(TCube& otherTCube);	// 函数重载, 判断立方体集合是否被包含   check

    bool isEmpty() const;	// 判断立方体集合是否为空 check
   
    void absorb(bool show = false);	// 吸收运算 check

    void addCube(const Cube& cube);	// 向立方体集合中加入一个新的立方体 check

    void addDC(const Cube& cube);

    TCube originalContains();

    TCube crossCube(const Cube& cube);	// 立方体与立方体集合相交

    TCube crossCube(TCube& otherTCube);	// 函数重载, 立方体集合之间相交

    TCube operator+(const TCube& otherTCube);	// 重载运算符+, 立方体集合之间相加    check

    TCube operator+(const Cube& cube);	// 重载运算符+, 立方体集合与立方体相加  check

    TCube& operator+=(const Cube& cube);	// 重载运算符+=, 立方体集合与立方体, 返回引用值    check

    TCube& operator+=(const TCube& otherTCube);	// 重载运算符+=, 立方体集合之间, 返回引用值  check

    TCube& operator=(const TCube& otherTCube);	// 重载运算符=   check

    TCube operator*(const TCube& otherTCube);

    TCube& operator*=(const TCube& otherTCube);

    TCube operator*(const Cube& otherCube);

    TCube& operator*=(const Cube& otherCube);

private:
    vector<Cube> T;
    vector<Cube> DC;
    int size;
    int cubeDimension;
    int dcSize;
    friend std::ostream& operator<<(std::ostream& out, const TCube& t_cube);   // check
    friend class Cube;
};
#endif // TCUBE_H