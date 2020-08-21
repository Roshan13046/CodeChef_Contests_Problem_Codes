/*
4
1
5
9
64
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,a;
  
  cin>>t;
  while(t--){
    cin>>a; 
    char arr[8][8];
    int c = 9;
    
    for(int j=0;j<8;j++){
      for(int k=0;k<8;k++){
        if(a>0){
          arr[j][k]='.';
          a--;
        }else if(a==0 && c>0){
          arr[j][k] ='X';
          c--;
        }else{
          arr[j][k]='.';
        }
      }
    }
    arr[0][0]='O';
    for(int j=0;j<8;j++){
      for(int k=0;k<8;k++){
        cout<<arr[j][k];
      }
      cout<<endl;
    }
    cout<<endl;
  }
}