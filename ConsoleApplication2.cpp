#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void matrix_reader(string file, int arr[][100], int &cols, int &rows) {
    ifstream input(file);
    string line;
    // Dòng này bỏ qua tên ma trận, đọc tên ma trận làm gì đâu :(((
    getline(input, line);
    // Đọc lần lượt từng dòng còn lại
    /*int rows, cols;*/ // Khai báo chỉ số hàng, cột
    // Vòng for này sẽ tăng dần chỉ số hàng
    for (rows = 0; getline(input, line); ++rows)
    {
        string element = "";
        cols = 0; // Bắt đầu mỗi hàng, cho chỉ số cột khởi tạo = 0
        for (int t = 0; t < line.length(); ++t) {
            if (line[t] != ' ') {
                // Nếu ký tự hiện tại khác dấu cách => nối vào biến element
                element += line[t];
            }
            // Nếu ký tự hiện tại là dấu cách, hoặc là ký tự cuối của hàng
            if (line[t] == ' ' || t == line.length() - 1) {
                // Thực hiện chuyển string thành số int dùng hàm atoi
                // Hàm atoi nhận vào biến kiểu char*, nên cần dùng .c_str() để chuyển từ string về char*
                arr[rows][cols] = atoi(element.c_str());
                // Tăng chỉ số cột
                cols++;
                // Đặt lại giá trị element
                element = "";
            }
        }
    }
        
}
void NhapFile(int arr[][10], int& row, int& col) {
    FILE* fi;
    fi = fopen("input.txt", "rt");
    if (fi == NULL)
        printf("Khong doc duoc File!");
    else {
        fscanf(fi, "%d%d", &row, &col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                fscanf(fi, "%d", &arr[i][j]);
        fclose(fi);
    }
}
int main()
{
	/*fstream f;
	f.open("input.txt", ios::in);

	string data;
	int array[100];
	int row = 0, col =0;
	string line;
	while (!f.eof())
	{
		getline(f, line);
		cout << line << endl;
	}

	f.close();*/

    int arr[10][10];
    int col, row;
    //matrix_reader("input.txt", arr, col, row);
    NhapFile(arr, row, col);
	for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
	}
}