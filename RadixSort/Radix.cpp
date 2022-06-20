#include "Radix.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Radix::Radix() {
	ifstream input;
	cout << "Reading from file...\n\n";

	input.open("twenty.txt");
	input >> num;
	arr = new int[num];
	for (int i = 0; i < num; i++)
		input >> arr[i];
	input.close();

	for (int i = 0; i < num; i++)
		cout << arr[i] << endl;

	cout << "\nCalculating...\n";

	radixSort(3, 10);
}

void Radix::radixSort(int d, int BASE) {
	int div = 1;
	vector<int> buffer(num);

	for (int x = 1; x <= d; x++) {
		vector<int> count(BASE);

		for (int i = 0; i < num; i++)
			count[(arr[i] / div) % BASE]++;
		for (int j = 1; j < BASE; j++)
			count[j] += count[j - 1];
		for (int i = num - 1; i >= 0; i--) {
			buffer[-1 + count[(arr[i] / div) % BASE]] = arr[i];
			count[(arr[i] / div) % BASE]--;
		}
		for (int i = 0; i < num; i++)
			arr[i] = buffer[i];
		div *= BASE;
	}
}

void Radix::print() {
	cout << "\nAfter Radix Sort\n\n";

	for (int i = 0; i < num; i++)
		cout << arr[i] << endl;
}