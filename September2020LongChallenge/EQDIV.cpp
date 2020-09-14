#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int k;
string str[5] = {"","0","01","001","0110"};


void mySolution(){
  int n;
  cin>>n;
  int result;
  if(n%4 == 0 || n%4 == 3 )
    result = 0;
  else
    result = 1;
  cout<<result<<endl;
  
  string ans ="";
  
  for(int i=0;i<n/4;i++){
    ans += str[4];
  }
  int temp;
  if(n%4 == 1){
    ans = str[1] + ans;
  }else if(n%4 == 2){
    ans += str[2];
  }else if(n%4 == 3){
    ans = str[3] + ans;
  }
  cout<<ans<<endl;
}


int main(){
  
  cin>>k;
  
  int test;
  cin>>test;
  while(test--){
    mySolution();
  }
}