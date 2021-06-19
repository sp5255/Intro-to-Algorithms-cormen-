#include<iostream>
#include<vector>
using namespace std;


int sockMerchant(int n, vector<int> ar) {
    int max = 0;
    for(int el : ar){
        if(el > max){
            max = el;
        }
    }
    vector<int> freq(max+1,0);
    cout<<"freq arr";
    /* for(int i = 0; i < freq.size(); i++){
        cout<<freq[i]<<" ";
    }
    cout<<endl; */

    for(int el : ar){
        cout<<"el : "<<el<<endl;
        freq[el] = ++freq[el];
        cout<<"freq : "<<freq[el]<<endl;
    }   
    /* for(int el : freq) {
        cout<<el <<" ";
    } */
    int pairs = 0;
    for(int el : freq){    
        //cout<<el<<" ";
        pairs += el/2;
    }
return pairs;
}
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    int el;
    for(int i = 0; i < n; i++){
        cin>>el;
        arr.push_back(el);
    }
    int ans = sockMerchant(n, arr);
    cout<<endl<<ans;
    return 0;
}