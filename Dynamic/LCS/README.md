# Longest Common Substring
> **Dynamic Programming** can be used to find the *longest common substring (LCS)*
1. **Input**
* Given that the two strings X and Y. Length X, Y <= 2000.  look for LCS of both X and Y.
* Init:
	* The first line contains string X.
	* The second line contains string Y.
* Output:
	* Length of C.
	* String C is LCS of both X and Y.
* Example: 
	* Input:
	```
	abc1def2ghi3
	abcdefghi123
	```
	* Output:
	``` 
	10
	abcdefghi3
	```
> Explanation: Length of longest common substring is 10, and it's "abcdefghi3"
2. **Concept**
> *Let L[i][j] be the longest common substring of the string X[i] consisting of i characters the first part of X and the string Y[j] consist of the first j characters of Y.*
* We have a formula dynamic programming: 
> ![Formula](https://github.com/phuocVu-IT/Programming-Techniques/blob/master/Dynamic/LCS/IMG/CodeCogsEqn.gif)
3. **Follow the original algorithm**
```C++
//longest common substring
int longestSubstring(string X, string Y) {
    int L[100][100];
    int m = X.length();
    int n = Y.length();
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
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
    return L[m][n];
}
```
### Explain
* Let m and n be the lengths of first and second strings respectively.

    A simple solution is to one by one consider all substrings of the first string and for every substring check if it's a substring in the second string. Keep check of the maximum length substring.
    When we have completed the length of two strings, the result of the longest common substring to look for is L[m][n].
* And array L will be like below *(in example)*:
> ![ARRAY](https://github.com/phuocVu-IT/Programming-Techniques/blob/master/Dynamic/LCS/IMG/output.png)

4. Complexity
* Time Complexity: O(m*n)
* Auxiliary Space: O(m*n)
> m and n be the lengths of first and second strings
5. Tracing
* The array L has stored the state the algorithm has created before. 
* To find the largest general substring from the state table, we will start from the last state (ie L[m][n]).
* Tracing status starts from L[m][n], the current state after each implementation will depend on  X[m] != Y[n] and the destination state occurs when m or n == 0
* The current state is m and n: if (X[m] == X[n]) 
	* the previous state is m - 1 and n - 1
		* will push in a string result
	* else L[m - 1][n] > L[m][n - 1] 
		* previous m--
		* or n--
* When destination state, the result will be the inverse of the result string because when tracing we start from m and n.
```C++
void tracing(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    string lcs;
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            lcs.push_back(a[i]);
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
```
