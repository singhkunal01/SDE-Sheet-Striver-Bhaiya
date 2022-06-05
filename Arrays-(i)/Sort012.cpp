#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    //   Write your code here
    int low , mid , high = n - 1;
    low = mid = 0;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1)mid++;
        else {
            swap(arr[mid], arr[high--]);
        }
    }
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01