#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll position(ll sum){
  
  long double a =sqrtl(1ul+4*(sum));
  a =a - 1.0;
  a = a/2.0;
  ll fs = a;
  return fs;
}

int main(){
  ll test;
  
  cin>>test;
  
  while(test--){
    
    ll n;
    cin>>n;
    
    if(n==0 || n==1 || n==2){
      cout<<0<<endl;
      continue;
    }
    
    ll sum = (n*(n+1))/2;
    if(sum%2 ){
      cout<<0<<endl;
      continue;
    }
    
    ll p = position(sum);
    ll ss = p*(p+1)/2;
    
    if(sum/2 == ss){
      ll ans = (p*(p-1ul))/2l+((n-p)*(n-p-1ul))/2l+(n-p);
      cout<<ans<<endl;
    }else{
      cout<<n-p<<endl;
    }
    
  }
  
  return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// ll binomialCoeff(ll n, ll k) 
// { 
//     ll C[k+1]; 
//     memset(C, 0, sizeof(C)); 
  
//     C[0] = 1;  // nC0 is 1 
  
//     for (ll i = 1; i <= n; i++) 
//     { 
//         // Compute next row of pascal triangle using 
//         // the previous row 
//         for (ll j = min(i, k); j > 0; j--) 
//             C[j] = C[j] + C[j-1]; 
//     } 
//     return C[k]; 
// } 


// int main(){
  
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
    
//   ll t,n;
  
//   cin>>t;
//   while(t--){
//     cin>>n;
    
//     ll sum = (n*(n+1))/2,count=0;
//     if(sum % 2 ==0){
      
//       ll half = sum/2;
   
//       ll tempSum  = 0;
//       for(ll i=n;i>=1;i--){
//         if(tempSum <=half ){
//           tempSum += i;
//           count++;
//         }
//         if(tempSum == half){
//           count = count + binomialCoeff(n-count,2) + binomialCoeff(count,2) ;
//           break;
//         }
//         if(tempSum > half){
//           break;
//         }
//       }
//     }
    
//     cout<<count<<endl;
//   }
  
// }












// #include <iostream>
// using namespace std;

// typedef long long int ll;

// int main() {
// 	ll t,n;
// 	cin>>t;
// 	while(t--){
	  
// 	  cin>>n;
// 	  ll sum = (n*(n+1))/2;
// 	  ll count = 0;
// 	  if(sum % 2 ==0 ){
// 	    ll a[n+1];
	    
// 	    for(ll i=1;i<=n;i++){
// 	      a[i] = i; 
// 	    }
	    
	    
// 	    for(ll i=1;i<=n;i++){
// 	      for(ll j=i+1;j<=n;j++){
//           ll temp[n+1];
//           for(ll k=1;k<=n;k++){
//             temp[k] = a[k];
//           }
//           //swap array elements
//           ll flag = temp[i];
//           temp[i] = temp[j];
//           temp[j] = flag;
          
//           //swap(temp[i] , temp[j]);
//           for(ll i=2;i<=n;i++){
//             temp[i] = temp[i-1] + temp[i];
//           }
//           for(ll m=1;m<=n;m++){
//             if(temp[m] == temp[n] - temp[m])
//               count++;
//           }
// 	      }
// 	    }
	    
// 	  }
	  
// 	  cout<<count<<endl;
// 	}
	
	
// 	return 0;
// }
