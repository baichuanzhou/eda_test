#include "tcube.h"


T_Cube nullTCube(0);	// 定义一个空立方体集合
extern Cube nullCube;	// 声明, 从外部文件链接变量, 一个空立方体



T_Cube::T_Cube(int num) {
	size = 0;
	while (size != num) {
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

void T_Cube::shrink() {
	for (auto i = T.begin(); i < T.end() - 1; i++) {
		Cube cubeOne = *i;
		Cube cubeTwo = *(i + 1);
		if (cubeOne / cubeTwo != nullCube) {
			*i = cubeOne / cubeTwo;
			
		}
	}
	absorb();
}



void T_Cube::addCube(const Cube& cube) {
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
		result += temp;
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
	// temp.absorb();
	return temp;
}

T_Cube T_Cube::operator+(const Cube& cube) {
	T_Cube temp = *this;
	temp.addCube(cube);
	// temp.absorb();
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

T_Cube T_Cube::operator-(const Cube& cube) {
	T_Cube result = *this;

	for (auto iter = result.T.begin(); iter < result.T.end();) {
		if (*iter == cube) {
			iter = result.T.erase(iter);
		}
		else {
			iter++;
		}
	}
	// result.shrink();
	return result;
}

T_Cube& T_Cube::operator-=(const Cube& cube) {
	*this = *this - cube;
	return *this;
}

T_Cube T_Cube::operator-(const T_Cube& otherTCube) {
	T_Cube result = *this;

	for (Cube indexCube : otherTCube.T) {
		result -= indexCube;
	}
	return result;
}

T_Cube& T_Cube::operator-=(const T_Cube& otherTCube) {
	*this = *this - otherTCube;
	return *this;
}