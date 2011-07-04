#include <iostream>
#include <cstdlib>

using namespace std;

int hash(int key) {
	int a,b,c,d;
	int acum = 0;
	a = (key & 0x000000FF) >> 0;
	b = (key & 0x0000FF00) >> 8;
	c = (key & 0x00FF0000) >> 16;
	d = (key & 0xFF000000) >> 24;

	acum += a * b;
	acum += b * c;
	acum += (c * d);

	return acum % 16;
}

int main() {
	int n;

	cin >> n;

	for(int i=0; i<n; i++) {
		int key = rand();
		cout << hash(key) << endl << key << endl; 
	}
}
	
