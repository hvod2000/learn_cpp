#include <bits/stdc++.h>
using namespace std;

template<typename T>
void f(T obj) {
	cout << "General f() was called with " << obj << endl;
}

template<>
void f<int*>(int *ptr) {
	cout <<  "Specific f() was called with " << ptr << endl;
}

int main() {
	int x = 5;
	f(x);
	f(&x);
}
