
#include<bits/stdc++.h>
using namespace std;

string IceCream(int a[],int n){
    map<int,int>chefBank;
    bool got[n];
    for(int i=0;i<n;i++){
        
            if(i == 0){
                if(a[i] == 5){
                    chefBank[a[i]]++;
                    got[i]=true;    
                }else{
                    return "NO";
                }  
            }
        
            else if(a[i] == 5 && i>0){
                chefBank[a[i]]++;
                got[i]=true;
            }else if(a[i] >5){
                if(a[i]==10){
                    chefBank[10]++;
                    if(chefBank[5]>0){
                        chefBank[5]--;
                        got[i] =true;
                    }else{
                        return "NO";
                    }
                }else if(a[i]==15){
                    chefBank[15]++;
                    //give change of 10
                    if(chefBank[10]>0){
                        chefBank[10]--;
                        got[i] = true;
                    }else if(chefBank[5]>=2){
                        chefBank[5] -= 2;
                        got[i] = true;
                    }else{
                        return "NO";
                    }
                }
            }else{
                return "NO";
            }
    }
    return "YES";
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
       cout<<IceCream(a,n)<<endl;
    }
}