
//ROSHAN RAUT SOLUTION AFTER 9 DAYS OF HARD WORK

#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;


#define ll long long int
void SOLUTION();  

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

struct myPair{
  
  int network;
  double time;
  
  myPair(int c,double t){
    network = c;
    time = t;
  }
};

int DFS(vector<vector<myPair>>&c,unordered_map<int,int>& visit,queue<myPair> &q){
  int counter = 0;
  
  while(!q.empty()){
    
    myPair x = q.front();
    q.pop();
    
    for(int j=0;j<c[x.network].size();j++){
      
      if(visit.count(c[x.network][j].network) == 0){
        
          if(x.time < (c[x.network][j].time)){
            
            visit[c[x.network][j].network]++;
            q.push(c[x.network][j]);
            counter++;
            
          }
      }
    }
  }
  return counter;
}


void SOLUTION(){
  int test;
  
  cin>>test;
  while(test--){
    
    int n;
    cin>>n;
    
    vector<int> arr(n+1);
    for(int i=1;i<n+1;i++)
      cin>>arr[i];
    
    vector<vector<myPair>>  c(n+1);
    
    for(int i=1;i<n+1;i++){
      for(int j=1;j<n+1;j++){
        
        if(i!=j){
          if(i-j>0 && arr[i]-arr[j] <0)
            c[i].push_back(myPair(j,(double)(i-j)/(arr[j]-arr[i])));
            
          if(i-j<0 && arr[i]-arr[j]>0)
            c[i].push_back(myPair(j,(double)(j-i)/(arr[i]-arr[j])));
        }
        
      }
    }
    
    int minBest = INT_MAX, maxWorst = INT_MIN;
    
    for(int i=1;i<n+1;i++){
      unordered_map<int,int>visit;
      queue<myPair>q;
      int counter = 1;
      
      visit[i]++;
      
      for(int j=0;j<c[i].size();j++){
        visit[c[i][j].network]++;
        q.push(c[i][j]);
        counter++;
      }
      
      counter += DFS(c, visit,q);
      if(counter > maxWorst)
        maxWorst = counter;
        
      if(counter < minBest)  
        minBest = counter;
    }
    ///khamaghanii
    cout<<minBest<<" "<<maxWorst<<endl;
  }
}


















// #include<bits/stdc++.h>
// using namespace std;

// typedef long long int ll ;

// void ResetInfecteds(vector<ll>&infect , ll n){
//   vector<ll> temp(infect.size(),0);
//   infect = temp;
//   infect[n] = 1;
// }


// int getCountOfOnes(vector<ll> &array){
//   ll count = 0;
//   for(auto x: array){
//     if(x == 1)
//       count++;
//   }
//   return count;
// }

// void ResetDistances(vector<ll>&distances){
//   ll n = distances.size();
//   for( ll i=0;i<n;i++){
//     distances[i] = i;
//   }
// }

// vector<ll> getCurrentlyInfecteds(vector<ll> &infecteds){
  
//   vector<ll> outputs;
//   for(ll i=0;i<infecteds.size();i++){
//     auto x = infecteds[i];
//     if(x == 1){
//       outputs.push_back(i);
//     }
//   }
//   return outputs;
// }



// void solve2(vector<ll> &a){
//   ll n = a.size();
  
//   vector<ll> count(n,1);
//   for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//       if(a[i] > a[j])
//         count[i]++;
//     }
    
//     for(int j=0;j<i;j++){
//       if(a[j] > a[i])
//         count[i]++;
//     }
//   }
//   ll mini = INT32_MAX;
//   ll maxi = 0;
  
//   for(auto x: count){
//     mini = min(mini , x);
//     maxi = max(maxi , x);
//   }
  
//   cout<<mini<<" "<<maxi<<endl;
  
// }

// void solve(vector<ll> &array){
//   ll n = array.size();
//   if( n == 0){
//     cout<<0<<" "<<0<<endl;
//     return ;
//   }
  
//   if(n==1){
//     cout<<1<<" "<<1<<endl;
//     return ;
//   }
  
//   vector<ll> infecteds(n,0);
//   vector<ll> dists(n,0);
//   ll mini = INT32_MAX;
//   ll maxi = 0;
  
//   for(ll i=0;i<n;i++){
//     ResetInfecteds(infecteds,i);
//     ResetDistances(dists);
    
//     int forLoop = 100;
    
//     while(forLoop-- ){
//       for(ll j=0;j<n;j++){
//         dists[j] += array[j];
//       }
      
      
//       unordered_set<ll> uSet;
//       vector<ll>alreadyInfecteds = getCurrentlyInfecteds(infecteds);
      
//       for(auto x:alreadyInfecteds){
//         uSet.insert(dists[x]);
//       }
      
//       for(ll j=0;j<n;j++){
        
//         if(infecteds[j])
//           continue;
          
//         if(uSet.count(dists[j]))
//           infecteds[j] = 1;
          
//       }
      
//       uSet.clear();
//     }
//       ll ans = getCountOfOnes(infecteds);
//       mini = min(mini , ans);
//       maxi = max(maxi , ans);  
//   }
  
//   cout<<mini<<" "<<maxi<<endl;
//   return ; 
// }

// int main(){
//   int tests;
  
//   cin>>tests;
//   while(tests--){
//     int n;
//     cin>>n;
//     vector<ll>arr(n);
    
//     for(int i=0;i<n;i++){
//       cin>>arr[i];
//     }
    
//     if( n == 3)
//       solve2(arr);  
//     else
//       solve(arr);
//   }
// }




// /*
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long int

// int main(){
  
//   ll test,n;
  
//   cin>>test;
//   while(test--){
    
//     cin>>n;
//   int v [n],temp[n]={0};
    
//     ll i;
//     for(i=0;i<n;i++)
//     cin>>v[i];
     
//     for(i=0;i<n;i++) {
      
//       ll l,r,px=0,py=0;
//       for(l=i;l>=0;l--){
//           if(v[l]>v[i])
//             px++;
//       }
      
//       for(r=i;r<n;r++){
//         if(v[r]<v[i])
//           py++;
//       }
      
//       temp[i] = px+py;
//     }
    
//     ll best = temp[0];
//     ll worst = temp[0];
    
//     for(i=0;i<n;i++){
//       if(temp[i] < best){
//         best = temp[i];
//       }
//       if(temp[i] > worst){
//         worst = temp[i];
//       }
//     }
    
//     best = best +1;
//     worst = worst + 1;
//     cout<<best<<" "<<worst<<endl;
//   }
    
// }
// */