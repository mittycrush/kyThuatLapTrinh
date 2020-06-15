# Largest Divisible Subset
> LDS
1. Input
* Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
> Si % Sj = 0 or Sj % Si = 0.
* If there are multiple solutions, return any subset is fine.
### Example:
#### Input:
```
4
3 4 16 8
```
#### Output:
```4 8 16```
2. Concept
* As you see in the output, the array is sorted !!!
> Yeah! One step to have an algorithm to solve this problem
### Main ideal: 
* To solve this, we will follow these steps −
 * Create an array ret, declare endPoint = 0, retLen = 1, n is size of nums
 * **SORT** the array
 * Create two arrays len(len of LDS on cStep) and par(storage ) of size n, initialize len by 1, and par with 0
 * for (i from 1 to n – 1, step = 1)
  * par[i] := i
  * for (j from 0 to i – 1, step = 1)
    * if (nums[i] % nums[j] == 0 and len[j] + 1 > len[i]), then
      * len[i] := len[j] + 1
      * par[i] := j
  * if (len[j] > retLen) 
    * retLen = len[i], endpoint := i
  * Insert nums[endPoint] into ret
  * while endpoint != par[endPoint]
    * endpoint := par[endPoint]
    * push nums[endPoint] into ret
* return reverse the list ret
### Source Code 
``` C++
vector<int> longestSubset(int n) {
    vector <int> res;
    int endPoint = 0;
    int resLen = 1;
    sort(nums.begin(), nums.end());
    vector <int> len(n, 1);
    vector <int> par(n, 0);
    for (int i = 1; i < n; i++) {
        par[i] = i;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && len[j] + 1 > len[i]) {
                len[i] = len[j] + 1;
                par[i] = j;
            }
        }
        if (len[i] > retLen) {
            resLen = len[i];
            endPoint = i;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
```
