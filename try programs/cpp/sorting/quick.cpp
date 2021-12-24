#include<iostream>
using namespace std;

int partition(int* arr, int p, int h);
void quick(int* arr, int, int);
void swap(int*, int*);

int main() {
    int n;
    cout << "Enter nu. of elements\n";
    cin >> n;
    int* arr = new int(n);                  //dynamic array
    cout << "enter the elements\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick(arr, 0, n - 1);
    cout << "sortd\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }

}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int p, int h) {
    int pivot = arr[h];                     //consider the last element as pivot element
    int i = p - 1;
    for (int j = p; j < h; j++) {
        // if element is less than pivot than swap with the greater element found earlier
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

void quick(int* arr, int l, int h) {
    // int p;
    if (l < h) {
        int  p = partition(arr, l, h);
        quick(arr, l, p - 1);           // pass left subarray
        quick(arr, p + 1, h);           // pass right subarray
    }
}