#pragma once
#include "tcube.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;
class T_Cube;

class Cube {
	friend T_Cube expandCube(Cube cube, int index, T_Cube& cubeSet);
public:
	Cube();

	Cube(string cubeString);

	~Cube();

	bool judgeContain(const Cube& child) const;

	bool judgeHelper(char child, char parent) const;

	bool contain(char ch);

	bool checkCube();

	bool checkCubeHelper(char ch);

	bool isEmpty() const;

	void getCube();

	string strCube() const;

	void printContain(Cube& child);

	char crossCubeHelper(char ch1, char ch2);

	Cube crossCube(const Cube& otherCube);

	int getDimension() const;

	bool operator==(const Cube& cube);

	bool operator!=(const Cube& cube);

	Cube& operator=(const Cube& otherCube);

	T_Cube operator+(const Cube& otherCube);

	Cube operator+(const char ch);

	Cube& operator+=(const char ch);

	T_Cube operator*(const Cube& otherCube);

	Cube operator/(const Cube& otherCube);

	// Cube operator-(const Cube& otherCube);

private:
	string cube;
	int dimension;
	friend std::ostream& operator<<(std::ostream& out, const Cube& cube);
};
