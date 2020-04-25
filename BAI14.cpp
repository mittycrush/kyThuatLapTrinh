#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int go[16][16] = { 0 };// luu toa do duong cua me cung

int row, col;// kich thuoc cua me cung
int minMove; // so buoc nho nhat
vector<int> way; // temp way (1 cap so la toa do x,y ma hugo di qua)
vector<int> result; 

struct Move {
	int up;
	int down;
};
// cac vi tri co the di chuyen
Move moveSet[8] = { {-1, -1}, { -1,0 }, { -1,1 }, { 0,1 }, { 1,1 }, { 1,0 }, { 1,-1 }, { 0,-1 } };

void importFromFile(int& x, int& y) {
	ifstream fi;
	fi.open("HUGO.inp");
	fi >> row >> col;
	// tao hang rao quanh matrix, :v tranh chay ra ngoai 
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			fi >> go[i][j];
		}
	}
	fi >> x >> y;
	way.push_back(x);
	way.push_back(y);
	fi.close();
}
void display(vector<int> bin) {
	bin.pop_back();
	bin.pop_back();
	// backtrack nhu shit ne phai loai di (x, y) cuoi do push_back trash :)) 
	// in ra ket qua !!!!
	int size = bin.size() / 2; // so buoc di chuyen
	int count = 0;
	cout << size << endl;
	for (auto i : bin) {
		cout << i << " ";
		count++;
		if (count == 2) {
			cout << endl;
			count = 0;
		}
	}
}
bool isOK(int x, int y) {
	return (x > row || y > col || x < 1 || y < 1);
}
void attempt(int x, int y, int& step) {
	int r_next;
	int c_next;
	if (step > 255) return; // ngan chan TH stack overflow 
	for (int i = 7; i >= 0; --i) {
		int k = go[x][y] >> i;
		if (k & 1) { // bit bi == 1 thi moi chay duoc
			// vi tri chay tiep theo
			r_next = x + moveSet[8 - i + 1].up;
			c_next = y + moveSet[8 - i + 1].down;
			// chen vi tri da chay vao way
			way.push_back(r_next);
			way.push_back(c_next);
			++step; // tang so buoc
			if (isOK(r_next, c_next)) { // chay ra ngoai === row, col roi vao hang rao
				if (step < minMove) { 
					minMove = step;
					result = way;
				}
			}
			else {
				attempt(r_next, c_next, ++step);
			}
			// xoa di toa do da chay khong ra kq
			way.pop_back();
			way.pop_back();
			step--;
		}
	}
}


int main() {
	minMove = 255;
	int step = 0;
	int x, y;
	importFromFile(x, y);
	attempt(x, y, step);
	display(result);
}
