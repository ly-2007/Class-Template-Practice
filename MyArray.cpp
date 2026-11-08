#include<iostream>
using namespace std;
#include"MyArray.hpp"

template<typename T>
void test1() {
	MyArray<int> arr(5);
	for (int i = 0; i < 5; i++) {
		T a;
		cin >> a;
		arr.Push_Back(a);
	}

	cout << "arr[1] = " << arr[1] << endl;
}


void test2() {
	int n;
	int N = 3;
	MyArray<Person> marr(N);
	string a;
	for (int i = 0; i < N; i++) {
		cout << "please cin name: ";
		cin >> a;
		cout << "please cin age: ";
		cin >> n;
		marr.Push_Back(Person(a, n));
	}

	cout << "show the marr" << endl;
	for (int i = 0; i < N; i++) {
		cout << marr[i];
	}
}

int main() {

	//	test1<int>();


	test2();

	system("pause");
	return 0;
}