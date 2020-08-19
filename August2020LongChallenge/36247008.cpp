#include <iostream>
using namespace std;

int main() {
	int t,c,r;
	
	cin>>t;
	while(t--){
	  cin>>c>>r;
	  int cDig = c/9,rDig=r/9;
	  
	  if(c%9){
	    cDig++;
	  }
	  
	  if(r%9){
	    rDig++;
	  }
	  
	  if(cDig<rDig){
	    cout<<0<<" "<<cDig<<endl;
	  }else{
	    cout<<1<<" "<<rDig<<endl;
	  }
	  
	}
	return 0;
}
