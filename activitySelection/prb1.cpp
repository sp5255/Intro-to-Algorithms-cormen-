#include<iostream>
#include<vector>
using namespace std;
class activity_selection{
    private:
        vector<int>s,f;                                             //contain startng time and finishing time of respective activities
        int n;
    public:
        void getdata();    
        vector<int> activitySelector();
        void display(vector<int>);
};

void activity_selection::getdata(){
    cout<<"enter the no. of activiies\n";
    cin>>n;
    int st;
    int fn;
    cout<<"enter the starting time and finishing time of activities in increasing order of finishing time\n";
    for(int i = 0; i < n; i++){
        
        cout<<"\nenter "<<i+1<<" activity details\n";
        cout<<"starting time\n";
        cin>>st;
        s.push_back(st);
        cout<<"finishing time\n";
        cin>>fn;
        while(fn < st){
            cout<<"finishing time should be greater than the starting time of the same activity. So please enter the finishing time again\n";
            cin>>fn;
        }
        f.push_back(fn);

    }
}

vector<int> activity_selection::activitySelector(){
    int k = 0;                                                // assign first activity to the variable
    vector<int> activiesSet;    
    activiesSet.push_back(0);                               // push first activity i.e, making a greedy choice

    for(int i = 1; i < s.size(); i++){                       // at the first iteration find activity compatible with the first activity
        if(s[i] > f[k]){                                    // find  compatible activities
            activiesSet.push_back(i);
            k = i;                                          // assign latest compatible activity then find the compatible activity with latest one
        }
    }
    return activiesSet;
}

void activity_selection::display(vector<int> v){
    for(auto el : v){

        cout<<el+1<<"\t";
    }
}

int main(){
    vector<int>res;
    activity_selection a;
    
    a.getdata();
    res = a.activitySelector();
    a.display(res);

    return 0;
}