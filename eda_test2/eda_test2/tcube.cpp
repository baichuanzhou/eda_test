#include "tcube.h"
#include "cube.h"

T_Cube nullTCube(0);	// 定义一个空立方体集合
extern Cube nullCube;	// 声明, 从外部文件链接变量, 一个空立方体



T_Cube::T_Cube(int num) {
	size = 0;
	cubeDimension = 0;
	dcSize = 0;
	while (size != num) {
		Cube tempCube;
		addCube(tempCube);
	}
	
}

T_Cube::T_Cube() {
	size = 0;
	dcSize = 0;
	cubeDimension = 0;
	cout << "输入立方体集合的立方体个数:) " << endl;
	int num = 0;
	cin >> num;
	while (size != num) {
		Cube tempCube;
		addCube(tempCube);
	}
}

T_Cube::T_Cube(vector<Cube> TCube) {
	size = 0;
	dcSize = 0;
	for (int i = 0; i < TCube.size(); i++) {
		addCube(TCube[i]);
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
				cout << "Original ON: " << * this << endl;
				cout << childTemp << " => " << parentTemp << endl;
				cout << "Delete: " << childTemp << endl;
				j = T.erase(j);
				i = T.begin();
				cout << "Now ON: " << * this << endl;
				cout << endl;
			}
			else {
				j++;
			}
		}
	}

	for (auto i = DC.begin(); i < DC.end(); i++) {
		for (auto j = DC.begin(); j < DC.end();) {
			Cube parentTemp = *i;
			Cube childTemp = *j;
			if (parentTemp.judgeContain(childTemp) && !childTemp.judgeContain(parentTemp)) {
				cout << endl;
				cout << "Original DC: " << *this << endl;
				cout << childTemp << " => " << parentTemp << endl;
				cout << "Delete: " << childTemp << endl;
				j = T.erase(j);
				i = T.begin();
				cout << "Now DC: " << *this << endl;
				cout << endl;
			}
			else {
				j++;
			}
		}
	}
	// T = absorbHelper(T);
	// DC = absorbHelper(DC);
}

vector<Cube> T_Cube::absorbHelper(vector<Cube> TCube) {
	for (auto i = TCube.begin(); i < TCube.end(); i++) {
		for (auto j = TCube.begin(); j < TCube.end();) {
			Cube parentTemp = *i;
			Cube childTemp = *j;
			if (parentTemp.judgeContain(childTemp) && !childTemp.judgeContain(parentTemp)) {
				cout << endl;
				cout << "Original: " << *this << endl;
				cout << childTemp << " => " << parentTemp << endl;
				cout << "Delete: " << childTemp << endl;
				j = T.erase(j);
				i = T.begin();
				cout << "Now: " << *this << endl;
				cout << endl;
			}
			else {
				j++;
			}
		}
	}
	return TCube;
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
		cubeDimension = cube.getDimension();
		size++;
	}
	else {
		Cube res = cube;
		while (cubeDimension != res.getDimension()) {
			cout << *this << "与" << res << "不在一个维度上!" << endl;
			cout << "请重新输入一个维度为" << cubeDimension << "的立方体" << endl;
			string newCube;
			cin >> newCube;
			res = Cube(newCube);
		}
		
		for (int i = 0; i < size; i++) {
			if (T[i] == res) {
				return;
			}
		}
		T.push_back(res);
		absorb();
		size = T.size();
	}
}

void T_Cube::addDC(const Cube& cube) {
	if (cube.isEmpty()) {
		return;
	}
	if (size == 0) {
		DC.push_back(cube);
		cubeDimension = cube.getDimension();
		dcSize++;
	}
	else {
		Cube res = cube;
		while (cubeDimension != res.getDimension()) {
			cout << *this << "与" << res << "不在一个维度上!" << endl;
			cout << "请重新输入一个维度为" << cubeDimension << "的立方体" << endl;
			string newCube;
			cin >> newCube;
			res = Cube(newCube);
		}
		for (int i = 0; i < dcSize; i++) {
			if (res == DC[i]) {
				return;
			}
		}
		DC.push_back(res);
		absorb();
		dcSize++;
	}
}

T_Cube T_Cube::originalContains() {
	Cube Un = nullCube;
	for (int i = 0; i < cubeDimension; i++) {
		Un += 'x';
	}
	// cout << *this << endl;
	T_Cube ON = T_Cube(T);
	// cout << ON << endl;
	T_Cube DCCube = T_Cube(DC);
	// cout << DCCube << endl;
	T_Cube dup = ON + DCCube;
	// cout << dup << endl;
	T_Cube OFF = Un * dup;
	// cout << OFF << endl;
	dup = Un * OFF;
	// cout << dup << endl;
	T_Cube result = nullTCube;
	for (Cube indexCube : dup.T) {
		if (ON.crossCube(indexCube).size != 0) {
			result += indexCube;
		}
	}
	return result;
}

T_Cube T_Cube::crossCube(const Cube& cube) {
	T_Cube result = nullTCube;
	for (Cube indexCube : T) {
		Cube temp = indexCube.crossCube(cube);
		result += temp;
	}
	result.absorb();
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
	DC = otherTCube.DC;
	dcSize = otherTCube.dcSize;
	cubeDimension = otherTCube.cubeDimension;
	return *this;
}

T_Cube T_Cube::operator+(const T_Cube& otherTCube) {
	T_Cube temp = *this;
	for (Cube tempCube : otherTCube.T) {
		temp.addCube(tempCube);
	}
	
	return temp;
}

T_Cube T_Cube::operator+(const Cube& cube) {
	T_Cube temp = *this;
	temp.addCube(cube);
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

T_Cube T_Cube::operator*(const T_Cube& otherTCube) {
	T_Cube result = nullTCube;
	for (Cube indexCube : T) {
		result += indexCube * otherTCube;
	}
	return result;
}

T_Cube& T_Cube::operator*=(const T_Cube& otherTCube) {
	*this = *this * otherTCube;
	return *this;
}

T_Cube T_Cube::operator*(const Cube& otherCube) {
	T_Cube result = nullTCube;
	for (Cube indexCube : T) {
		result += indexCube * otherCube;
	}
	return result;
}

T_Cube& T_Cube::operator*=(const Cube& otherCube) {
	*this = *this * otherCube;
	return *this;
}