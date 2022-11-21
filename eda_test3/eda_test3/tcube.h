#pragma once
#ifndef TCUBE_H
#define TCUBE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Cube;	// ����, ���������ļ����Զ������� -- Cube

//	�Զ������� -- �����弯��
//	˽�б���: �����弯��T, ����
//			 �����弯�ϵ���������size, int
//			 ��Ԫ����, ��������� <<




class TCube {

public:
    TCube(int num);	// constructor check

    TCube(vector<Cube> TCube);

    TCube();

    void compatible(const TCube& otherTCube);

    bool judgeContain(Cube& cube);	// �ж��������Ƿ񱻰���   check

    bool judgeContain(TCube& otherTCube);	// ��������, �ж������弯���Ƿ񱻰���   check

    bool isEmpty() const;	// �ж������弯���Ƿ�Ϊ�� check
   
    void absorb(bool show = false);	// �������� check

    void addCube(const Cube& cube);	// �������弯���м���һ���µ������� check

    void addDC(const Cube& cube);

    TCube originalContains();

    TCube crossCube(const Cube& cube);	// �������������弯���ཻ

    TCube crossCube(TCube& otherTCube);	// ��������, �����弯��֮���ཻ

    TCube operator+(const TCube& otherTCube);	// ���������+, �����弯��֮�����    check

    TCube operator+(const Cube& cube);	// ���������+, �����弯�������������  check

    TCube& operator+=(const Cube& cube);	// ���������+=, �����弯����������, ��������ֵ    check

    TCube& operator+=(const TCube& otherTCube);	// ���������+=, �����弯��֮��, ��������ֵ  check

    TCube& operator=(const TCube& otherTCube);	// ���������=   check

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