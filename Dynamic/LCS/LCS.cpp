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
    int m = X.length();
    int n = Y.length();
    string lcs;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (X[i] == Y[j]) {
            lcs.push_back(X[i]);
            i++;
            j++;
        }
        else {
            if (L[i + 1][j] > L[i][j + 1])
                i++;
            else
                j++;
        }
    }
    cout << lcs;
}
int longestSubstring(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    for (int i = m; i >= 0; i--)
        for (int j = n; j >= 0; j--)
        {
            if (X[i] == '\0' || Y[j] == '\0') 
                L[i][j] = 0;
            else if (X[i] == Y[j]) 
                L[i][j] = 1 + L[i + 1][j + 1];
            else L[i][j] = max(L[i + 1][j], L[i][j + 1]);
        }
    return L[0][0];
}
