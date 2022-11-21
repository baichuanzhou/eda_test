#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "cube.h"

using namespace std;

class Cube;
class TCube;

vector<string> strip(string src, string delim = " ");
void checkBrackets(string line);
void checkChar(string line);
void checkLegal(string line);
bool getTruth(string line);
TCube extractTCube(string line);
vector<int> findOpPositions(string line);
TCube evaluate(string line);
#endif