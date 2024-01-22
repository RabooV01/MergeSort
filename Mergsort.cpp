#include<iostream>
using namespace std;
int arr[] = {5,4,7,2,12,9,1};
void merg(int lower,int mid, int higher){
    int index = lower;
    int tempArr[(int)1e5];
    int leftptr = lower, rightptr = mid;
    while(leftptr < mid && rightptr <= higher){
        if(arr[leftptr] < arr[rightptr]){
            tempArr[index++] = arr[leftptr++];
        }
        else {
            tempArr[index++] = arr[rightptr++];
        }
    }
    while(rightptr <= higher)
        tempArr[index++] = arr[rightptr++];
    while(leftptr < mid){
        tempArr[index++] = arr[leftptr++];
    }
    for(int i = lower; i <= higher; i++){
        arr[i] = tempArr[i];
    }
}
void mergesort(int left, int right){
    if(right - left == 0)
        return;
    cout << "BEFORE:\n" << "Left = " << left << " Right = " << right << endl;
    for(int i = 0; i < sizeof(arr)/4; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    int mid = (left+right)/2;
    mergesort(left,mid);
    mergesort(mid+1,right);
    merg(left,mid+1,right);
    cout << "AFTER:\n" << "Left = " << left << " Right = " << right << endl;
    for(int i = 0; i < sizeof(arr)/4; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main () {
    mergesort(0,6);
    return 0;
}