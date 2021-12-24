#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class FindIndeces{
    private:
        vector<int> arr;                // create the main (dyanamic array);
    public:
        void get();                     // get data form the user
        int returnInde(int key);        // find the element in  array
};
void FindIndeces::get(){
    cout << "enter the no. of elements\n";
    int n, ele;             
    cin >> n;                          // number of elements in array
    for (int i = 0; i < n; i++){
        cin >> ele;                     // element to be entered
        arr.push_back(ele);              // store elements in the main array
    }
}
int FindIndeces::returnInde(int key){

        /* sort(arr.begin(), arr.end()); */

    auto ind = find(arr.begin(), arr.end(), key);    // find the element in array

    // if found 
    if(ind != arr.end()){
        int found = ind - arr.begin();              // calulate index of found element
        return found;
    }
    // if not found
    return -1;
}
int main(){
   
    FindIndeces f;
    f.get();                            //getting data
    vector<int> keys, indeces;          // creates two arrays keys for storing key to be searched and indeces to store the found position of elements
    cout << "enter no. of keys to be serached\n";
    int k,n;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> n;
        keys.push_back(n);                  // sotring keys
    }
    for(auto &ele : keys){
        int found = f.returnInde(ele);      
        if(found >= 0)
            found += 1; 
        indeces.push_back(found);       // storing positions
    }
    cout << "Positions\n";
    
    // print positions
    
    for (int pos : indeces){
        cout << pos << " ";         
    }
    cout << endl;
}