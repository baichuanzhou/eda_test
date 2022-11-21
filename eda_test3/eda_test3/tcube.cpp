#include "tcube.h"
#include "cube.h"

TCube nullTCube(0);	// 定义一个空立方体集合
extern Cube nullCube;	// 声明, 从外部文件链接变量, 一个空立方体

TCube::TCube(int num) {
	size = num;
	cubeDimension = 0;
	for (int i = 0; i < size; i++) {
		T.push_back(nullCube);
	}
	dcSize = 0;
	
}

TCube::TCube(vector<Cube> TCube) {
	cubeDimension = 0;
	size = 0;
	dcSize = 0;
	for (int i = 0; i < TCube.size(); i++) {
		addCube(TCube[i]);
	}
}

TCube::TCube() {
	cubeDimension = 0;
	size = 0;
	dcSize = 0;
}

void TCube::compatible(const TCube& otherTCube) {
	if (cubeDimension != otherTCube.cubeDimension) {
		cout << "立方体集合" << *this << "的立方体的维度是" << cubeDimension << endl;
		cout << "立方体集合" << otherTCube << "的立方体的维度是" << cubeDimension << endl;
		cout << "不匹配" << endl;
		exit(-1);
	}
	return;
}

bool TCube::isEmpty() const {
	return size == 0;
}

ostream& operator<<(std::ostream& out, const TCube& t_cube) {
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

void TCube::absorb(bool show) {
	for (auto i = T.begin(); i < T.end(); i++) {
		for (auto j = T.begin(); j < T.end();) {
			Cube parentTemp = *i;
			Cube childTemp = *j;
			if (parentTemp.judgeContain(childTemp) && !childTemp.judgeContain(parentTemp)) {
				if (show) {
					cout << endl;
					cout << "Original ON: " << *this << endl;
					cout << childTemp << " => " << parentTemp << endl;
					cout << "Delete: " << childTemp << endl;
				}
				j = T.erase(j);
				i = T.begin();
				if (show) {
					cout << "Now ON: " << *this << endl;
					cout << endl;
				}
				
			}
			else {
				j++;
			}
		}
	}
	//for (auto i = DC.begin(); i < DC.end(); i++) {
	//	for (auto j = DC.begin(); j < DC.end();) {
	//		Cube parentTemp = *i;
	//		Cube childTemp = *j;
	//		if (parentTemp.judgeContain(childTemp) && !childTemp.judgeContain(parentTemp)) {
	//			cout << endl;
	//			cout << "Original DC: " << *this << endl;
	//			cout << childTemp << " => " << parentTemp << endl;
	//			cout << "Delete: " << childTemp << endl;
	//			j = T.erase(j);
	//			i = T.begin();
	//			cout << "Now DC: " << *this << endl;
	//			cout << endl;
	//		}
	//		else {
	//			j++;
	//		}
	//	}
	//}
	// T = absorbHelper(T);
	// DC = absorbHelper(DC);
}

void TCube::addCube(const Cube& cube) {
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
		if (cubeDimension != res.getDimension()) {
			cout << "立方体集合中每个立方体的维度是:" << cubeDimension << endl;
			cout << "而立方体" << cube << "的维度是" << cube.getDimension() << endl;
			exit(-1);
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

bool TCube::judgeContain(Cube& cube) {
	for (Cube tempCube : T) {
		if (tempCube.judgeContain(cube)) {
			return true;
		}
	}
	return false;
}

bool TCube::judgeContain(TCube& otherTCube) {
	for (Cube tempCube : otherTCube.T) {
		if (!judgeContain(tempCube)) {
			return false;
		}
	}
	return true;
}

TCube TCube::crossCube(const Cube& cube) {
	TCube result = nullTCube;
	for (Cube indexCube : T) {
		Cube temp = indexCube.crossCube(cube);
		result += temp;
	}
	result.absorb();
	return result;
}

TCube TCube::crossCube(TCube& otherTCube) {
	TCube result = nullTCube;
	for (Cube indexCube : T) {
		result += otherTCube.crossCube(indexCube);
	}
	return result;
}

TCube& TCube::operator=(const TCube& otherTCube) {
	T = otherTCube.T;
	size = otherTCube.size;
	DC = otherTCube.DC;
	dcSize = otherTCube.dcSize;
	cubeDimension = otherTCube.cubeDimension;
	return *this;
}

TCube TCube::operator+(const TCube& otherTCube) {
	TCube temp = *this;
	for (Cube tempCube : otherTCube.T) {
		temp.addCube(tempCube);
	}

	return temp;
}

TCube TCube::operator+(const Cube& cube) {
	TCube temp = *this;
	temp.addCube(cube);
	return temp;
}

TCube& TCube::operator+=(const Cube& cube) {
	*this = *this + cube;
	return *this;
}

TCube& TCube::operator+=(const TCube& otherTCube) {
	*this = *this + otherTCube;
	return *this;
}

TCube TCube::operator*(const TCube& otherTCube) {
	TCube result = nullTCube;
	for (Cube indexCube : T) {
		result += indexCube * otherTCube;
	}
	return result;
}

TCube& TCube::operator*=(const TCube& otherTCube) {
	*this = *this * otherTCube;
	return *this;
}

TCube TCube::operator*(const Cube& otherCube) {
	TCube result = nullTCube;
	for (Cube indexCube : T) {
		result += indexCube * otherCube;
	}
	return result;
}

TCube& TCube::operator*=(const Cube& otherCube) {
	*this = *this * otherCube;
	return *this;
}