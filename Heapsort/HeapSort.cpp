#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Heaps
{
private:
    vector<T> data;
    int size, heapSize;

public:
    void get();
    void swap(int *, int *);
    void max_heapify(int );
    void build_max_heap();
    void heapsort();
    void show();
    int left(int);
    int right(int);
};

template <typename T>
inline int Heaps<T>::left(int i)
{
    return 2 * i + 1;
}

template <typename T>
inline int Heaps<T>::right(int i)
{
    return 2 * (i + 1);
}

template <typename T>
void Heaps<T>::swap(int *a, int *b){
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
template <typename T>
void Heaps<T>::get()
{    
    cout << "Enter the number of elements\n";
    cin >> size;
    heapSize = size;
    int el;
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
        cin >> el;
        data.push_back(el);
    }
}

template <typename T>
void Heaps<T>::max_heapify( int index)
{

    int l = left(index);
    int r = right(index);
    int largest;

    // find largest element

    if (l < heapSize && data[l] > data[index])
        largest = l;
    else
        largest = index;
    if (r < heapSize && data[r] > data[largest])
        largest = r;

    // if largest element is the index so we don't need to swap it, but if it's not the index element 
    //so we have to swap with the largest child 

    if(largest != index){
        swap(&data[largest], &data[index]);
        max_heapify(largest);                   // after swapping we have to maintain the max-heap property
    }
}

template <typename T>
void Heaps<T>::build_max_heap(){

    // elements after the size/2 are the leaf nodes of the tree so, they will automotically take their positions
    // when max-heapify will run for their parent
    
    for (int i = data.size() / 2 ; i >= 0; i--){    
        max_heapify(i);
    }
}

template <typename T>
void Heaps<T>::heapsort(){
    build_max_heap();
    for (int i = data.size() - 1; i > 0; i--){
        swap(&data[i], &data[0]);               //swap the root and the last node of heap
        heapSize -= 1;
        max_heapify(0);                         // beacuse the last node element is present at root now so we have to maintain the heap property
    }
}

template<typename T>
void Heaps<T>::show(){
    for(int el: data){
        cout << el << "\t";
    }
}

int main(){
    Heaps<int> h;
    h.get();
    h.heapsort();
    cout << "sorted array\n";
    h.show();
    cout << endl;
    return 0;
}