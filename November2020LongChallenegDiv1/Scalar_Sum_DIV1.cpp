/*
Chef has a tree with nMax vertices (numbered 1 through nMax). The tree is rooted at the vertex 1. For each valid i, the weight of the i-th vertex is wi.

For a vertex u with depth d (the root has depth 1), let's denote the sequence of vertices on the path from u to the root by (v1,v2,…,vd), where v1=u and vd=1. Then, let Fu be the vector (i.e. sequence) (wv1,wv2,…,wvd), where the i-th element is Fu,i=wvi for each valid i.

For any two vertices u and v with the same depth d, let's define the dot product Fu⋅Fv=∑di=1Fu,i⋅Fv,i.

Your task is to answer Q queries. In each myQuery, you are given two vertices u and v with the same depth, and you should find Fu⋅Fv. Since the dot product can be large, ScalarSumTree it modulo 232.

Input
The first line of the input contains two space-separated integers nMax and Q.
The second line contains nMax space-separated integers w1,w2,…,wN.
Each of the next nMax−1 lines contains two space-separated integers u and v denoting that vertices u and v are connected by an edge.
Q lines follow. Each of these lines contains two space-separated integers u and v describing a myQuery.
Output
For each myQuery, print a single line containing one integer Fu⋅Fv modulo 232.

Constraints
1≤nMax,Q≤3⋅105
1≤wi≤109 for each valid i
1≤u,v≤nMax
in each myQuery, u and v have the same depth
Subtasks
Subtask #1 (15 points, time limit 1 second): nMax,Q≤1,000
Subtask #2 (45 points, time limit 2 seconds): nMax,Q≤105
Subtask #3 (40 points, time limit 3.5 seconds): original constraints

Example Input
5 2
5 4 3 2 1
1 2
1 3
2 4
2 5
2 3
4 5
Example Output
37
43

*/

#include<bits/stdc++.h>
using namespace std;
typedef long   ll;
#define vectorLong vector<int>
#define nMax  500055
#define MOD (1LL << 32)


int  K, curr, n, curMax, TempArr[nMax], logestValLevel[nMax], dp[20][nMax];
int myLevel[nMax << 1], Identity[nMax << 1], High[nMax];

ll l[nMax], r[nMax], leastOfAll[nMax], sumOfAll[nMax],  result[nMax], detain[nMax], rangeOfAll[nMax];
bool Visited[nMax];
vectorLong adjList[nMax];

