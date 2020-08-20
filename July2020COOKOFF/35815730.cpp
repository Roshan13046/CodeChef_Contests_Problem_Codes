#include <iostream>
#include<map>
using namespace std;

int main() {
	
	int t,n;
	cin>>t;
	while(t--){
	  string str;
	  cin>>n;
	  cin>>str;
	  map<char,int>m;
	  for(int i=0;i<n;i++){
	    m[str[i]]++;
	  }
	  
	  int flag=0;
	  for(auto x:m){
	    if(x.second %2==1){
	      cout<<"NO"<<endl;
	      flag=1;
	      break;
	    }
	  }
	  
	  if(flag ==0)
	    cout<<"YES"<<endl;
	}
	
	return 0;
}
