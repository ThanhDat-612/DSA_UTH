#include "Array.h"

Array::Array(int n) {
	this->size = n;
	data = new int[size];
}
Array::~Array() {
	delete data;
}
Array::Array(const Array& other) {
	size = other.size;
	data = new int[size];

	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}
void Array::input() {
	for (int i = 0;i < size;i++) {
		cin >> data[i];
	}
}

void Array::print() {
	for (int i = 0;i < size;i++) {
		cout << data[i] << " ";
	}
	cout << "\n";
}
void Array::swap(int &a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Array::sort(bool b) {
	for (int i = 0;i < size;i++) {
		for (int j = i+1;j < size-1;j++) {
			if (b == 1) {
				if (data[i] < data[j]) swap(data[i], data[j]);
			}
			else {
				if (data[i] > data[j]) swap(data[i], data[j]);
			}
		}
	}
}
int Array::countElm() {
	int count = 0;
	Array temp(size);
	for (int i = 0; i < size; i++) {
		temp.data[i] = data[i];
	}
	temp.sort(1);
	for (int i = 0;i < temp.size - 1;i++) {
		if (temp.data[i] != temp.data[i + 1]) {
			count++;
		}
	}
	return count+1;
}