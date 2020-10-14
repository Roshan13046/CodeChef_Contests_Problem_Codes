// Problem Stmt Link : https://www.codechef.com/problems/CVDRUN


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,k,x,y;
	
	cin>>t;
	while(t--){
	  
	  cin>>n>>k>>x>>y;
	  
	  if(y > n){
	    cout<<"NO"<<endl;
	  }else if(y <= n) {
	    
	    int flag = 0;
	    
	    for(int i=1;i<=n && flag == 0;i++){
	      if((x + (k*i))%n != y){
	        continue;
	      }else{
	        cout<<"YES"<<endl;
	        flag = 1;
	      }
	    }
	    
	    if(!flag){
	      cout<<"NO"<<endl;
	    }
	  }
	}
	return 0;
}
