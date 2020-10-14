// Problem Stmt Link : https://www.codechef.com/problems/REPLESX

#include <bits/stdc++.h>
using namespace std;


int correctIndex(int*, int , int , int );

void solve() {
  
  int n, x, p, k;
  
  cin>>n>>x>>p>>k;
  
  int a[n];
  
  for(int i=0;i<n;i++)
    cin >> a[i];
    
  sort(a, a+n);
  
  int indx = correctIndex(a, n, x, p);
  int counter = 0;
  
  if(a[indx] != x) {
    a[k-1] = x;
    sort(a, a+n);
    counter++;
  }
  
  if(p < k && a[p-1] < x) {
    cout << "-1";
    return;
  }
  
  if(a[p-1] == x) {
    cout << counter;
    return;
  }
  
  if(p > k && a[p-1] > x) {
    cout <<"-1";
    return;
  }
  
  indx = correctIndex(a, n, x, p)+1;
  cout << abs(indx - p) + counter;
  
  return;
  
}


int correctIndex(int a[], int n, int x, int p) {
  
  int mini = INT_MAX, minimumP=0;
  
  for(int i=1;i<n;i++){
    
    if(a[i] == x) {
      if(abs(p-i) < mini) {
        mini = abs(p-i);
        minimumP = i;
      }
    }
  }
  
  return minimumP;  
}


int main() {
  
  int t ;
  
  cin >> t;
  
  while(t--) {
    solve();
    cout<<endl;
  } 
  
}



