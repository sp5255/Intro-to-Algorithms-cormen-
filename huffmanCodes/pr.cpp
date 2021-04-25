
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Hnode{
    private:

    public:
        int freq;
        char ch;
        Hnode *left, *right;
       /*  Hnode(char character, int frequency){
            freq = frequency;
            ch = character;
            left = right = NULL;
        } */
        void get(char character, int frequency){
            freq = frequency;
            ch = character;
            left = right = NULL;
        }
};

class compare{
    public:
        bool operator()(Hnode *a, Hnode *b){
            return a->freq > b->freq;
        }
};

int main(){
    priority_queue<Hnode *, vector<Hnode *>, compare> pq;
    int f[] = {4, 2, 6, 1, 8};
    char ch[] = {'a', 't', 'q', 'f', 'y'};
    for (int i = 0; i < 5; i++){
        Hnode *node = new Hnode();
        node->ch = ch[i];
        node->freq = f[i];
        pq.push(node);
    }

    cout << "queue\n";
    while (!pq.empty())
    {
        cout << pq.top()->ch << ":\t";
        cout << pq.top()->freq << "\t";
        cout << endl;
        pq.pop();
    }

    cout << endl;
    return 0;
}