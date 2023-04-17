#include <iostream>

using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 5, 3, 8, 4, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 4;
    int index = sequentialSearch(arr, n, x);
    if(index == -1) {
        cout << "Element not found";
    } else {
        cout << "Element found at index: " << index << endl;
    }
    return 0;
}