//Roshan Raut
//"Hard work beats Talent,when Talent doesn't work Hard"
//Have Confidence.....................

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int helper(){
  
  ll num,answer=0;
  cin>>num;
  
  vector<ll>v;
  ll aa;
  
  for(ll i=1;i<=20;i++){
    
    cout<<1<<" "<<(1ul<<i)<<endl;
    cout.flush();
    cin>>aa;
    v.push_back(aa);
  }
  //reversing the vector
  reverse(v.begin(),v.end());
  
 // for(int i=0;i<8;i++);//just for time pass
  
  ll temp = v[0]- num*(1ul<<20);
  
  for(ll i=1;i<v.size();i++){
    if(v[i] >=temp){
      v[i] = ((num-(v[i] - temp)/(1ul<<(v.size()-i)))/2);
    }else{
      v[i] = (num+(temp-v[i])/(1ul<<(v.size()-i)))/2;
    }
  }
  
  for(ll i=1;i<v.size();i++)
    if(v[i]%2!=0)
      answer += 1ul<<(v.size()-i);
      
    if(temp%2!=0)  
      answer++;
    cout<<2<<" "<<answer<<endl;
    cout.flush();
    
    ll RESULT;
    cin>>RESULT;
    return RESULT;
  
}



int main(){
  
  ll test;
  cin>>test;
  
  while(test--){
    
    if(!helper())
      break;
      
    cout<<endl;
    
    cout.flush();
  }
}



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
	  
// 	  cout<<count<<" ";
// 	}
	
	
// 	return 0;
// }
