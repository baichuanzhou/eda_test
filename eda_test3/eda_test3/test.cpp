#include "tcube.h"
#include "cube.h"
#include "utils.h"
#include <iostream>

using namespace std;
extern TCube nullTCube;
extern Cube nullCube;

void testAbsorb() {
	Cube cube1("111");
	Cube cube2("1xx");
	Cube cube3("101");
	Cube cube4("100");
	Cube cube5("011");
	Cube cube6("110");

	TCube T1 = cube1 + cube2 + cube3 + cube4 + cube5 + cube6;

	T1.absorb();
	cout << T1;
}

void testTCubeAdd() {
	TCube T1 = Cube("111") + nullCube;
	TCube T2 = Cube("110") + nullCube;

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
	TCube T;

	T = t1 + t2;

	cout << T.crossCube(t) << endl;
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

	TCube T1 = Cube("0x0x") + Cube("x100") + Cube("0001") + Cube("00x1");
	TCube T2 = Cube("0xx1") + Cube("x1x1");
	cout << T1 * T2 << endl;
}

void testCrossMerge() {
	Cube t1("000");
	Cube t2("010");
	cout << t1.crossMerge(t2) << endl;

	Cube t3("0x0");
	Cube t4("1xx");
	cout << t3.crossMerge(t4) << endl;
	cout << t4.crossMerge(t3) << endl;
}

void testExtractTCube() {
	string line = "111 110";
	cout << extractTCube(line);
}

void testEvaluate() {
	string line = "{xxx 110} + {111} # {000} #     {100  {}    111}";
	cout << evaluate(line);
}

void testCheckBrackets() {
	
	checkBrackets("{{}}");
}

void test() {
	while (true) {
		string line;
		cout << "ÇëÊäÈë¼ÆËãÊ½:" << endl;
		getline(cin, line);
		if (line[0] == '?') {
			if (getTruth(line.substr(1))) {
				cout << "True" << endl;
			}	
			else {
				cout << "False" << endl;
			}
		}
		else {
			checkLegal(line);
			cout << evaluate(line) << endl;
		}
	}
}

int main() {
	// testAbsorb();
	// testTCubeAdd();
	// testCrossCube();
	// testCrossTCube();
	// testSharpMul();
	// testCrossMerge();
	// testExtractTCube();
	// testEvaluate();
	// testCheckBrackets();
	test();
	return 0;
}