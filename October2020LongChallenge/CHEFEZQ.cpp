//Proble Link : https://www.codechef.com/problems/CHEFEZQ

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll arr[],ll n,ll k){
  
  ll i, ans = 0;
  
	  for(i=0;i<n;i++){
	    if(arr[i] >= k){
	      ans++;
	      arr[i+1] = arr[i+1] + (arr[i]-k);
	    }
	    if(arr[i] < k)
	      break;
	  }
	  
	  if(i == n)
	    ans = ans + (arr[n-1] - k)/k;
	    
	 ans += 1;     
	return ans;
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	  
	  ll n, k ;
	  cin>>n>>k;
	  
	  ll arr[n];
	  
	  for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	  cout<<solve(arr,n,k)<<endl;
	}
	
	return 0;
}
