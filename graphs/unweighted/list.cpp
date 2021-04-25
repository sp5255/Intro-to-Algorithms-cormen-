#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    private:
        int V, E;
        
        list<int> *adj;
        Graph *G;

    public:
        void get();
        void print();
};

void Graph::get(){
    G = new Graph();
    cout << "enter no. of vertices and edges\n";
    cin >> G->V >> G->E;

    G->adj = new list<int>[G->V];
    for (int i = 0; i < G->V; i++){
        G->adj[i].push_back(i);
    }

    cout << "enter edges\n";
    int u, v;

    for (int i = 0; i < G->E; i++)
    {
        cout << "enter edge " << i + 1<<endl;
        cin >> u >> v;
        if (u < G->V && v<G->V)
            G->adj[u].push_back(v);
            else{
                cout << "Vertex range of the edge is out of graph\n";
                exit(1);
            }
            //   G->adj[v].push_back(u);            // use for undirected graph
    }

    
}

void Graph::print(){
    for (int i = 0; i < G->V; i++){
        for (auto j = G->adj[i].begin(); j != G->adj[i].end(); j++){
            cout << *j;
            auto e = j;
            if (++e != G->adj[i].end())
            {
                cout << "\t----> ";
            }
        }
            cout << endl;
    }

    //delete (G->adj);              // after print the list it shows segmentation fault
    delete (G);
}

int main(){
    Graph g;
    g.get();
    cout << "\n********** print Graph *************\n\n";
    g.print();
    return 0;
}