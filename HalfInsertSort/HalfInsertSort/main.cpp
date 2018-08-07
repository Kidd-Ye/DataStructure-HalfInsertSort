//
//  main.cpp
//  HalfInsertSort
//
//  Created by kidd on 2018/8/7.
//  Copyright © 2018年 Kidd. All rights reserved.
//  折半插入排序在查找上比直接插入排序减少了次数，但是元素的移动次数没有改变
//  时间复杂度O(n^2)

#include <iostream>
using namespace std;

void HalfInsertSort(int arr[], int length){
    int i,j,low,high,mid;
    for (i=2; i<=length; i++) {
        arr[0] = arr[i];
        low = 1;
        high = i-1;
        while (low<=high) {
            mid = (low+high)/2;
            if (arr[mid] > arr[0]) {
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        for (j=i-1; j>=high+1; --j) {
            arr[j+1] = arr[j];
        }
        arr[high+1] = arr[0];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, HalfInsertSort!\n";
    
    int arr[] = {0,88,23,45,2,12,46,31,7,9,10};
    int length = sizeof(arr)/sizeof(*arr);
    HalfInsertSort(arr, length-1);
    for (int i=1; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
