#include "utils.h"

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