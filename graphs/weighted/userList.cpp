#include<iostream>
using namespace std;

template<typename T>
class LinkedList{
    private:
        T vertex;
        int weight;
        LinkedList *head = nullptr, *next, *tail;
    public:
        //void createNode();
        void push(T, int);
        void printList();
};

template<typename T>
void LinkedList<T>::push(T v, int w){
    
    LinkedList *temp = new LinkedList;
    temp->vertex = v;
    temp->weight = w;

    if (!head)
    {
        head = temp;
        tail = head;
        tail->next = nullptr;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
    }
}

template <typename T>
void LinkedList<T>::printList(){
    LinkedList *temp = head;
    while(temp){
        cout << "vertex : " << temp->vertex << "   weight : " << temp->weight;
        temp = temp->next;
        if(temp)
            cout << " ----> ";
    }
    cout << endl;
}


class Graph{
    private:
        int V, E, W;
        LinkedList<int> *adj;
        Graph *G;
    public:
        void get();
        void addEdge();
        void print();
};


void Graph::get(){
    G = new Graph;

    cout << "enter no.of vertices and edges\n";
    cin >> G->V >> G->E;

    G->adj = new LinkedList<int>[G->V];
    for (int i = 0; i < G->V; i++){
        G->adj[i].push(i,0);
    }
}


void Graph::addEdge(){
    int s,d, w;
    cout << "Enter edges\n";
    for (int i = 0; i < G->E; i++){
        cout << "Enter Edge " << i + 1 << endl;
        cin >> s >> d;
        cout << "Enter weight\n";
        cin >> w;
        G->adj[s].push(d, w);
    }
}

void Graph::print(){
    for (int i = 0; i < G->V; i++){
        G->adj[i].printList();
    }
}

int main()
{
    /* LinkedList<char> l;
    l.push('a', 2);
    l.push('e', 5);
    l.push('q', 1);
    l.push('n', 23);
     */

    Graph g;
    g.get();
    g.addEdge();
    cout << "\n*********** List *************\n\n";
    g.print();
    /* 
    cout << "print\n";
    l.print(); */
    cout << endl;
    return 0;
}
