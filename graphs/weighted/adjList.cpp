#include<iostream>
#include<utility>
#include<list>
#include<queue>
#include<vector>
//#include<limits>
#define INFINITY 99999
using namespace std;

class Graphs{
    private:
        int V,E;
        list<pair<int,int>> *adj;        
        vector<int> distance;
        vector<int> predecessor;
    public:
        void get();
        void addEdge();
        void printList();
        void bfs();
        void initialization(int);
        void relax(int ,int);
        bool CheckRelaxation(int ,int);
        bool Bellmon_forrd(int);
};

void Graphs::get(){
    cout<<"Enter no. Vertices and Edges\n";
    cin>>V>>E;
    adj = new list<pair<int, int>>[V];
}

void Graphs::addEdge(){
    int src,dest,w;
    for(int i = 0; i < E; i++){
        cout<<"Enter Edge "<<i+1<<endl;
        cin>>src>>dest;
        cout<<"enter wieght\n";
        cin>>w;
        if(src < V && dest < V)                                           // added later
        adj[src].push_back(make_pair(dest,w));
        else {
            cout<<"vertices out of the graph";
            exit(1);
        }
    }
}

void Graphs::printList(){
    for(int i = 0; i < V; i++){
            cout<<i<<"  :  ";
        for( list<pair<int,int>>::iterator j = adj[i].begin(); j != adj[i].end(); j++ ){
            cout<<j->first<<" ( "<<j->second<<" )";
            auto temp = j;
            if(++temp != adj[i].end())
            cout<<" ------>  ";
        }
        cout<<endl;
    }
}

void Graphs::bfs(){
    queue<pair<int,int>>q;
    vector<bool>visited;
    
    for(int i = 0; i < V; i++)
    visited.push_back(false);

    cout<<"Enter source\n";
    int s;
    cin>>s;
    q.push(make_pair(s,0));
    while(!q.empty()){
        s = q.front().first;
        int w = q.front().second;
        q.pop();
        cout<<s<<" ( "<<w<<" ) " <<" ----> ";
        visited[s] = true;
        for(auto i = adj[s].begin(); i != adj[s].end(); i++){
            if(!visited[i->first]){
                q.push(make_pair(i->first, i->second));
                visited[i->first] = true;
            }
        }
    }
    cout<<endl;
}

void Graphs::initialization(int src){
    //float f_inf = numeric_limits<float>::infinity();

    for(int i =0; i < V; i++){
        distance.push_back(INFINITY);
        predecessor.push_back(-1);
    }
    distance[src] = 0;
}

void Graphs::relax(int u,int v){
    int w;
    cout<<"\nfor "<< u<<endl;
   for(auto i = adj[u].begin(); i!= adj[u].end(); i++){
       if(i->first == v){
            w = i->second;
     //      cout<<"W ; "<<w;
           break;
       }
   }
   //cout<<"distance\n";
   for(auto el: distance){
       cout<<el<<"\t";
   }
   cout<<endl;
    if(distance[v] > (distance[u] +w)){
        distance[v] = distance[u]+w;
        predecessor[v] = u;
    }
}

bool Graphs::CheckRelaxation(int u, int v){
    int w;
    
   for(auto i = adj[u].begin(); i!= adj[u].end(); i++){
       if(i->first == v){
            w = i->second;
     //      cout<<"W ; "<<w;
           break;
       }
   }
     if(distance[v] > (distance[u] +w)){
         return true;
    }
    return false;
}

bool Graphs::Bellmon_forrd(int s){
    initialization(s);
    for(int k =0; k < V-1; k++)
    for(int i = 0; i < V; i++){
        for(auto j = adj[i].begin();  j != adj[i].end(); j++){
            relax(i, j->first);
        }
    }

     for(int i = 0; i < V-1; i++){
        for(auto j = adj[i].begin();  j  != adj[i].end(); j++){
            if(CheckRelaxation(i,j->first))
            return false;
        }
    }
    return true;
}

int main(){    
    Graphs g;
    g.get();
    g.addEdge();
    cout<<"\n*********** List ***********\n\n";
    g.printList();

    cout<<"\n\n *********** BFS ***********\n\n";
    g.bfs();
    
    //g.initialization(4);
    cout<<"enter source\n";
    int src;
    cin>>src;
    bool y = g.Bellmon_forrd(src);
    if(y)
    cout<<"\n\nok solved\n";
    if(!y)
    cout<<"\n\nnot solved! contain negative cycle";
    cout<<endl;
    return 0;
}
