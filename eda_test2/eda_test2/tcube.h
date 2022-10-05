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




class T_Cube {

public:
    T_Cube(int num);	// constructor

    T_Cube();

    // ~T_Cube();	// destroyer

    bool judgeContain(Cube& cube);	// �ж��������Ƿ񱻰���

    bool judgeContain(T_Cube& otherTCube);	// ��������, �ж������弯���Ƿ񱻰���

    bool isEmpty() const;	// �ж������弯���Ƿ�Ϊ��

    void printContain(T_Cube& otherTCube);	// ��ӡ�����弯���Ƿ񱻰���

    void absorb();	// ��������

    vector<Cube> absorbHelper(vector<Cube> TCube);

    void shrink();	// ��ŵͼ����

    void addCube(const Cube& cube);	// �������弯���м���һ���µ�������

    void addDC(const Cube& cube);

    T_Cube originalContains();

    T_Cube crossCube(const Cube& cube);	// �������������弯���ཻ

    T_Cube crossCube(T_Cube& otherTCube);	// ��������, �����弯��֮���ཻ

    T_Cube operator+(const T_Cube& otherTCube);	// ���������+, �����弯��֮�����(δ��������, ��ͬ)

    T_Cube operator+(const Cube& cube);	// ���������+, �����弯�������������

    T_Cube& operator+=(const Cube& cube);	// ���������+=, �����弯����������, ��������ֵ

    T_Cube& operator+=(const T_Cube& otherTCube);	// ���������+=, �����弯��֮��, ��������ֵ

    T_Cube& operator=(const T_Cube& otherTCube);	// ���������=

    T_Cube operator-(const Cube& cube);	// ���������-, ��������弯���а�����������ȥ(�����)

    T_Cube& operator-=(const Cube& cube);	// ���������-=

    T_Cube operator-(const T_Cube& otherTCube);	// ���������-, �����弯��֮�����

    T_Cube& operator-=(const T_Cube& otherTCube);	// ���������-=

    T_Cube operator*(const T_Cube& otherTCube);

    T_Cube& operator*=(const T_Cube& otherTCube);

    T_Cube operator*(const Cube& otherCube);

    T_Cube& operator*=(const Cube& otherCube);

private:
    T_Cube(vector<Cube> TCube);

    vector<Cube> T;
    vector<Cube> DC;
    int size;
    int cubeDimension;
    int dcSize;
    friend std::ostream& operator<<(std::ostream& out, const T_Cube& t_cube);
    friend class Cube;
};
#endif // TCUBE_H