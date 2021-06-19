#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graphs{
    private:
        int V,E;
        unordered_map<T , list<T> >adj;
    public:
        void get(int , int );
        void add_edge(T, T,bool bidir = false);
        void print();
};

template<typename T>
void Graphs<T>::get(int v, int e){
    V = v, E= e;
}

template<typename T>
void Graphs<T>::add_edge(T u, T v,bool bidir){
    adj[u].push_back(v);
    if(bidir)
    adj[v].push_back(u);
}

template<typename T>
void Graphs<T>::print(){
   for(auto row : adj){
       cout<<row.first;
       for(auto el : row.second){
           cout<<"---->"<<el;
       }
       cout<<endl;
   }


    // we can't use for loop as below because the type of map and list is generic .

   /* unordered_map<T,list<T>>::iterator i;                          
   for(i = adj.begin(); i != adj.end(); i++){
       cout<<(*i).first;
       for(list<int>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++)
       cout<<"---->"<<(*j);
       cout<<endl;
   } */
}

int main(){
    Graphs<int> g;

    g.add_edge(2,3,true);
    g.add_edge(1,3, true);
    g.add_edge(2,5, true);
    cout<<"print\n";
    g.print();

}