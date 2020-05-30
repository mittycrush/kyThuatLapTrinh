# **Longest Increases Of The Subset**
> Finding the longest increases of the the subset by dynamic
1. **Input**
* A list of N integer (1 <= N <= 30000). Finding the amount of LIS and print LIS.
* Init: 
    * The first line contains an integer N.
    * The second line contains N numbers describing the range.
* Example: 
    * Input: 
    ```
    10
    9 1 2 4 7 5 2 5 6 8
    ```
    * Output:
    ```
    5
    1 2 4 5 6 8
    ```
2. Concept
* In other words, the LIS of A is a sequence A ![A(i)](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn.png)
* Formula:
> Call F(i) is the longest series of increments ending in A[i], we have the formula
* ![formula](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn%20(1).png)
* With ![dk](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn%20(3).png) and ![dk1](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn%20(4).png)

### Following the original algorithm
> Complexity time is ![complex](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn%20(2).png) 
### Source code C++
``` C++
int longestSubset(int n) {
	int result = 0;
	// Create flag as the last element
    // If you want use this way, can try way below
	A[n] = MAX;
	int res = 0;
	for (int i = 0; i <= n; i++) {
		L[i] = 1;
        // int j = 0;
		for (int j = 0; j < i; j++)
			if (L[j] + 1 > L[i] && A[i] > A[j]) 
                L[i] = L[j] + 1;
		//if (L[i] > res) res = L[i];
	}
	//return res;
	return L[n];  //Return this way, must minus 1.  
    //Because the flag is in the last and appears in the result
}
```
### **Improved by using Binary Search**
> Concept: 
* We will have array B with the meaning:
B[k] is the ending value of a subset increasing the length k (at the time being calculated).
* Declare vector F, with all ![F](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn(5).png)
* Browse from ![N](https://github.com/phuocVu-IT/kyThuatLapTrinh/blob/master/Dynamic/LIS/Formal/CodeCogsEqn(6).png), with every element a[i]
* The lower_bound function finds the position k is the element F [k]&gt; = a [i]
* Assign F [k] = a [i]
* The longest series is the last k position that F [k] != MAX
        
