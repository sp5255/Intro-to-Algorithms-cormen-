#include<iostream>
#include<vector>
using namespace std;
vector<int> merge(vector<int>a, vector<int>b) {
    for (int i = 0; i < b.size(); i++) {
        a.push_back(b[i]);
    }
    return a;
}
int main() {
    int n;
    vector<int> u;
    cout << "Enter the no. of elements in 1st array\n";
    cin >> n;
    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        u.push_back(el);
    }
    cout << "enter for 2nd \n";
    cin >> n;
    vector<int>v;
    
    for (int i = 0; i < n; i++) {
        cin >> el;
        v.push_back(el);
    }

    u = merge(u, v);
    cout << "merged\n";
       for (int i = 0; i < u.size(); i++) {
           cout << u[i]<<"\t";
       }
       cout << endl;
}