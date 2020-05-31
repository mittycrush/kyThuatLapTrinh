#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 99999
using namespace std;
vector<int> L;
vector<int> a;
vector<int> F;
int T[1010];

void init(int& n);
int longestSubset(int n);
int longestSublist(int n);
int BinarySearch(int n, int k);
void tracing(int k);

int main() {
	int n;
	init(n);
	cout << longestSubset(n) - 1 << endl;
	int res = longestSublist(n);
	cout << res << endl;
	tracing(res);
}

void tracing(int k) {
	int i = 0;
	for (int i = 0; i < k; ++i) {
		cout << F[i] << " ";
	}
}
void init(int& n) {
	cin >> n;
	a.resize(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}
int BinarySearch(int n, int k) {
	//Filter the first case
	if (k <= F[0]) return 0;
	if (k > F[n - 1]) return n;
	// If not, will do below
	int l = 0, r = n - 1, i = (l + r) / 2;
	while (l != i && i != r) {
		if (F[i] >= k) r = i;
		else l = i;
		i = (l + r) / 2;
	}
	for (i = l; i <= r; i++) {
		if (F[i] >= k) {
			return i;
		}
	}
	return n;
}
int longestSublist(int n) {
	F.resize(n + 1, MAX);
	int result = 0;
	for (int i = 0; i < n; ++i) {
		//int k = lower_bound(F.begin(), F.end(), a[i]) - F.begin();
		int k = BinarySearch(F.size(), a[i]);
		F[k] = a[i];
		result = max(result, k + 1);
	}
	return result;
}
int longestSubset(int n) {
	L.resize(n + 1, 0);
	int result = 0;
	a[n] = MAX;
	int res = 0;
	for (int i = 0; i <= n; i++) {
		L[i] = 1;
		int j = 0;
		for (j; j < i; j++)
			if (L[j] + 1 > L[i] && a[i] > a[j]) L[i] = L[j] + 1;
	}
	return L[n];
}
