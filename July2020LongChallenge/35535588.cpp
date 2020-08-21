/*
2
6
1 6 11 6 10 11
4
1 3 5 7
Sample Output:
15
3

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    cin>>a[0];
    
    unsigned long long int sum =0 ;
    for(int i=1;i<n;i++){
      cin>>a[i];
      
      sum += abs(a[i]-a[i-1]) - 1;
      
    }
    
    cout<<sum<<endl;
  }
}