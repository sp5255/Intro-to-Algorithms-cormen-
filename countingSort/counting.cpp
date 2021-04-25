
// make it general 

#include<iostream>
#include<vector>
using namespace std;
class CountingSort{
    private:
        vector<int> data;        
        int size;
        
    public:
        void get();
        vector<int> countSort();
        void show(vector<int>);
};

void CountingSort::get(){
    //cin>>this->size;    
    int el;
    data = {9,3,10,4,7,3,6,3,6,2};

    size = sizeof(data)/sizeof(int);
    /* for(int i = 0; i< size; i++){
        //cin>>el;
        data.push_back(el);
    } */
}

vector<int> CountingSort::countSort(){
    vector<int> count;
    int max = data[0];
    for(int i = 0; i < data.size(); i++){

        if(data[i] > max)
            max = data[i];                    
    }

    for(int i = 0; i <=max; i++){
        count.push_back(0);
    }

    // stores the frequency of the elements

    for(int i = 0; i < data.size(); i++){

        count[data[i]] += 1;
        //count[data[i]-1] += 1;              // we can use count[data[i]] instead count[data[i] -1]  but mostly it gives an extra element of value 0 at 0th index
    }


/* cout<<"\n count \t";

for(int el: count){
    cout<<el<<"\t";
}
 */

    // commulative sum 

    for(int  i= 1;  i< count.size(); i++){
        count[i] += count[i-1];

    }

/* cout<<"\ncomm count \t";

for(int el: count){
    cout<<el<<"\t";
}
    cout<<endl;
    
 */

    // output vector  one more than given array

    vector<int> out(data.size()+1);           // if we don't use -1 at indexes as above than we have to use "  data.size()+1  "

    // data = {8,7,3,6,1};
    
    // what the vlaue of data[i] look at that index inside the latest count  i.e, holds the commulative sum
    // then see that value on that index of count and then 
    // use that value as an index of output( out ) array and store the value of data[i] at that index in out araay

    for(int i = data.size()-1; i >=0 ; i--){
        
        
        //out[count[data[i]-1]-1] = data[i];          // we can replace -1 at indexes ,  above reason for use
        //count[data[i]-1] -= 1;                      // same here " " " " " " " "

        out[count[data[i]]] = data[i];
        count[data[i]] -= 1;
    }

return out;
}


void CountingSort::show(vector<int> out){
    for(int i = 1; i < out.size(); i++){
        cout<<out[i]<<"\t";
    }
    /* for(int el : out){
        cout<<el<<"\t";
    } */
    cout<<endl;
}

int main(){
    CountingSort c;

    c.get();
    
    vector<int> res;
    res = c.countSort();

    cout<<"sorted\n";
    c.show(res);

    return 0;
}