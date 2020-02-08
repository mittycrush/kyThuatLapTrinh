#include <iostream>
#include<string>
#include<fstream>
#include<math.h>
using namespace std;

void matrix_Reader(int data[][10], int& row, int& col) {
	ifstream input;
	input.open("text.inp");
	string line;
	input >> row >> col;
	getline(input, line);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			input >> data[i][j];
		}
		getline(input, line);
	}
}
int main() {
	int data[10][10];
	int row, col;
	matrix_Reader(data, row, col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}