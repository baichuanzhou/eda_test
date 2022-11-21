#pragma once
#include "utils.h"
#include <iostream>

// 将 + 定义为吸收
// # 定义为锐积
// & 定义为并

extern Cube nullCube;
extern TCube nullTCube;

vector<string> strip(string src, string delim) {
	vector<string> result;
	size_t pos = 0;
	while ((pos = src.find(delim)) != string::npos) {

		result.push_back(src.substr(0, pos));

		src.erase(0, pos + delim.length());
	}
	result.push_back(src);
	return result;
}

void checkChar(string line) {
	for (int i = 0; i < line.size(); i++) {
		char ch = line[i];
		if (ch != '+' && ch != '#' && ch != '&' && ch != ','
			&& ch != '{' && ch != '}' && ch != ' '
			&& ch != '1' && ch != '0' && ch != 'x') {
			cout << "合法的符号为:" << endl;
			cout << "+ # * & 1 0 x { } ," << endl;
			cout << "你的符号为:" << ch << endl;
			exit(-1);
		}
	}
}

void checkBrackets(string line) {
	stack<char> brackets;
	for (int i = 0; i < line.size(); i++) {
		char ch = line[i];
		if (ch == '{') {
			if (line.substr(i).find('}') == string::npos || line.substr(i + 1).find('}') > line.substr(i + 1).find('{')) {
				cout << "在位置" << i << "的" << line[i] << "不匹配" << endl;
				exit(-1);
			}
			brackets.push('{');
		}
		if (ch == '}') {
			if (brackets.empty() || brackets.top() != '{') {
				cout << "在位置" << i << "的" << line[i] << "不匹配" << endl;
				exit(-1);
			}
			brackets.pop();
		}
	}
}

void checkLegal(string line) {
	checkChar(line);
	checkBrackets(line);
}

TCube extractTCube(string line) {
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '{' || line[i] == '}') {
			line[i] = ' ';
		}
	}
	TCube newT = nullTCube;
	vector<string> cubes = strip(line, " ");
	for (string cube : cubes) {
		newT += Cube(cube);
	}
	return newT;
}

vector<int> findOpPositions(string line) {
	vector<int> opPositions;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '+')
			opPositions.push_back(i);
		else if (line[i] == '#')
			opPositions.push_back(i);
		else if (line[i] == '&')
			opPositions.push_back(i);
	}
	return opPositions;
}

TCube evaluate(string line) {
	
	vector<int> opPositions = findOpPositions(line);
	vector<TCube> TCubeLine;
	if (opPositions.empty()) {
		return extractTCube(line);
	}
	TCube newTCube = extractTCube(line.substr(0, opPositions[0]));
	TCubeLine.push_back(newTCube);
	for (int i = 1; i < opPositions.size(); i++) {
		if (opPositions[i]) {
			string TCubeString = line.substr(opPositions[i - 1] + 1, opPositions[i] - opPositions[i - 1] - 1);
			TCube newTCube = extractTCube(TCubeString);
			TCubeLine.push_back(newTCube);
		}
	}
	TCubeLine.push_back(extractTCube(line.substr(opPositions[opPositions.size() - 1] + 1)));
	TCube res = TCubeLine[0];
	int count = 1;
	for(int i = 0; i < opPositions.size(); i++) {
		TCube currentT = TCubeLine[count++];
		if (line[opPositions[i]] == '+') {
			res += currentT;
		}
		else if (line[opPositions[i]] == '#') {
			res *= currentT;
		}
		else if (line[opPositions[i]] == '&') {
			res = res.crossCube(currentT);
		}
	}
	return res;
}


bool getTruth(string line) {
	vector<string> cubeStrings = strip(line, "contains");
	if (cubeStrings.size() != 2) {
		cout << "判断数输入有误" << endl;
		exit(-1);
	}
	TCube one = extractTCube(cubeStrings[0]);
	TCube two = extractTCube(cubeStrings[1]);
	return one.judgeContain(two);
}