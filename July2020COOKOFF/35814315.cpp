#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

int test(ll arrA[],int n)
{
    int arrSize = n;
    map<ll,int>m;
        //start point
        for (int startPoint = 0; startPoint <arrSize ; startPoint++) {
            //group sizes
            for (int grps = startPoint; grps <=arrSize ; grps++) {
                //if start point = 1 then
                //grp size = 1 , print 1
                //grp size = 2, print 1 2
                //grp size = 3, print 1 2 3 ans so on
                vector<ll>v;
                for (int j = startPoint ; j < grps ; j++) {
                    v.push_back(arrA[j]);
                }
                
                if(v.size()>0){
                    ll t = v[0];
                for(int u = 1;u<v.size();u++){
                    t =t | v[u];
                }
               // cout<<t<<" ";
                v.clear();
                if(m[t] ==0)
                    m[t]++;  
                else
                    return 0;
                }
            }
        }
    
    return 1;
}    


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans = test(a,n);
        if(ans){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }
}

