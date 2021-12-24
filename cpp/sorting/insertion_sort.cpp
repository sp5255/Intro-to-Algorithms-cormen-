#include<iostream>
#include<vector>
using namespace std;
void insertion(vector<int> arr) {
    for (int i = 1;i < arr.size();i++) {
        //cout << "1s5";
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "\t";   
}
int main() {
    vector<int>a;
    int n;
    cout << "number of elements\n";
    cin >> n;
    int ele;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        a.push_back(ele);
    }
    insertion(a);
}