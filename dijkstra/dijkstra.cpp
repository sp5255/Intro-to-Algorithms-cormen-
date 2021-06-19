
//incomplete  dijkstra

#include<iostream>
#include<list>
#include<vector>
#include<queue>
#define INFINITY 999999
using namespace std;

class Graphs{
    private:
        int V, E;
        list<pair<int,int>> *adj;
        vector<int> distance;

    public:
        void initGraph(int,int);
        void addEdge(int , int,int);
        void printList();
        void initialisation(int);
        void dijkstra(int );
};

class compare {
    public: 
        bool operator() (int a, int b){
            return a > b;                   // min priority queue
        }
};

void Graphs::initGraph(int v ,int e){
    V = v,E = e;
    adj = new list<pair<int,int>>[V];
}

void Graphs::addEdge(int u, int v,int w ){
    if(u >= V || v >= V){
        cout<<"no such vertex exist in graph to make  an edge\n";
        exit(1);
    }
    adj[u].push_back(make_pair(v,w));
}

void Graphs::printList(){
    for(int i = 0; i < V; i++){
        cout<<i<<"   :   ";
        for(auto j = adj[i].begin(); j != adj[i].end(); j++){
            cout<<(*j).first<<" ("<<(*j).second<<")"<<" ----> ";
        }
        cout<<endl;
    }
}

void Graphs::initialisation(int src){

    for(int i = 0; i < V; i++){
        distance.push_back(INFINITY);
    }
    distance[src] = 0;
}

void Graphs::dijkstra(int src){
    vector<int> s;
    initialisation(src);
    priority_queue<int, vector<int>, compare>q;

    for(int i = 0; i < V; i++)
    q.push(distance[i]);


    while(not q.empty()){

    }

}


int main(){
    Graphs g;
    int v, e;
    cout<<"enter the no. of vertices and edges of the graphs\n";
    cin>>v>>e;
    g.initGraph(v,e);
    int u,x,w;
    for(int i = 0; i < e; i++){
        cout<<"Enter Edge "<<i+1<<endl;
        cin>>u>>x;
        cout<<"enter weight\n";
        cin>>w;
        g.addEdge(u,x,w);
    }
    g.printList();
    int src;
    cout<<"Enter source \n";
    cin>>src;
    cout<<"q\n";
    g.dijkstra(src);

    return 0;
}