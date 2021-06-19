#include<iostream>
#include<queue>
#include<vector>

class compare{
  public:
    bool operator() (int a, int b){
      return a > b;
    }
};

int main(){

  std::priority_queue<int, std::vector<int>,compare> q;
  std::vector<int>v;
  for(int i = 0; i < 5; i++){
    v.push_back(9999);
    q.push(9999);
  }
  q.push(0);

std::cout<<"q\n";
  for(int i = 0; i < 6; i++){

  std::cout<<q.top()<<"\t";
  q.pop();

  }

}