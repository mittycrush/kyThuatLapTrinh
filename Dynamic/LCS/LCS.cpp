#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void init(string& s);
//longest common substring
int longestSubstring(string X, string Y);

int main() {
    string X, Y;
    init(X);
    init(Y);
    int result = longestSubstring(X, Y);
    cout << result << endl << gen;
}
void init(string& s) {
    getline(cin, s);
}

int longestSubstring(string X, string Y) {
    int L[100][100] = { 0 };
    int n1 = X.length();
    int n2 = Y.length();
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            }
            else {
                if (X[i] == Y[j]) {
                    addToGeneral(X[i]);
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
    }
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    return L[n1][n2];
}
