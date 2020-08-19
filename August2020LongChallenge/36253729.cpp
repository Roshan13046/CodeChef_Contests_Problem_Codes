#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t,H,P;
	
	cin>>t;
	while(t--){
	  
	  cin>>H>>P;
	  
	  int ans= 0;
	  while(H>0 && P>0){
	    H -= P;
	    if(H <= 0){
	      ans = 1;
	      break;
	    }
	    P = P/2;
	    
	    if(P <= 0){
	      ans = 0;
	      break;
	    }
	    
	  }
	  
	  cout<<ans<<endl;
	}
	return 0;
}
