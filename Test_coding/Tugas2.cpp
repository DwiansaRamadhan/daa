#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if(r >= l) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x) {
            return mid;
        }
        if(arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 5, 8 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    int index = binarySearch(arr, 0, n - 1, x);
    if(index == -1) {
        cout << "Element not found";
    } else {
        cout << "Element found at index: " << index << endl;
    }
    return 0;
}