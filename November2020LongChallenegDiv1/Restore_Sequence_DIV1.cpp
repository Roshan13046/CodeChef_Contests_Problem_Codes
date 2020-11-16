/*
Alice has a very complex machine ? when fed with a sequence A1,A2,…,AN, it produces a sequence B1,B2,…,BN, where for each valid i, Bi is the largest index j such that Ai divides Aj (since Ai divides itself, such an index always exist). For example, if the machine is fed with A=[2,6,5,3,4], it produces B=[5,2,3,4,5].

Alice gave you a sequence B that was produced by the machine. Find an integer sequence A such that when it is fed into the machine, then the machine produces the sequence B. Alice does not like huge integers, so make sure that 1=Ai=4·106 holds for each valid i.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers B1,B2,…,BN.
Output
For each test case, print a single line containing N space-separated integers A1,A2,…,AN. For each valid i, 1=Ai=4·106 should hold.

If there are multiple solutions, you may print any of them. It is guaranteed that at least one solution exists.

Constraints
1=T=2·104
1=N=105
1=Bi=N for each valid i
the sum of N over all test cases does not exceed 2·105
Subtasks
Subtask #1 (20 points): B1,B2,…,BN are pairwise distinct

Subtask #2 (80 points): original constraints

Example Input
2
5
5 2 3 4 5
4
4 4 4 4
Example Output
2 6 5 3 4
2 6 3 12
*/
#include<bits/stdc++.h> 
using namespace std; 
const long long Maxi_Size = 1299720; 

vector<long long >isprime(Maxi_Size , true); 
vector<long long >prime; 
vector<long long >ssppff(Maxi_Size); 


void findPrimesArr(int N) 
{ 
	isprime[0] = isprime[1] = false ; 

	for (long long int i=2; i<N ; i++) 
	{ 
		if (isprime[i]) 
		{ 
			prime.push_back(i); 
			ssppff[i] = i; 
		} 

		for (long long int j=0; 
			j < (int)prime.size() && 
			i*prime[j] < N && prime[j] <= ssppff[i]; 
			j++) 
		{ 
			isprime[i*prime[j]]= 0; 
			ssppff[i*prime[j]] = prime[j] ; 
		} 
	} 
} 

int main() 
{ 
	int N = 1299720 ;

	findPrimesArr(N); 
	int t,nSize;
	
  cin>>t;
  while(t--){
    cin>>nSize;
    int Barr[nSize+1];
    
    for(int i=1;i<=nSize; i++)
      cin>>Barr[i];
    
    int nPrimes[nSize+1];
    for (int i=0, count=1; i<prime.size() && prime[i] <= N ; i++) {
      if(count > nSize){
        break;
      }else{
        nPrimes[count] = prime[i];
        // cout<<prime[i]<<" ";
        count++;
      }
      
    }
  // for(int i=1;i<=nSize;i++)
  //   cout<<nPrimes[i]<<" ";
  //   cout<<endl;
    
    for(int i=1;i<=nSize;i++)  {
      if(Barr[i]!= i){
        nPrimes[i] = nPrimes[Barr[i]];
      }
    }
    
    for(int i=1;i<=nSize;i++)
      cout<<nPrimes[i]<<" ";
    cout<<endl; 
    
  }

	return 0; 
} 
/*
2
5
5 2 3 4 5
4
4 4 4 4

*/


