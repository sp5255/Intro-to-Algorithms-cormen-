#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;
template<typename T>
class Graphs{
    private:
        unordered_map<T, list<T>> adj;
        string s;
        Graphs *color;
    public:
        void add_edge(T , T);
        void bfs(T);
        void print();
};

template<typename T>
void Graphs<T>::add_edge(T u, T v){
    adj[u].push_back(v);
    //adj[u]->color->s =  "white";
}

template<typename T>
void Graphs<T>::print(){
    for(auto key:adj){
        cout<<key.first<<"   :   ";
        for(auto val: key.second)
        cout<<val<<"------->";
        cout<<endl;
    }
}

int main(){
    Graphs<int>g;
    g.add_edge(4,3);
    g.add_edge(3,2);
    g.add_edge(2,3);
    g.add_edge(6,4);

    g.print();
    return 0;
}
