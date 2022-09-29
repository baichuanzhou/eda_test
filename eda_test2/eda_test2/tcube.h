#pragma once
#include "cube.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Cube;


class T_Cube {

public:
	T_Cube(int num);	// constructor

	T_Cube();
	// ~T_Cube();	// destroyer

	bool judgeContain(Cube& cube);

	bool judgeContain(T_Cube& otherTCube);

	bool isEmpty() const;

	void printContain(T_Cube& otherTCube);
	
	void absorb();

	void shrink();

	void addCube(const Cube& cube);

	T_Cube crossCube(const Cube& cube);

	T_Cube crossCube(T_Cube& otherTCube);

	T_Cube operator+(const T_Cube& otherTCube);

	T_Cube operator+(const Cube& cube);

	T_Cube& operator+=(const Cube& cube);

	T_Cube& operator+=(const T_Cube& otherTCube);

	T_Cube& operator=(const T_Cube& otherTCube);

	T_Cube operator-(const Cube& cube);

	T_Cube& operator-=(const Cube& cube);

	T_Cube operator-(const T_Cube& otherTCube);

	T_Cube& operator-=(const T_Cube& otherTCube);
	
private:
	vector<Cube> T;
	int size;
	friend std::ostream& operator<<(std::ostream& out, const T_Cube& t_cube);
};

