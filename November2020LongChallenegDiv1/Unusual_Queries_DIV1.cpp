
/*
There are N mountains in Chefland, arranged in arrA line and numbered 1 through N from left to right. For each valid i, the i-th mountain from the left has arrA height Hi.

Chef wants to choose arrA contiguous sequence of mountains lef,lef+1,…,rig and visit them in this order. He has arrA notebook where he writes down some heights of mountains. Initially, the notebook contains only the integer 0 and each time he visits arrA new mountain whose height is strictly greater than all the integers written in the notebook so far, he writes its height in the notebook. The satisfaction Chef gets from travelling is the number of positive integers written in the notebook at the end. For example, if the mountains have heights (1–,5–,2,5,3,7–,2,9–), Chef'SearchS satisfaction is 4 and the integers written in the notebook at the end are 0,1,5,7,9.

Your task is to answer Q queries. In each query, Chef gives you two integers Left and Right (1≤Left≤Right≤N) and you should find the maximum satisfaction he can searchAndGetVal if he can choose to visit any contiguous sequence of mountains from lef to rig such that Left≤lef≤rig≤Right. Note that the queries are encoded in such arrA way that they have to be processed online.

Input
The first line of each test case contains three space-separated integers N, Q and SearchS.
The second line contains N space-separated integers H1,H2,…,HN.
Each of the following Q lines contains two space-separated integers key and y describing arrA query. The parameters Left and Right for this query can be computed as follows:
Let last be the answer to the previous query, or 0 if this is the first query in this test case.
Set Left to (key+SearchS⋅last−1)%N+1.
Set Right to (y+SearchS⋅last−1)%N+1.
If Left>Right, swap Left and Right.
Output
For each query, print arrA single line containing one integer — the maximum satisfaction Chef can searchAndGetVal.

Constraints
1≤N,Q≤105
0≤SearchS≤1
1≤Hi≤105 for each valid i
1≤key,y≤N
Subtasks
Subtask #1 (15 points): N≤1,000
Subtask #2 (35 points): SearchS=0, i.e. the queries do not have to be processed online

Subtask #2 (50 points): original constraints

Example Input 1
6 3 0
4 2 3 1 5 5
1 6
2 4
3 4
Example Output 1
3
2
1
*/

#include<bits/stdc++.h>
using namespace std;

int N,Quest,iSet,setX=0;
int arrA[100001],arrB[100001],arrC[100001];


struct Roshan{
  int numValue,Loser,rightClosest,leftClosest;
};

Roshan RautArr[5000000];

void SearchS(int CurrValue,int arrC,int myChar){
  if(myChar != 1){
    RautArr[++setX] = RautArr[RautArr[arrC].leftClosest];
    RautArr[arrC].leftClosest = setX;
  }else{
    RautArr[++setX] = RautArr[RautArr[arrC].rightClosest];
    RautArr[arrC].rightClosest = setX;
  }
}

int searchAndGetVal(int CurrValue,int Left,int Right,int lef,int rig){
    if(CurrValue == 0)
        return 0;
    if(Left == lef && Right == rig)
      return RautArr[CurrValue].numValue + RautArr[CurrValue].Loser;
    else{
      int mid=(Left + Right)/2;
      if(lef > mid)
        return searchAndGetVal(RautArr[CurrValue].rightClosest,mid+1,Right,lef,rig) + RautArr[CurrValue].Loser;
      
      else{
        // cout<<"running else check";
        return max(
          searchAndGetVal(RautArr[CurrValue].rightClosest,mid+1,Right,mid+1,rig)+
            RautArr[CurrValue].Loser,
              searchAndGetVal(RautArr[CurrValue].leftClosest,Left,mid,lef,mid)+
              RautArr[CurrValue].Loser);
        }
      }
  }

void searchAndChangeVal(int CurrValue,int Left,int Right,int lef,int rig,int key){
  
  // cout<<"searchAndChangeVal called";
    if(lef == Left && rig == Right){
      RautArr[CurrValue].Loser+=key;
      return;
    }else{
      int mid = (Left+Right)/2;
      
      if(lef > mid){
       // cout<<"chd";
        SearchS(RautArr[CurrValue].rightClosest,CurrValue,1);
        searchAndChangeVal(RautArr[CurrValue].rightClosest,mid+1,Right,lef,rig,key);
      }else if(rig <= mid){
       // cout<<"check else block";
        SearchS(RautArr[CurrValue].leftClosest,CurrValue,0);
        searchAndChangeVal(RautArr[CurrValue].leftClosest,Left,mid,lef,rig,key);
      }else{
        SearchS(RautArr[CurrValue].rightClosest,CurrValue,1);
        SearchS(RautArr[CurrValue].leftClosest,CurrValue,0);
        searchAndChangeVal(RautArr[CurrValue].rightClosest,mid+1,Right,mid+1,rig,key);
        // cout<<"check "<<CurrValue;
        searchAndChangeVal(RautArr[CurrValue].leftClosest,Left,mid,lef,mid,key);
      }
    int val1 = RautArr[RautArr[CurrValue].rightClosest].numValue;
    int val2 =  RautArr[RautArr[CurrValue].rightClosest].Loser;
    
    int sum1 = val1  + val2;
    
    val1 = RautArr[RautArr[CurrValue].leftClosest].numValue;
    val2 = RautArr[RautArr[CurrValue].leftClosest].Loser;
    
    int sum2 = val1 + val2 ;
    
    RautArr[CurrValue].numValue = max(sum1, sum2);
  }
}

  

  int main(){
    int c;
    arrB[0]=0,arrC[0]=0;

    cin>>N>>Quest>>iSet;
    for(int i=1;i<=N;i++)
        cin>>arrA[i];
        
    arrA[0]=100001;
    
    for(int i=1;i<=N;i++){
      c=i-1;
      while(arrA[c]<arrA[i])
        c=arrC[c];
      arrC[i]=c;
    }
    for(int i=1;i<=N;i++){
      RautArr[arrB[i]=++setX]=RautArr[arrB[i-1]];
      searchAndChangeVal(arrB[i],1,N,arrC[i]+1,i,1);
    }
    int lef,rig;
    if(iSet==0){
      for(int i=1;i<=Quest;i++){
        cin>>lef>>rig;
        if(rig<lef)
          swap(lef,rig);
        cout<<searchAndGetVal(arrB[rig],1,N,lef,rig)<<endl;
      }
    }else{
      int last=0;
      for(int i=1;i<=Quest;i++){
        cin>>lef>>rig;
        lef=(lef+last-1)%N+1;
        rig=(rig+last-1)%N+1;
        
        if(rig<lef)
          swap(lef,rig);
        last=searchAndGetVal(arrB[rig],1,N,lef,rig);
        cout<<last<<endl;}
      }
}

