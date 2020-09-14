//ROSHAN RAUT SOLUTION AFTER 5 DAYS OF HARD WORK

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;


#define ll long long int
#define MOD 1000000007

ll division1(ll x , ll y);
void SOLUTION();  

#define loop1 for(int i=0 ; i<k; i++){\
                  ans = (ans % MOD *(n-i)%MOD)%MOD;\
                  ans = division1(ans,i+1);\
                }                
    

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
    #ifndef ONLINE_JUDGE
      clock_t tStart = clock();
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
        SOLUTION();
    #ifndef ONLINE_JUDGE
        fprintf(stderr,"Runtime: %.10fs\n",(double)(clock() - tStart) / CLOCKS_PER_SEC);
    #endif
        return 0;
}                

ll powerll(ll x, ll n){
  ll ans = 1;
  while(n){
    if(n & 1)
      ans = ans * x % MOD;
    n = n/2;
    x = x * x % MOD;
  }
  return ans;
}



ll solution1(ll n, ll r){
  
  ll ans = 1;
  ll k = min(r, n-r);
  loop1
  return ans % MOD;
  
}

ll division1(ll x , ll y){
  
  return (x % MOD * (powerll(y , MOD - 2) % MOD)) % MOD;
  
}
                
void SOLUTION(){
  
  int test;
  
  cin>>test;
  while(test--){
    
    ll n;
    cin>>n;
    
    ll arr[n], answer;
    
    for(ll i=0; i<n;i++){
      cin>>arr[i];
    }
    
    ll max = 0, max_value = 0;
    
    for(int i=0 ; i<n; i++){
      if(max < arr[i])
         max = arr[i];
    }
    
    for(int i=0 ; i<n; i++){
      if(max == arr[i])
        max_value++;
    }
    
    if(n == 1){
      cout<<2<<'\n';
      continue;
    }
    if(max_value % 2)
      answer = powerll(2 , n)% MOD;
    else
      answer = powerll(2,n) % MOD - 
            ((powerll(2,n - max_value) % MOD) * solution1(max_value,max_value/2)% MOD)%MOD;
    if(answer < 0)        
      answer = (answer + MOD)% MOD;
      
    cout<<answer % MOD<<endl;
  }
}       

