#include "tcube.h"
#include "cube.h"
#include <graphics.h>

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

void testExpandCube() {
	Cube t("xxx10x");
	T_Cube T = nullTCube;
	cout << expandCube(t, 0, T) << endl;
}

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
}

/// <>
/// //////////////
/// <>
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
	// test();
	// testTCubeConatain();
	// testTCubeAdd();
	// testExpandCube();

	// testSharpMul();

	// testOverload();

	// testCrossCube();
	initgraph(640, 480);

	ExMessage m;		// 定义消息变量

	while (true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{
		case WM_MOUSEMOVE:
			// 鼠标移动的时候画红色的小点
			putpixel(m.x, m.y, RED);
			break;

		case WM_LBUTTONDOWN:
			// 如果点左键的同时按下了 Ctrl 键
			if (m.ctrl)
				// 画一个大方块
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			else
				// 画一个小方块
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				return 0;	// 按 ESC 键退出程序
		}
	}

	// 关闭图形窗口
	closegraph();
	return 0;
}