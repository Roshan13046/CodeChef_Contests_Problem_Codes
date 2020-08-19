/*
Constraints
1≤T≤100
1≤N≤1,000
1≤K≤109
1≤Pi≤109 for each valid i
K,P1,P2,…,PN are pairwise distinct
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
4 6
4 3 2 8
4 7
4 3 2 8
Example Output
3
-1
Explanation
Example case 1: The player who starts at the position 2 can move to square 4 and then to square 6. The player who starts at the position 3 can move to square 6. The player at position 2 can capture Chef's pawn in 2 turns, whereas the player at position 3 can capture Chef's pawn in 1 turn. Therefore, the answer is 3.

Example case 2: No player can capture Chef's pawn.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
  
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
	int t,n,k;
	
	cin>>t;
	while(t--){
	  cin>>n>>k;
	  int p[n];
	  map<int,int>m;
	  for(int i=0;i<n;i++){
	    cin>>p[i];
	    
	    m[p[i]]=INT_MAX;
	    
	    int moves = -1;
	    
	    if(p[i] <= k)  {
	      if((k-p[i]) >= p[i] && (k-p[i])%p[i]==0){
	        moves = (k-p[i])/p[i];
	      }
	    }
	    
	    if(moves != -1) m[p[i]] = moves;
	  } 
	  
	  int player = -1 , playerMoves=INT_MAX;
	  
	  for(auto x:m){
	    if(x.second <playerMoves){
	      player= x.first ;
	      playerMoves = x.second;
	    }
	  }
	  
	  cout<<player<<endl;
	  
	}
	
	return 0;
}
