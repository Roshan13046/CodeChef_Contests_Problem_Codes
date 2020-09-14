#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	
	cin>>t;
	while(t--){
	  cin>>n;
	  int x;
	  map<int,int>m;
	  for(int i=0;i<n;i++){
	    cin>>x;
	    if(x!=0)
	      m[x]++;
	  }
	  
	  cout<<m.size()<<endl;
	 
	}
	return 0;
}
