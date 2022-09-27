#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Cube{
public:
	Cube();

	~Cube();
	
	bool judgeContain(Cube& child);

	bool judgeHelper(char child, char parent);

	bool checkCube();

	bool checkCubeHelper(char ch);

	void getCube();

	void printContain(Cube& child);

private:
	string cube;
	int dimension;
	friend std::ostream& operator<<(std::ostream& out, const Cube& cube);
};

class T_Cube {
public:
	// T_Cube();	// constructor
	// ~T_Cube();	// destroyer

	bool judgeContain(Cube& cube);
	
	void absorb();

	void addCube(Cube cube);
	
private:
	vector<Cube> T;
	int size;
	friend std::ostream& operator<<(std::ostream& out, const T_Cube& t_cube);
};