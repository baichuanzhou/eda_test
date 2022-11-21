#include "cube.h"
#include "tcube.h"

Cube nullCube("");	// 定义一个空立方体
extern TCube nullTCube;	// 声明, 从外部文件链接变量, 一个空立方集合

Cube::Cube(string cubeString) {
	if (!checkCube(cubeString)) {
		cout << "输入的立方体" << cubeString << "不合法" << endl;
		cout << "立方体只包含元素1, 0, x" << endl;
		cout << "而输入的立方体是:" << cubeString << endl;
		exit(-1);
	}
	cube = cubeString;
	dimension = cube.length();
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

bool Cube::checkCube(string cubeString) {
	if (cubeString.empty()) {
		return true;
	}

	for (char ch : cubeString) {
		if (!checkCubeHelper(ch)) {
			return false;
		}
	}
	return true;
}

Cube::~Cube() {
	cube = "";
	dimension = 0;
}

bool Cube:: isEmpty() const {
	return dimension == 0;
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

ostream& operator<<(std::ostream& out, const Cube& cube) {
	// out << "{";
	if (!cube.isEmpty()) {
		out << cube.cube;
	}
	// out << "}";
	return out;
}

TCube Cube::operator+(const Cube& otherCube) {
	TCube result = nullTCube;
	result += *this;
	result += otherCube;
	return result;
}

bool Cube::judgeHelper(char child, char parent) const {
	if (parent != 'x') {
		return false;
	}
	return true;
}

bool Cube::judgeContain(const Cube& child) const {
	if (child.getDimension() != dimension) {
		cout << cube << "与" << child.cube << "不在一个维度上!:(" << endl;
		return false;
	}
	string childCube = child.cube;
	string parentCube = cube;
	for (int i = 0; i < dimension; i++) {
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

TCube Cube::operator*(const Cube& otherCube) {
	if (otherCube.judgeContain(*this)) {
		return nullTCube;
	}

	if (this->crossCube(otherCube) == nullCube) {
		return nullTCube + *this;
	}

	TCube result = nullTCube;
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

TCube Cube::operator*(const TCube& T) {
	TCube result = nullTCube + *this;
	for (Cube indexCube : T.T) {
		result *= indexCube;
	}
	return result;
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
	for (int i = 0; i < getDimension(); i++) {
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