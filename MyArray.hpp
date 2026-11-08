#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
	string name;
	int age;
public:
	Person(string a = "0", int b = 0) {
		name = a;
		age = b;
	}
	friend ostream& operator<<(ostream& os, Person& a) {
		os << "Name is: " << a.name << ' ' << "Age is: " << a.age << endl;
		return os;
	}
};

template<typename T>
class MyArray {
	T* arr;
	int size;
	int capacity;
public:
	MyArray(int c = 1) {
		this->capacity = c;
		this->size = 0;
		this->arr = new T[this->capacity];
		//cout << "调用有参构造函数" << endl;
	}

	MyArray(const MyArray& a) {
		this->size = a.size;
		this->capacity = a.capacity;
		this->arr = new T[a.capacity];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = a.arr[i];
		}
	}

	//operator= 防止浅拷贝
	MyArray operator=(const MyArray& a) {
		if (this->arr != nullptr) {
			delete[] this->arr;
		}
		this->arr = new T[a.capacity];
		this->size = a.size;
		this->capacity = a.capacity;
		for (int i = 0; i < a.size; i++) {
			this->arr[i] = a.arr[i];
		}
	}

	//尾插法
	void Push_Back(const T& a) {
		if (this->size <= this->capacity) {
			T* newarr = new T[this->size + 1];
			this->capacity++;
			for (int i = 0; i < this->size; i++) {
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
		}
		this->arr[size] = a;
		this->size++;
	}

	//尾删法
	void Pop_Back() {
		//这个if其实我没想到
		if (this->size == 0) {
			return;
		}
		//"障眼法"
		this->size--;
	}

	T& operator[] (int a) {
		return arr[a];
	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return capacity;
	}

	~MyArray() {
		if (arr != nullptr) {
			delete[] arr;
		}
		arr = nullptr;
	}



};
