/*
1
2
1 1
1 2
4 6
2 1
9 6
9 3
4 3
Example Output
2 2

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
	 int t,n;
// 	scanf("%d",&t);
	cin>>t;
	while(t--){
	  unordered_set<int>mx,my;
	  
	  int x,y;
	  cin>>n;
	 // scanf("%d",&n);
	  n=(4*n-1);
	  
	  while(n--){
	    cin>>x>>y;
	   //scanf("%d %d",&x,&y);
	   
	   
	   if( mx.find(x) != mx.end())
	    mx.erase(mx.find(x));
	   else{
	     mx.insert(x);
	   } 
	   
	   if( my.find(y)!= my.end())
	    my.erase(my.find(y));
	   else{
	     my.insert(y);
	   } 
	  }
	  for(auto X : mx){
	   // if(X.second %2 ==1 ){//if odd occurence of X.first
	   //   //cout<<X.first<<" ";
	   //   printf("%d ",X.first);
	   //   break;
	   // }
	   cout<<X<<" ";
	  }
	  
	  for(auto Y : my){
	   // if(Y.second % 2 ==1 ){//if odd occurence of Y.first
	   //  // cout<<Y.first;
	   //  printf("%d\n",Y.first);
	   //   break;
	   // }
	   cout<<Y<<endl;
	  }
	  mx.clear();my.clear();
	  //cout<<endl;
	}
	return 0;
}
