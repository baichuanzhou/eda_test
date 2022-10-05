#include "tcube.h"
#include "cube.h"
#include "utils.h"
#include <iostream>

using namespace std;
extern T_Cube nullTCube;

void testAbsorb() {
	Cube cube1;
	
	Cube cube2;
	Cube cube3;
	Cube cube4;
	Cube cube5;
	Cube cube6;

	T_Cube T1 = cube1 + cube2 + cube3 + cube4 + cube5 + cube6;
	
	T1.absorb();
	cout << T1;
}

void testCubeContain()
{
	while (true) {
		Cube child;
		Cube parent;
		child.printContain(parent);
		parent.printContain(child);
	}
}

void testTCubeConatain() {
	T_Cube T1(2);
	T_Cube T2(2);
	T_Cube T3(2);

	T1.printContain(T2);
	T2.printContain(T3);
	T3.printContain(T2);
}

void testTCubeAdd() {
	T_Cube T1;
	T_Cube T2;

	cout << T1 + T2 << endl;
}

void testCrossCube() {
	Cube a("0x0");
	Cube c("11x");
	Cube d("1x1");
	Cube f("1xx");

	cout << a.crossCube(c) << endl;
	cout << c.crossCube(d) << endl;
	cout << c.crossCube(f) << endl;

}

void testCrossTCube() {
	Cube t("00x");

	Cube t1("0x0");
	Cube t2("x01");
	T_Cube T(0);

	T = t1 + t2;

	cout << T.crossCube(t) << endl;
}

//void testExpandCube() {
//	Cube t("xxx10x");
//	T_Cube T = nullTCube;
//	cout << expandCube(t, 0, T) << endl;
//}

void testOverload() {
	Cube t1("0x0");
	Cube t2("0x1");
	cout << t1 / t2 << endl;

	Cube t3("011");
	Cube t4("001");
	cout << t3 / t4 << endl;


	Cube t5("010");
	Cube t6("101");
	cout << t5 / t6 << endl;
}

void testSharpMul() {
	Cube t1("xxx");
	Cube t2("010");
	cout << t1 * t2 << endl;

	Cube t3("0xx");
	Cube t4("01x");
	cout << t3 * t4 << endl;

	Cube t5("0xx");
	Cube t6("x11");
	cout << t5 * t6 << endl;

	Cube t7("0xx");
	Cube t8("1x1");
	cout << t7 * t8 << endl;

	Cube t9("1xx0");
	Cube t10("x1x0");
	cout << t9 * t10 << endl;

	T_Cube T1 = Cube("0x0x") + Cube("x100") + Cube("0001") + Cube("00x1");
	T_Cube T2 = Cube("0xx1") + Cube("x1x1");
	cout << T1 * T2 << endl;
}

void testOriginalContains() {
	T_Cube T1 = Cube("001") + Cube("01x") + Cube("110");
	T1.addDC(Cube("10x"));
	cout << T1.originalContains() << endl;

	T_Cube T2 = Cube("0000") + Cube("0100") + Cube("01x1") + Cube("11x1") + Cube("0011");
	cout << T2.originalContains() << endl;

	T_Cube T3 = Cube("001") + Cube("01x") + Cube("110");
	T3.addDC(Cube("10x"));
	cout << T3.originalContains() << endl;
}

/// <>
/// //////////////
/// <>
void menu() {
	cout << endl;
	cout << "ѡ����Ҫ���е�����" << endl;
	cout << "1.����������" << endl;
	cout << "2.�����弯������" << endl;
	cout << "-1. �˳�" << endl;
	cout << endl;
}

void menuCube() {
	cout << endl;
	cout << "������֧���������㣺" << endl;
	cout << "1. �������Ƿ����" << endl;
	cout << "2. ������֮���ཻ" << endl;
	cout << "3. ������֮�����" << endl;
	cout << "4. ������֮������" << endl;
	cout << endl;
}

void testCube() {
	Cube c1;
	Cube c2;
	cout << endl << "1. " << endl;
	c1.printContain(c2);
	c2.printContain(c1);

	cout << endl << "2. " << endl;
	cout << c1 << " & " << c2 << " = " << c1.crossCube(c2) << endl;
	
	cout << endl << "3. " << endl;
	cout << c1 << " # " << c2 << " = " << c1 * c2 << endl;

	cout << endl << "4. " << endl;
	cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
}

void menuTCube() {
	cout << endl;
	cout << "�����弯��֧���������㣺" << endl;
	cout << "1. �����弯���Ƿ����" << endl;
	cout << "2. �����弯��֮���ཻ" << endl;
	cout << "3. �����弯��֮�����" << endl;
	cout << "4. �����弯��֮������" << endl;
	cout << "5. �����弯�ϱ�ԭ�̺�" << endl;
	cout << endl;
}

void testTCube() {
	cout << "���������������弯��:)" << endl;
	cout << "���Կո����������:)" << endl;

	string lineOne;
	string lineOneDC;

	string lineTwo;
	string lineTwoDC;

	cout << "�������һ�������弯�ϵ�ON:)" << endl;
	cin.ignore();
	getline(cin, lineOne);
	cout << "�������һ�������弯�ϵ�DC:)" << endl;
	getline(cin, lineOneDC);


	cout << "������ڶ��������弯�ϵ�ON:)" << endl;
	getline(cin, lineTwo);
	cout << "������ڶ��������弯�ϵ�DC:)" << endl;
	getline(cin, lineTwoDC);

	T_Cube T1 = nullTCube;
	for (string cubeStr : strip(lineOne)) {
		T1 += Cube(cubeStr);
	}

	for (string dcStr : strip(lineOneDC)) {
		T1.addDC(Cube(dcStr));
	}

	T_Cube T2 = nullTCube;
	for (string cubeStr : strip(lineTwo)) {
		T2 += Cube(cubeStr);
	}

	for (string dcStr : strip(lineTwoDC)) {
		T2.addDC(Cube(dcStr));
	}

	cout << endl << "1. " << endl;
	T1.printContain(T2);
	T2.printContain(T1);

	cout << endl << "2. " << endl;
	cout << T1 << " & " << T2 << " = " << T1.crossCube(T2);

	cout << endl << "3. " << endl;
	cout << T1 << " # " << T2 << " = " << T1 * T2 << endl;

	cout << endl << "4. " << endl;
	cout << T1 << " + " << T2 << " = " << T1 + T2 << endl;

	cout << endl << "5. " << endl;
	cout << "��һ�������弯�ϵı�ԭ�̺�: " << T1.originalContains() << endl;
	cout << "�ڶ��������弯�ϵı�ԭ�̺�: " << T2.originalContains() << endl;
}

void test() {
	menu();
	int opt = 0;
	cin >> opt;
	while (opt != -1) {
		if (opt == 1) {
			menuCube();
			testCube();
		}
		else if (opt == 2) {
			menuTCube();
			testTCube();
		}

		else {
			cout << "�������Ƿ�, ����������:)" << endl;
		}
		menu();
		cin >> opt;
	}
}



int main() {
	// test();
	// testTCubeConatain();
	// testTCubeAdd();
	// testExpandCube();

	// testSharpMul();

	// testOverload();

	// testCrossCube();
	// testCrossTCube();
	testOriginalContains();
	return 0;
}