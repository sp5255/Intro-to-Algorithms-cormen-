#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
    private:
        int V, E;
        list<int> *adj;
        Graph *G;
    public:
        void get();
        void addEdge();
        void BFS(int );
        void print();
};

void Graph::get(){
    G = new Graph();
    if(!G){
        cout << "Memory is not available\n";
        exit(1);
    }

    cout << "enter vertices and edges\n";
    cin >> G->V >> G->E;

    G->adj = new list<int>[G->V];
    for (int i = 0; i < G->V; i++){
        G->adj[i].push_back(i);
    }
}

void Graph::addEdge(){
    int src, dest;
    for (int i = 0; i < G->E; i++){
        cout << "Enter Edge " << i + 1 << endl;
        cin >> src >> dest;
        if(src < G->V && dest < G->V ){
            G->adj[src].push_back(dest);
         //   G->adj[dest].push_back(src);          // for undirected graph
        }

        else{
            cout << "Vertex range is out of graph\n";
            exit(1);
        }
    }
}

void Graph::BFS(int s){
    if(s >= G->V){
        cout << "source is not in the graph\n";
        exit(1);
    }
    queue<int> q;
    bool *visited = new bool[G->V];

    // intitally all nodes are unvisited

    for (int i = 0; i < G->V; i++){
        visited[i] = false;
    }

    // push  current vertex to the queue

    q.push(s);
    visited[s] = true;

    // repeat until all the reachable nodes is visited

    while(!q.empty()){
      s =  q.front();                   
      cout << s<<" ---- > ";                // process source 
      q.pop();                              // dequeue src from queue

      // traverse the adjacent nodes to the current src

      for (auto i = G->adj[s].begin(); i != G->adj[s].end(); i++){

          // if any adjacenct node is not visited push that to queue

          if(!visited[*i]){
              q.push(*i);
              visited[*i] = true;
          }
      }
    }
    cout << endl;
}

void Graph::print(){

    for (int i = 0; i < G->V; i++){
        for (auto j = G->adj[i].begin(); j != G->adj[i].end(); j++){
            cout<<*j;
            auto c = j;
            if (++c != G->adj[i].end()){
                cout << " \t-----> ";
            }
        }
            cout << endl;
    }
}

int main()
{
    Graph g;
    g.get();
    g.addEdge();
    cout << "\n*********** Adjacency List **********\n";
    g.print();
    cout << "enter the vertex in the graph range as a source \n";
    int s;
    cin >> s;
    cout << "\n ********** BFS  (Print Graph) **********\n\n";
    g.BFS(s);

    return 0;
}