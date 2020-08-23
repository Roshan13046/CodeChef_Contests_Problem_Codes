#include <iostream>
using namespace std;

int main() {

    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>k){
                sum += a[i]-k;
            }
        }
        cout<<sum<<endl;
    }

	return 0;
}

