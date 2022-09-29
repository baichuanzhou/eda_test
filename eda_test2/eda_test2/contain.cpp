#include "cube.h"
#include "tcube.h"


Cube nullCube("");
T_Cube nullTCube(0);

Cube::Cube() {
	getCube();
	dimension = cube.length();
}

Cube::Cube(string cubeString) {
	cube = cubeString;
	dimension = cubeString.length();
	assert(checkCube());
}

Cube::~Cube() {
	cube = "";
	dimension = 0;
}

bool Cube::judgeContain(const Cube& child) {
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
	if (cube.empty()) {
		return true;
	}

	for (char ch : cube) {
		if (!checkCubeHelper(ch)) {
			return false;
		}
	}
	return true;
}

bool Cube::isEmpty() const{
	return dimension == 0;
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

char Cube::crossCubeHelper(char ch1, char ch2) {
	if (ch1 == ch2) {
		return ch1;
	}

	if (ch1 == 'x') {
		return ch2;
	}

	if (ch2 == 'x') {
		return ch1;
	}

	return '*';
}

Cube Cube::crossCube(const Cube& otherCube) {
	if (judgeContain(otherCube)) {
		return otherCube;
	}
	if (otherCube.getDimension() != dimension) {
		return nullCube;
	}

	Cube crossCubeRes("");
	string othercube = otherCube.cube;
	for (int i = 0; i < cube.length(); i++) {
		if (crossCubeHelper(cube[i], othercube[i]) == '*') {
			return nullCube;
		}
		crossCubeRes += crossCubeHelper(cube[i], othercube[i]);
	}
	return crossCubeRes;
}

int Cube::getDimension() const {
	return dimension;
}

bool Cube::operator==(const Cube& otherCube) {
	return otherCube.cube == cube;
}

Cube& Cube::operator=(const Cube& otherCube) {
	cube = otherCube.cube;
	dimension = otherCube.dimension;
	return *this;
}

T_Cube Cube::operator&(const Cube& otherCube) {
	T_Cube result = nullTCube;
	result.addCube(*this);
	result.addCube(otherCube);
	result.absorb();
	return result;
}

Cube Cube::operator+(const char ch) {
	if (!checkCubeHelper(ch)) {
		return *this;
	}
	cube += ch;
	dimension++;
	return *this;
}

Cube& Cube::operator+=(const char ch) {
	assert(checkCubeHelper(ch));
	*this = *this + ch;
	return *this;
}



ostream& operator<<(std::ostream& out, const Cube& cube) {
	out << "{";
	if (!cube.isEmpty()) {
		out << cube.cube;
	}
	out << "}";
	return out;
}
///////////////////////////////////////////////////////////////////////////
//**************以上是立方体类的构建***************************************/
///////////////////////////////////////////////////////////////////////////


T_Cube::T_Cube(int num) {
	size = 0;
	while(size != num) {
		Cube tempCube;
		addCube(tempCube);
	}
}

T_Cube::T_Cube() {
	size = 0;
	cout << "输入立方体集合的立方体数:) " << endl;
	int num = 0;
	cin >> num;
	while (size != num) {
		Cube tempCube;
		addCube(tempCube);
	}
}

bool T_Cube::judgeContain(Cube& cube) {
	for (Cube tempCube : T) {
		if (tempCube.judgeContain(cube)) {
			return true;
		}
	}
	return false;
}

bool T_Cube::judgeContain(T_Cube& otherTCube) {
	for (Cube tempCube : otherTCube.T) {
		if (!judgeContain(tempCube)) {
			return false;
		}
	}
	return true;
}

bool T_Cube::isEmpty() const {
	return size == 0;
}

void T_Cube::printContain(T_Cube& otherTCube) {
	if (judgeContain(otherTCube)) {
		cout << otherTCube << " => " << *this << endl;
		return;
	}
	cout << otherTCube << " !=> " << *this << endl;
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
	for (auto i = T.begin(); i < T.end(); i++) {
		for (auto j = T.begin(); j < T.end();) {
			Cube parentTemp = *i;
			Cube childTemp = *j;
			if (parentTemp.judgeContain(childTemp) && !childTemp.judgeContain(parentTemp)) {
				cout << endl;
				cout << childTemp << " => " << parentTemp << endl;
				cout << "Delete " << childTemp << endl;
				cout << endl;
				j = T.erase(j);
				i = T.begin();
			}
			else {
				j++;
			}
		}
	}
}

void T_Cube::addCube(const Cube cube) {
	if (cube.isEmpty()) {
		return;
	}
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

T_Cube T_Cube::crossCube(const Cube& cube) {
	T_Cube result = nullTCube;
	for (Cube indexCube : T) {
		Cube temp = indexCube.crossCube(cube);
		result += cube;
	}
	return result;
}

T_Cube T_Cube::crossCube(T_Cube& otherTCube) {
	T_Cube result = nullTCube;
	for (Cube indexCube : T) {
		result += otherTCube.crossCube(indexCube);
	}
	return result;
}

T_Cube& T_Cube::operator=(const T_Cube& otherTCube) {
	T = otherTCube.T;
	size = otherTCube.size;
	return *this;
}

T_Cube T_Cube::operator+(const T_Cube& otherTCube) {
	T_Cube temp = *this;
	for (Cube tempCube : otherTCube.T) {
		temp.addCube(tempCube);
	}
	temp.absorb();
	return temp;
}

T_Cube T_Cube::operator+(const Cube& cube) {
	T_Cube temp = *this;
	temp.addCube(cube);
	temp.absorb();
	return temp;
}

T_Cube& T_Cube::operator+=(const Cube& cube) {
	*this = *this + cube;
	return *this;
}

T_Cube& T_Cube::operator+=(const T_Cube& otherTCube) {
	*this = *this + otherTCube;
	return *this;
}