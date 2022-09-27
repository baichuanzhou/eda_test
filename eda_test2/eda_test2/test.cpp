#include "contain.h"

void testAbsorb() {
	Cube cube1;
	
	Cube cube2;
	Cube cube3;
	Cube cube4;
	Cube cube5;
	Cube cube6;

	T_Cube T1(0);
	T1.addCube(cube1);
	T1.addCube(cube2);
	T1.addCube(cube3);
	T1.addCube(cube4);
	T1.addCube(cube5);
	T1.addCube(cube6);
	
	T1.absorb();
	cout << T1;
}

void testCubeContain()
{
	while (true) {
		Cube child;
		Cube parent;
		// child.getCube();
		// parent.getCube();
		child.printContain(parent);
		parent.printContain(child);
	}
}

void menu() {
	cout << endl;
	cout << "***************************" << endl;
	cout << "***选择需要进行的运算*******" << endl;
	cout << "***1. 立方体包含运算********" << endl;
	cout << "***2. 立方体集合吸收********" << endl;
	cout << "********-1. 退出***********" << endl;
	cout << "***************************" << endl;
}

void cubeContain() {
	Cube child;
	Cube parent;
	child.printContain(parent);
	parent.printContain(child);
}

void tcubeAbsorb() {
	cout << "集合包含的立方体个数是:) " << endl;
	int size;
	cin >> size;
	T_Cube TCube(size);

	TCube.absorb();
	cout << TCube << endl;;
}
void test() {
	menu();
	int opt = 0;
	cin >> opt;
	while (opt != -1) {
		if (opt == 1) {
			cubeContain();
		}
		else if (opt == 2) {
			tcubeAbsorb();
		}

		else {
			cout << "操作数非法, 请重新输入:)" << endl;
		}
		menu();
		cin >> opt;
	}
}

int main() {
	test();
	return 0;
}