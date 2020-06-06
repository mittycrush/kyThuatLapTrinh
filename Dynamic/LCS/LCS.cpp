#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L[100][100];

void init(string& s);
//longest common substring
int longestSubstring(string X, string Y);
void tracing(string X, string Y);

int main() {
    string X, Y;
    init(X);
    init(Y);
    int result = longestSubstring(X, Y);
    cout << result << endl;
    tracing(X, Y);
}

void init(string& s) {
    getline(cin, s);
}
void tracing(string X, string Y) {
    int i = X.length() - 1;
    int j = Y.length() - 1;
    string lcs;
    while (i >= 0 && j >= 0) {
        if (X[i] == Y[j]) {
            lcs.push_back(X[i]);
            i--;
            j--;
        }
        else {
            if (L[i - 1][j] > L[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
}
int longestSubstring(string X, string Y) {
    int n1 = X.length();
    int n2 = Y.length();
    int re = 0;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            }
            else {
                if (X[i] == Y[j]) {
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
    }
    return L[n1][n2];
}
