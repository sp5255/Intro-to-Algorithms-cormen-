// huffman code

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Hcode {
    private:
        int freq;
        char ch;
        Hcode *left, *right;        

    public:
        Hcode* buildPriorityq(char, int);        
        Hcode* build(char *, int* ,int size);              // here it uses the above class object as parameter
        void print(Hcode *,vector<int> *);

        bool chk(Hcode *a, Hcode *b){                   // uses in compare class member function
            return a->freq > b->freq;
        }
};

class compare : public Hcode{                      // overload () operator to buildi min_priority_queue(or min_heap) having priority based on the frequensy
    public:
        bool operator()(Hcode *a, Hcode *b)
        {
            return Hcode::chk( a, b);
        }
};

// create a new node and intialize its values 

Hcode* Hcode::buildPriorityq(char ch, int f){
    Hcode *node = new Hcode();
    node->ch = ch;
    node->freq = f;
    node->left = node->right = nullptr;
    return node;
}

//  here it build the tree and uses a print function to print that

Hcode* Hcode::build (char *ch,int *f, int size) {

    // buld a priority queue

    priority_queue<Hcode *, vector<Hcode *>, compare> q;

    for (int i = 0; i < size; i++){
        q.push(buildPriorityq(ch[i], f[i]));
    }

        // Huffman code Algorithm

        for (int i = 0; i < size - 1; i++)
        {
            Hcode *temp = new Hcode();              //  -- create a node
            int x = 0;
            temp->left = q.top();                   // -- pop min. from priority queue and assigm to the left of created node
            x = q.top()->freq;                      // store the frequencies of the popped node and then assign that sum to frequency of created node
            q.pop();

            temp->right = q.top();                  //  --  pop min. from priority queue and assigm to the Right of created node
            x += q.top()->freq;
            for (int i = 0; i < size; i++)
            {
                q.push(buildPriorityq(ch[i], f[i]));
            }
            q.pop();
            temp->freq = x;                         //  -- frequency of created node is = freq.first popped element + freq. of 2nd popped element
            q.push(temp);                           // then push newly created node back to the queue
        }

    return q.top();
}

// print the Huffman Codes(Tree)

void Hcode::print(Hcode *rt, vector<int> *p){
    if(rt == nullptr)
        return;

    // if it is leaf node it means that it contains the character and frequency of that character so we have to print the codes
    // this if block just print the codes

    if(!rt->left && !rt->right){
        cout << rt->ch << " : " << rt->freq;
        cout << "\t  code : \t";
        for (int el: *p){
            cout << el;        
        }
        cout << endl;
    }

    p->push_back(0);            // if it is going to left then push (0) to the vector
    print(rt->left, p);
    p->pop_back();              // pop last item from vector every time when it goes from leaf node to other non-leaf nodes

    p->push_back(1);            // when it goes to right push (1) to the vector
    print(rt->right, p);
    p->pop_back();              // then again pop item from the vector when it goes from leaf to non-leaf
}

int main(){

    Hcode h;

    int f[] = {45, 13, 12, 16, 9,5};
    char ch[] = {'a', 'b', 'c', 'd', 'e','f'};
    int size = sizeof(f) / sizeof(int);

    Hcode *r;
     r = h.build(ch, f, size);

    cout << "codes \n";
    vector<int> p;
    h.print(r,&p);

    return 0;
}