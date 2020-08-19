
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;

#define M 1000000007

ll dp[1001][1001];

ll nck(ll n,ll r)
{
  if(n<r){    
    return 0;
  }  
  if(r==0 || r==n)
    return 1;
      
    if(r > n/2 && dp[n][n-r]!=0)   
      return dp[n][n-r]%M;
      
    if(dp[n][r]!=0)
      return dp[n][r]%M;
      
    if(n>r)
      return dp[n][r]=(nck(n-1,r-1)%M + nck(n-1,r)%M)%M;
}



void solve(ll a[],ll n){
  
  map<ll,ll> m;
  
  for(ll i=0;i<n;i++){
    m[a[i]]= (m[a[i]]%M+1%M)%M ;
  } 
  
  ll combi[n+10][n+10]={0};/// for storing the values in pairs of ele and j
  memset(combi,0,sizeof(combi));
  // for(ll i=1;i<=n;i++){
  //   if(m[i] !=0)
  //     combi[0][i]= 1;
  // }
  for(auto x: m){
    combi[0][x.first] = 1;
  }
  
  ll maxOccur = 0;
  for(auto x: m){
    maxOccur = max(maxOccur, x.second);
  }
  
  for(ll i=1;i<=maxOccur;i++){
    for(ll j=1;j<=n;j++){
      if(combi[i][j] == 0){
          combi[i][j] = (nck(m[j],i)%M + combi[i-1][j]%M)%M;
      }
    }
  }
  
  // for(ll i=0;i<=maxOccur;i++){
  //   for(ll j=1;j<=n;j++){
  //   cout<<combi[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout << "ans : ";
  
  
    
  for(ll i=1;i<=n;i++){
    ll sum=0;
    
    if(m[i] !=0){
      for(ll j=1;j<=m[i];j++){      //no times occurs from 1 to m[i]
      
      ll tempMul = 1;
        for(auto x:m){ //elements from 1 to n
        
          ll e=x.first;                          
          
          if( e < i){ //for elements less than i
            if(combi[j-1][e])
              tempMul = (tempMul%M * combi[j-1][e]%M) % M;
             // if(tempMul == 0) cout<<"Zero ";
          }
          
          if(e == i){ //for elements equals to i
            tempMul = (tempMul%M * nck(m[e],j)%M) % M;
          }
          
          if(e > i){  //for elements greater than i 
            if(combi[j][e])
              tempMul = (tempMul%M * combi[j][e]%M) % M;
          }
        }
        sum = (sum%M + tempMul%M) % M;
      }
    }
    cout<<sum<<" ";
  }
 m.clear();
 
}


ll solve2(ll x, ll y){
    ll ans = 1;
    x = x % M;
    if(x==0){
        return 0;
    }
    while(y>0){
        if(y&1){
            ans = (ans%M * x%M)%M;
        }
        y = y>>1;
        x = (x%M*x%M) % M;
    }
    return ans; 
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp,0,sizeof(dp));
  
  int t;  
    
  cin>>t;
  while(t--){
      ll n;
    	cin >> n;
    	ll a[n+1]={0};
    	map<ll,ll>mp;
    	for(ll i=0;i<n;i++){
    	  cin>>a[i]; 
    	  mp[a[i]]=(mp[a[i]]+1)%M;
    	}
    	bool case2 =1;
    	for(int i=1;i<=n;i++){
    	  if(mp[i]==0)
    	    case2 = 0;
    	} 
    	
    	if(case2){
    	  for(ll i=1;i<=n;i++){
    	    cout << (solve2(2, n-i))<<" ";
    	    //cout<<pow(2,n-i)<<" ";
    	  }
    	}else{
    	  memset(dp,0,sizeof(0));
    	  solve(a,n);
    	}
    	cout << endl;
    	mp.clear();
  }
  
	return 0;
}

