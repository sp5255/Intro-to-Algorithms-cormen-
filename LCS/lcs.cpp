#include<iostream>
using namespace std;

class Lcs{
    private:
        string x, y;
        int **c;
        char **b;
        
    public:
        void getString(string s1, string s2);
        void subsequece();
        void print();
        void prints();
};

void Lcs::getString(string s1, string s2){
    x = s1;
    y = s2;
}

void Lcs::subsequece(){

    // allocate memory to the c (2-d dynamic array)
    // allocate memory to the b (2-d dynamic array)

    c  = new int*[x.length()+1];
    b = new char*[x.length()+1];

    for(int i = 0; i <= x.length(); i++){
        c[i] = new int[y.length()+1] ;
        b[i] = new char[y.length()+1];
    }


   /*  for(int i = 0; i < x.length(); i++){
    }
 */
    // assign 0 to the first column of the table

    for(int i = 0 ; i <= x.length(); i++){
        c[i][0] = 0;
        b[i][0] = '0';
    }
    
    // assign 0 to the first row  of the table

    for(int i = 0; i <= y.length(); i++){
        c[0][i] = 0;
        b[0][i] = '0';
    }

    // now enter the arrow type sign in b table and the number entry in c table

    for(int i = 1; i <= x.length(); i++)
    for(int j =1; j <= y.length(); j++){
      if(x[i-1] == y[j-1]){
          c[i][j] = c[i-1][j-1]+1;
          b[i][j] = '\\';
      }
      else if(c[i-1][j] >= c[i][j-1]){
          c[i][j] = c[i-1][j];
          b[i][j] = '|';
      }
      else {
          c[i][j] = c[i][j-1];
          b[i][j] = '-';
      }
    }
}

void Lcs::print(){
    for(int i = 0; i <= x.length(); i++ ){
        for(int j = 0 ; j <= y.length(); j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\n\n\nb\n\n";
      for(int i = 0; i <= x.length(); i++ ){
        for(int j = 0 ; j <= y.length(); j++){
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nsequence\n";

    
    
    int i = x.length(),j = y.length();
    string seq = "";

    while(i >0 && j > 0){
        //cout<<endl<<"enter = "<<i<<endl;

        if(b[i][j] == '|'){
            i = i-1;
        }
        else if(b[i][j] == '-'){
            j -= 1;
        }
        else if(b[i][j] == '\\'){
            seq += x[i-1];
            i -= 1;
            j -=1;

        }
        else{
            i =-1;
        }
    }
    for(int k = seq.size()-1; k >= 0; k--){
        cout<<seq[k];
    }
    cout<<endl;
}


int main(){
    string s1,s2;
    cout<<"enter two strings\n";
    cin>>s1>>s2;
cout<<"\nentered\n";
    cout<<s1<<endl<<s2;
  /* s1 = "abcbdab";
  s2 = "bdcaba"; */

    Lcs l1;
    l1.getString(s1,s2);
    l1.subsequece();
    cout<<"\noutput\n";
    l1.print();

    cout<<endl;
    return 0;

}