#include <algorithm>
#include <iostream>
using namespace std;

int table(int n) {
	if (n == 255)
		return 0;
	return n + 1;
}

int h(const char* str) {
	int h;
	while (*str != 0) {
		h = table (n: h ^ *str);
		++str;
	}
	return h;
}

int h(const char* str) {
	int h;
	while (*str != 0) {
		h = h ^ *str;
		++str;
	}
	return h;
}

int main() {
	cout << h(str:"abc") << endl;
	cout << h(str:"acb") << endl;
	cout << h(str:"bac") << endl;
	cout << h(str:"bca") << endl;
	cout << h(str:"cab") << endl;
	cout << h(str:"cba") << endl;

		
}