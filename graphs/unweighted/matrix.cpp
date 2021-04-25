
//  adjacency matrix representation for unweighted graph

#include<iostream>

class Graph{
    private:
        int V, E;
        int **adj;
        Graph *G;
    public:
        void get();
        void addEdge();
        void print();
};

void Graph::get(){
    G = new Graph();
    std::cout << "no. of vertices and edges\n";
    std::cin >> G->V >> G->E;
    G->adj = new int*[G->V];
    for (int i = 0; i < G->V; i++){
        G->adj[i] = new int [G->V];
        for (int j = 0; j < G->V; j++){
            G->adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(){
    int u, v;
    std::cout << "enter the edge\n";
    for (int i = 0; i < G->E; i++)
    {
        std::cout << "Enter Edge " << i+1 << "\n";
        std::cin >> u >> v;
        if (u < G->V && v < G->V){
            G->adj[u][v] = 1;
            //G->adj[v][u] = 1; // for undirected graph
        }
        else{
            std::cout << "vertices range out of graph\n";
            exit(1);
        }
    }
}

void Graph::print(){
    for (int i = 0; i < G->V; i++){
        for (int j = 0; j < G->V; j++){
            std::cout << G->adj[i][j]<<"\t";
        }
        std::cout << std::endl;
    }

    delete (G->adj);
    delete (G);
}

int main(){
    Graph g;
    g.get();
    g.addEdge();
    std::cout << "\n********** print Graph ***********\n\n";
    g.print();
    return 0;
}