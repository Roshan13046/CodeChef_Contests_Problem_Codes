//ROSHAN RAUT: PVG COET,Pune. 11/8/2020 .
//HARD WORK BEATS TALENT , WHEN TALENT DOESN'T WORK HARD


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  
  int t;
  
  cin>>t;
  while(t--){
    
    ll n,k;
    cin>>n>>k;
    
    map<ll,ll>m;  
    ll a[n+1];
    
    for(int i=0;i<n;i++)
      cin>>a[i];
    
    ll conflicts[n+1][n+1] = {0};
    
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        conflicts[i][j]=0;
      }
    }
    
    for(int i=0;i<n;i++){
      m.clear();
      
      for(int j=i;j<n;j++){
        if(j==0){
          conflicts[i][j] = 0;
        }else{
          conflicts[i][j] = conflicts[i][j-1]; 
        }
          if(m[a[j]]){
            if(m[a[j]] == 1){
              conflicts[i][j]++;
            }    
            conflicts[i][j]++;
          }
          m[a[j]]++;
      }
    }
    
    ll MinCost = INT_MAX,table=100;
    ll dp[101][1001]={0};
    
    for(int i=0;i<=table;i++){
      for(int j=0;j<=n;j++)
        dp[i][j]=0;
    }
    
    for(int i=2;i<n+2;i++){               //smll check i<n+2 and also i=2
      dp[1][i]= conflicts[0][i-1];
    }
    
    for(int i=2;i<=table;i++){
      for(int j=2;j<=n;j++){
        ll mini = INT_MAX;
        for(int k=1;k<j;k++){
          mini = min(mini,dp[i-1][k] + conflicts[k][j-1]);
        }
        dp[i][j] = mini;
      }
    }
    
    for(int i= 1;i<=100;i++){
      MinCost = min(MinCost,i*k + dp[i][n]);
    }
    cout<<MinCost<<endl;
  }
}



// #include <bits/stdc++.h>
// using namespace std;

// void solve(int a[],int n,int k){
  
//   map<int,int>fam,tables;
  
//   int countChair=1;
//   for(int i=0;i<n;i++){
//     ++fam[a[i]];
//     if(!tables[a[i]]){
//       tables[a[i]]++;
//     }else{
//       countChair++;
//       tables.clear();
//       tables[a[i]]++;
//     }
//   }
  
//   int conflicts = 0;
//   for(auto x:fam){
//     if(x.second>1){
//       conflicts += x.second;
//     }
//   }
  
// long int ans=0;
//   if(countChair*k > conflicts + k){
//     ans = conflicts + k;
//   }else{
//     ans = countChair*k;
//   }
//   cout<<ans<<endl;
// }

// int main() {
  
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
  
// 	int t,n,k;
	
// 	cin>>t;
// 	while(t--){
// 	  cin>>n>>k;
// 	  int a[n];
	  
// 	  for(int i=0;i<n;i++){
// 	    cin>>a[i];
// 	  }
	  
// 	  solve(a,n,k);
// 	}
	
// 	return 0;
// }
// /*
// 12 5
// 1 2 3 4 4 5 1 2 3 4 4 5
// Ans:14
// */

