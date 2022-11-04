#include "cube.h"
#include "tcube.h"

Cube nullCube("");	// 定义一个空立方体
extern T_Cube nullTCube;	// 声明, 从外部文件链接变量, 一个空立方集合

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

bool Cube::judgeContain(const Cube& child) const{
	if (child.cube.length() != cube.length()) {
		cout << cube << "与" << child.cube << "不在一个维度上!:(" << endl;
		return false;
	}
	string childCube = child.cube;
	string parentCube = cube;
	for (int i = 0; i < childCube.length(); i++) {
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

bool Cube::contain(char ch) {
	for (char indexCh : cube) {
		if (indexCh == ch) {
			return true;
		}
	}
	return false;
}

bool Cube::judgeHelper(char child, char parent) const{
	if (parent != 'x') {
		return false;
	}
	return true;
}

bool Cube::checkCubeHelper(char ch){
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

bool Cube::isEmpty() const {
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

string Cube::strCube() const {
	return cube;
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

char crossMergeCal(char cubeOne, char cubeTwo) {
	if (cubeOne == cubeTwo) {
		return cubeOne;
	}
	if (cubeOne == 'x') {
		return cubeTwo;
	}
	if (cubeTwo == 'x') {
		return cubeOne;
	}
	else {
		return '$';
	}
}

Cube Cube::crossMerge(Cube& otherCube) {
	Cube crossMergeRes("");
	int count = 0;
	for (int i = 0; i < getDimension();i ++) {
		if (crossMergeCal(cube[i], otherCube.cube[i]) == '$') {
			count++;
		}
	}
	if (count == 1) {
		for (int i = 0; i < getDimension(); i++) {
			if (crossMergeCal(cube[i], otherCube.cube[i]) == '$') {
				crossMergeRes += 'x';
			}
			else {
				crossMergeRes += crossMergeCal(cube[i], otherCube.cube[i]);
			}
		}
	}
	return crossMergeRes;
}

int Cube::getDimension() const {
	return dimension;
}

bool Cube::operator==(const Cube& otherCube) {
	return otherCube.cube == cube;
}

bool Cube::operator!=(const Cube& otherCube) {
	return !(*this == otherCube);
}

Cube& Cube::operator=(const Cube& otherCube) {
	cube = otherCube.cube;
	dimension = otherCube.dimension;
	return *this;
}

T_Cube Cube::operator+(const Cube& otherCube) {
	T_Cube result = nullTCube;
	result += *this;
	result += otherCube;
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

T_Cube Cube::operator*(const Cube& otherCube) {
	if (otherCube.judgeContain(*this)) {
		return nullTCube;
	}

	if (this->crossCube(otherCube) == nullCube) {
		return nullTCube + *this;
	}

	T_Cube result = nullTCube;
	for (int i = cube.length() - 1; i >= 0; i--) {
		if (cube[i] == 'x' && otherCube.cube[i] != 'x') {
			if (otherCube.cube[i] == '0') {
				result += Cube(cube.substr(0, i) + '1' + cube.substr(i + 1));
			}
			else {
				result += Cube(cube.substr(0, i) + '0' + cube.substr(i + 1));
			}
		}
	}
	return result;
}

T_Cube Cube::operator*(const T_Cube& TCube) {
	T_Cube result = nullTCube + *this;
	for (Cube indexCube : TCube.T) {
		result *= indexCube;
	}
	return result;
}

int countDiff(const Cube& cubeOne, const Cube& cubeTwo) {
	string strOne = cubeOne.strCube();
	string strTwo = cubeTwo.strCube();

	assert(strOne.length() == strTwo.length());

	int count = 0;
	for (int i = 0; i < strOne.length(); i++) {
		if (strOne[i] != strTwo[i]) {
			count++;
		}
	}
	return count;
}

Cube Cube::operator/(const Cube& otherCube) {
	Cube cubeOne = *this;
	if (countDiff(cubeOne, otherCube) == 1) {
		string strOne = this -> strCube();
		string strTwo = otherCube.strCube();
		int i = 0;
		for (i = 0; i < strOne.length(); i++) {
			if (strOne[i] != strTwo[i]) {
				break;
			}
		}
		cubeOne.cube[i] = 'x';
		return cubeOne;
	}
	return nullCube;
}



ostream& operator<<(std::ostream& out, const Cube& cube) {
	out << "{";
	if (!cube.isEmpty()) {
		out << cube.cube;
	}
	out << "}";
	return out;
}









T_Cube expandCube(Cube targetCube, int index, T_Cube& cubeSet)
{
	if (index >= targetCube.dimension) {
		if (!targetCube.contain('x')) {
			cubeSet += targetCube;
		}
		return cubeSet;
	}
	string cube = targetCube.cube;
	if (cube[index] == 'x') {
		Cube cube1(cube.substr(0, index) + "0" + cube.substr(index + 1));
		Cube cube2(cube.substr(0, index) + "1" + cube.substr(index + 1));
		expandCube(cube1, index + 1, cubeSet);
		expandCube(cube2, index + 1, cubeSet);
		
	}
	return expandCube(targetCube, index + 1, cubeSet);
}