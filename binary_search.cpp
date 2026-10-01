#include <bits/stdc++.h>

using namespace std;

int search(int arr[], int beg, int end, int item)
{
    if (beg > end) {
        return -1;
    }

    int mid = (beg + end) / 2;

    if (arr[mid] == item) {
        return mid;
    }

    if (item < arr[mid]) {
        return search(arr, beg, mid - 1, item);
    }

    return search(arr, mid + 1, end, item);
}

int main()
{
    int n;

    cout << "Enter the size of array: "<<endl;
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be a positive integer"<<endl;
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter " << n << " elements in sorted order: "<<endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int item;

    cout << "Enter element to search for: "<<endl;
    cin >> item;

    int loc = search(arr, 0, n - 1, item);

    if (loc == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index " << loc << endl;
    }

    delete[] arr;

    return 0;
}