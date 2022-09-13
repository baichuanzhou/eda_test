#include "Contain.h"


void JudgeContain(char* child, char* parent){
	if (strlen(child) != strlen(parent)){
		cout << "不在一个维度上:(!" << endl;
		return;
	}
	int common_len = strlen(child);
	for (int i = 0; i < common_len; i++)
		if (child[i] != parent[i]){
			if (!Judge(child[i], parent[i])){
				cout << child << " !=> " << parent << endl;
				return;
			}
		}
	cout << child << " => " << parent << endl;
}

bool Judge(char child, char parent){
	if (parent == 'x')
		return true;
	return false;
}
