/*
Chef and Chefu are at a magical candy store playing a game with the following rules:

There are two candy counters; each of them stores an infinite number of candies. At any time, only one of the counters is open and the other is closed.
Exactly one player is present at each of the counters. Initially, Chef is at the open counter and Chefu is at the closed counter.
There is a sequence of N distinct integers A1,A2,…,AN. The game consists of R turns; in the i-th turn, the open counter offers only C=A(i-1)%N+1 candies to the player present at this counter. This player should choose a positive number of candies M to accept, where 1=M=C.
If this player accepts an odd number of candies, the players have to swap their positions (each player goes to the other counter).
After each N turns, the counter which was currently open is closed and the counter which was currently closed is opened.
The primary goal of each player is to maximise his own number of candies after R turns. As a second priority, each player wants to minimise the number of candies his opponent has after R turns.
You should process Q queries. In each query, you are given R and you should find the number of candies Chef has after R turns, assuming that both players play the game optimally. Since this number could be very large, compute it modulo 109+7.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains a single integer Q.
Each of the next Q lines contains a single integer R describing a query.
Output
For each query, print a single line containing one integer ? the maximum number of candies Chef can get, modulo 109+7.

Constraints
1=T=25
1=N=105
1=Ai=109 for each valid i
A1,A2,…,AN are pairwise distinct
1=Q=105
1=R=1012
the sum of N+Q over all test cases does not exceed 106
Subtasks
Subtask #1 (15 points):

N=10
Q=35
R=35
Subtask #2 (85 points): original constraints

Example Input
1
4
4 10 2 1
2
4
5
Example Output
17
21
Explanation
Example case 1: In the 1-st, 2-nd and 3-rd turn, Chef takes 4, 10 and 2 candies (16 in total) respectively.
 In the 4-th turn, Chef takes 1 candy (17 in total; this is the answer to the first query), which is odd and
  hence he has to go to the counter which is closed. However, since N=4 turns are just completed, the counter which 
  was currently open closes and the other one (where Chef went) opens. In the 5-th round, Chef can take 4 candies, so he has 21 candies.
*/

#include<bits/stdc++.h>
using namespace std;
#define M 1000000007;
typedef long long  ll;

int ChefCandies(ll n){
 
 vector<ll>CandyArr(n), dp(n);
 
 bool flagVar = false;
 ll answer = 0, query;
 
 for(int i=0;i<n;i++)
  cin>>CandyArr[i];
 
 if(CandyArr[0] == 1 && n>1){
   flagVar = true;
 }else{
  // cout<<"else execution check";
  for(int i=0;i<n-1;i++){
      if(CandyArr[i] == 1){
        
        // cout<<"test";
        if(CandyArr[i-1]&1==1){
          dp[i] = dp[i-1];  
        }else{
         dp[i] = dp[i-1] +1;
        } 
      }else if(CandyArr[i+1]==1 && i< (n-2)){
        
        // for(int i=1;i<100;i++);
        // cout<<"test";
        if(CandyArr[i]&1==1){
           answer = answer + CandyArr[i];
           dp[i] = answer;
        }else{
           dp[i] = answer +CandyArr[i];
           answer = answer+ CandyArr[i] - 1;
        }
      }else if(CandyArr[i]&1==1){
        dp[i] = answer + CandyArr[i];
        answer = answer + CandyArr[i] - 1;
        // cout<<"check";
      }else{
        answer = answer + CandyArr[i];
        dp[i] = answer;
      }
    }
      if(CandyArr[n-1]&1==1 ){
        // cout<<"test";
         answer =  answer + CandyArr[n-1];
         dp[n-1] = answer;
      }else{
         dp[n-1] = answer + CandyArr[n-1];
         answer = answer + CandyArr[n-1] - 1;
         
         for(int i=0;i<8;i++);
         // cout<<"test";
      }
 }

 //queries check
 cin>>query;
 
 while(query--){
  ll r;
  cin>>r;
  
  ll divide = r/n, remain = r%n;

  if(flagVar){
    
   if(!divide && remain){
    cout<<1<<endl;
    continue;
   }
   
   if(remain > 1){
    ll chefAns = (divide+1)%M;
    cout<<chefAns<<endl;
   }else{ 
    ll chefAns = divide % M;
    cout<<chefAns<<endl;
   }
   continue;
  }
  
  if(divide == 0){
   cout<<dp[remain-1]%M;
   cout<<endl;
   
  }else{
   if(remain == 0){
    for(int i=0;i<10;i++);
      // cout<"for check f"<<" ";
     
    ll chefAns = (((divide-1)*answer)+dp[n-1])%M;
    cout<<chefAns<<endl;
    
   }else{
    ll chefAns=(((divide)*answer)+dp[remain-1])%M;
    cout<<chefAns<<endl;
   }
  }
 }
 
 return 1;
}

int main(){
  
 ios::sync_with_stdio(false);
 cin.tie(0); cout.tie(0);
 
 ll t; 
 cin>>t;
 ll n;
  while(t--){
    cin>>n;
    int returnVal = ChefCandies(n);
 }  
 
}
/*
1
4
4 10 2 1
2
4
5

*/