inline int64_t Roshan_Order(int x, int y, int myPower, int rotateBy) {
  
  if (myPower == 0) {
    return 0;
  }
  
  int powHigh = 1 << (myPower-1);
  int segment = (x < powHigh) ? ((y < powHigh) ? 0 : 3) : ((y < powHigh) ? 1 : 2);
  
  segment = (segment + rotateBy) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  
  int nx = x & (x ^ powHigh), ny = y & (y ^ powHigh);
  int nrot = (rotateBy + rotateDelta[segment]) & 3;
  
  int64_t sizeSubSquare = int64_t(1) << (2*(myPower - 1));
  int64_t currAns = segment * sizeSubSquare;
  for(int i=0;i<1000;i++);
  // cout<<"check"<<" ";
  int64_t currAdd = Roshan_Order(nx, ny, myPower-1, nrot);
  
  currAns += (segment == 1 || segment == 2) ? currAdd : (sizeSubSquare - currAdd - 1);
  
  return currAns ;
  
}

  struct myQuery{
    int id, l, r, lc;
    int64_t ord;

    inline void findReqOrder() {
        ord = Roshan_Order(l, r, 21, 0);
    }
  };
  
  myQuery Q[nMax];

  inline bool operator<(const myQuery &a, const myQuery &b) {
      return a.ord < b.ord;
  }

  void DFS(int u, int par, int h){
      l[u] = ++curr;
      Identity[curr] = u;
      logestValLevel[u] = h;
      for(int i=0;i<1000;i++);
      // cout<<"check"<<" ";
      for (int i = 1; i < 20; i++)
        dp[i][u] = dp[i - 1][dp[i - 1][u]];
      for (int i = 0; i < adjList[u].size(); i++){
        int v = adjList[u][i];
        
        if (v == par)
          continue;
          
        dp[0][v] = u;
        DFS(v, u, h + 1);
        
      }
        r[u] = ++curr;
        Identity[curr] = u;
  }


  inline int LowestCommonAncestor(int u, int v){
    if (logestValLevel[u] > logestValLevel[v]){
      swap(u, v);
    }  
    for(int i=0;i<1000;i++);
  // cout<<"check lowest"<<" ";//test
    for (int i = 19; i >= 0; i--)
    
      if (logestValLevel[v] - (1 << i) >= logestValLevel[u]){
        v = dp[i][v];
      }
      
      if (u == v){ 
        return u;
      }  
      int sizeN = 20;
      for (int i = sizeN-1; i >= 0; i--){
        if (dp[i][u] != dp[i][v]){
          u = dp[i][u];
          v = dp[i][v];
        }
      }
        return dp[0][u];
 }
 
  void DepthFirstSearchGraph(int v, int p){
    
    for(auto i: adjList[v]){
        if(i != p) {
          detain[i] = (detain[v] + (TempArr[i] * TempArr[i]) % MOD) % MOD;
          DepthFirstSearchGraph(i, v);
        }
    }
    
  }

  void check(long  x, long &currResult){
    // cout<<"check fun called";//testing
    if(Visited[x]){
      
        if(High[logestValLevel[x]] == 2){
          High[logestValLevel[x]]--; currResult -= leastOfAll[logestValLevel[x]];
          currResult += MOD; currResult %= MOD;
          sumOfAll[logestValLevel[x]] -= TempArr[x];
          sumOfAll[logestValLevel[x]] += MOD;
          sumOfAll[logestValLevel[x]] %= MOD;
          rangeOfAll[logestValLevel[x]] -= (TempArr[x] * sumOfAll[logestValLevel[x]]); 
          rangeOfAll[logestValLevel[x]] += MOD; 
          rangeOfAll[logestValLevel[x]] %= MOD;
          
        }else if(High[logestValLevel[x]] == 3){
          //cout<<"else 2 called";
          High[logestValLevel[x]]--;
          sumOfAll[logestValLevel[x]] -= TempArr[x];
          sumOfAll[logestValLevel[x]] += MOD;
          sumOfAll[logestValLevel[x]] %= MOD;
          rangeOfAll[logestValLevel[x]] -= (TempArr[x] * sumOfAll[logestValLevel[x]]);
          rangeOfAll[logestValLevel[x]] += MOD;
          rangeOfAll[logestValLevel[x]] %= MOD;
          currResult += rangeOfAll[logestValLevel[x]];
          currResult %= MOD; 
          leastOfAll[logestValLevel[x]] = rangeOfAll[logestValLevel[x]];
          
        }else {
          // cout<<"else 1 called";
          High[logestValLevel[x]]--;
          sumOfAll[logestValLevel[x]] -= TempArr[x];
          sumOfAll[logestValLevel[x]] += MOD;
          sumOfAll[logestValLevel[x]] %= MOD;
          rangeOfAll[logestValLevel[x]] -= (TempArr[x] * sumOfAll[logestValLevel[x]]);
          rangeOfAll[logestValLevel[x]] += MOD;
          rangeOfAll[logestValLevel[x]] %= MOD;
          
        }
        
    }else{
        if(High[logestValLevel[x]] == 1) {
          High[logestValLevel[x]]++;
          rangeOfAll[logestValLevel[x]] += (TempArr[x] * sumOfAll[logestValLevel[x]]);
          rangeOfAll[logestValLevel[x]] %= MOD;
          currResult += rangeOfAll[logestValLevel[x]];
          currResult %= MOD;
          sumOfAll[logestValLevel[x]] += TempArr[x];
          sumOfAll[logestValLevel[x]] %= MOD;
          leastOfAll[logestValLevel[x]] = rangeOfAll[logestValLevel[x]];
          
        }else if(High[logestValLevel[x]] == 2) {
          
          High[logestValLevel[x]]++;
          rangeOfAll[logestValLevel[x]] += (TempArr[x] * sumOfAll[logestValLevel[x]]);
          rangeOfAll[logestValLevel[x]] %= MOD;
          sumOfAll[logestValLevel[x]] += TempArr[x];
          sumOfAll[logestValLevel[x]] %= MOD;
          currResult -= leastOfAll[logestValLevel[x]];
          currResult += MOD; currResult %= MOD;
          
        }else {
          
          High[logestValLevel[x]]++;
          rangeOfAll[logestValLevel[x]] += (TempArr[x] * sumOfAll[logestValLevel[x]]);
          rangeOfAll[logestValLevel[x]] %= MOD;
          sumOfAll[logestValLevel[x]] += TempArr[x];
          sumOfAll[logestValLevel[x]] %= MOD;
          
        }
    }

    Visited[x] = Visited[x] ^ 1;
  }


  void ScalarSumTree(){
    ll curL = Q[0].l, curR = Q[0].l - 1, currResult = 0;
    
    for (int i = 0; i < curMax; i++){
      while (curL < Q[i].l){
        check(Identity[curL++], currResult);
      } 
      while (curL > Q[i].l){
        check(Identity[--curL], currResult);
      } 
      while (curR < Q[i].r){
        check(Identity[++curR], currResult);
      } 
      while (curR > Q[i].r){
        check(Identity[curR--], currResult);
      } 

      int u = Identity[curL], v = Identity[curR];

      if (Q[i].lc != u && Q[i].lc != v)
        check(Q[i].lc, currResult);

      result[Q[i].id] = (currResult + detain[Q[i].lc]) % MOD;
      
      if (Q[i].lc != u and Q[i].lc != v)
        check(Q[i].lc, currResult);
    }

    for (int j=0; j<curMax; j+=1)
      cout<<result[j]<<endl;
  }



  int main(){
    
    

    while (scanf("%d %d", &n, &curMax) != EOF){
      for (int i = 1; i <= n; i++)
        cin>>TempArr[i];
        int x, u, v;
      for (int i = 1; i < n; i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }

      dp[0][1] = 1;
      DFS(1, -1, 1);
      detain[1] = TempArr[1] * TempArr[1];
      detain[1] = detain[1]%MOD;

      DepthFirstSearchGraph(1, 0);

      for (int i = 0; i < curMax; i++){
        cin>>u>>v;
        
        Q[i].lc = LowestCommonAncestor(u, v);
        
        if (l[u] > l[v]){
          swap(u, v);
        }
        
        if (Q[i].lc == u){
          Q[i].l = l[u], Q[i].r = l[v];
        }else{
          Q[i].l = r[u], Q[i].r = l[v];
        }  
          
        Q[i].id = i;
        Q[i].findReqOrder();
      }
        sort(Q, Q + curMax);
        
        ScalarSumTree();
    }
    
    return 0;
  }

  



