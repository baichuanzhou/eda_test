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
    friend TCube expandCube(Cube cube, int index, TCube& cubeSet);	// ��Ԫ����, ��һ��������չ��
                                                                        // ��: 1xx չ��Ϊ100, 101, 110, 111

public:

    Cube(string cubeString); // check

    ~Cube(); // check

    bool judgeContain(const Cube& child) const;	// �ж��������Ƿ���� check

    bool contain(char ch);	// �ж��������Ƿ��������ch    check

    bool isEmpty() const;	// �ж��������Ƿ�Ϊ�� check

    Cube crossCube(const Cube& otherCube);	// �����������ཻ check

    Cube crossMerge(Cube& otherCube);   // check

    int getDimension() const;	// ����������ά�� check

    bool operator==(const Cube& cube);	// ���������==, �ж��Ƿ���� check

    bool operator!=(const Cube& cube);	// ���������!= check

    Cube& operator=(const Cube& otherCube);	// ���������=, �������帳ֵ check

    TCube operator+(const Cube& otherCube);	// ���������+, ������֮����ӵõ������弯�� check

    TCube operator*(const Cube& otherCube);	// ���������*, ����Ϊ���

    TCube operator*(const TCube& TCube);

    Cube operator/(const Cube& otherCube);	// ���������/, ����Ϊ������֮��ĺϲ�, ��000��001, �ϲ�Ϊ00x
                                            //									 ���޷��ϲ��򷵻ؿ�������

    // Cube operator-(const Cube& otherCube);

private:
    string cube;
    int dimension;


    friend std::ostream& operator<<(std::ostream& out, const Cube& cube); // check
    bool checkCube(string cubeString);	// ����������Ƿ�Ϸ�
    bool checkCubeHelper(char ch);
    bool judgeHelper(char child, char parent) const;
    char crossCubeHelper(char ch1, char ch2);   // check
    Cube operator+(const char ch);	// ���������, ���������ά��   check
    Cube& operator+=(const char ch);	// ���������+=  check
    
};
#endif // CUBE_H
