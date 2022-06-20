#ifndef RADIX_H
#define RADIX_H

class Radix {
private:
	int* arr;
	int num;
public:
	Radix();
	void radixSort(int, int);
	void print();
};

#endif