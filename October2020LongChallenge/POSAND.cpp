//Problem Stmt Link :  https://www.codechef.com/problems/POSAND

#include <bits/stdc++.h>
using namespace std;

int check(int n){
  if(n==0)
    return 0;
    
  if((n & (n-1)) == 0)
    return 1;
  else 
    return 0;
}

int main() {
  int t,n;
  
  cin>>t;
  while(t--){
    
    cin>>n;
    
    string ans[] = {"1", "1 3 2","2 3 1 5 4","-1"};
    
    if(n == 1){
      cout<<ans[0]<<endl;
    }else if(n == 3){
      cout<<ans[1]<<endl;
    }else if(n == 5){
      cout<<ans[2]<<endl;
    }else if(check(n)){
      cout<<ans[3]<<endl;
    }else{
      cout<<ans[2]<<endl;
      
      for(int i=6;i<=n;){
        
        if(!check(i)){
          
          cout<<i<<" ";
          i++;
          
        }else if(check(i)){
          
          cout<<i+1<<" "<<i<<" ";
          i += 2;
          
        }
        
      }
      cout<<endl;
    }
  }
	
	return 0;
}
