#pragma once
#include "contain.h"


Cube::Cube() {
	getCube();
	dimension = cube.length();
}

Cube::~Cube() {
	cube = "";
	dimension = 0;
}

bool Cube::judgeContain(Cube& child) {
	if (child.cube.length() != cube.length()) {
		cout << cube << "与" << child.cube << "不在一个维度上!:(" << endl;
		return false;
	}
	string childCube = child.cube;
	string parentCube = cube;
	for (int i = 0;i < childCube.length();i++) {
		if (childCube[i] != parentCube[i]) {
			if (!judgeHelper(childCube[i], parentCube[i])) {
				// cout << childCube << " !=> " << parentCube << endl;
				return false;
			}
		}
	}
	// cout << childCube << " => " << parentCube << endl;
	return true;
}

bool Cube::judgeHelper(char child, char parent) {
	if (parent != 'x') {
		return false;
	}
	return true;
}

bool Cube::checkCubeHelper(char ch) {
	switch (ch) {
	case '1':
		return true;
	case '0':
		return true;
	case 'x':
		return true;
	}
	return false;
}

bool Cube::checkCube() {
	for (char ch : cube) {
		if (!checkCubeHelper(ch)) {
			return false;
		}
	}
	return true;
}

void Cube::getCube() {
	cout << "请输入一个立方体:)" << endl;
	cin >> cube;
	
	while (!checkCube()) {
		cout << "输入的立方体不合法, 请重新输入!" << endl;
		cout << "请输入一个立方体:)" << endl;
		cin >> cube;
	}
}

void Cube::printContain(Cube& child) {
	string childCube = child.cube;
	string parentCube = cube;
	if (judgeContain(child)) {
		cout << childCube << " => " << parentCube << endl;
	}
	cout << childCube << " !=> " << parentCube << endl;
}

int Cube::getDimension() {
	return dimension;
}

ostream& operator<<(std::ostream& out, const Cube& cube) {
	out << "{";
	if (!cube.cube.empty()) {
		out << cube.cube;
	}
	out << "}";
	return out;
}
///////////////////////////////////////////////////////////////////////////
//**************以上是立方体类的构建***************************************/
///////////////////////////////////////////////////////////////////////////


T_Cube::T_Cube(int num = 0) {
	size = 0;
	while(size != num) {
		Cube tempCube;
		addCube(tempCube);
	}
}

bool T_Cube::judgeContain(Cube& cube) {
	return true;
}



ostream& operator<<(std::ostream& out, const T_Cube& t_cube) {
	out << "{";
	if (!t_cube.T.empty()) {
		out << t_cube.T[0];
		for (int i = 1; i < t_cube.T.size(); i++) {
			out << ", " << t_cube.T[i];
		}
	}
	out << "}";
	return out;
}

void T_Cube::absorb() {
	vector<Cube> temp;
	temp = T;
	for (auto i = temp.begin(); i < temp.end(); i++) {
		for (auto j = temp.begin(); j < temp.end();) {
			Cube parentTemp = *i;
			Cube childTemp = *j;
			if (parentTemp.judgeContain(childTemp) && !childTemp.judgeContain(parentTemp)) {
				
				cout << childTemp << " => " << parentTemp << endl;
				cout << "Delete " << childTemp << endl;
				cout << endl;
				j = temp.erase(j);
				i = temp.begin();
			}
			else {
				j++;
			}
		}
	}
	T = temp;
	
}

void T_Cube::addCube(Cube cube) {
	if (size == 0) {
		T.push_back(cube);
		size++;
	}
	else {
		if (T[0].getDimension() != cube.getDimension()) {
			cout << "不在一个维度上!" << endl;
			return;
		}
		T.push_back(cube);
		size++;
	}
}