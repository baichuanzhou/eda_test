#include "contain.h"

void testAbsorb() {
	Cube cube1;
	
	Cube cube2;
	Cube cube3;
	Cube cube4;
	Cube cube5;
	Cube cube6;

	T_Cube T1;
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
		child.judgeContain(parent);
		parent.judgeContain(child);
	}
}

int main() {
	// testCubeContain();

	testAbsorb();
	return 0;
}