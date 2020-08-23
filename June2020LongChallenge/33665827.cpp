#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int n = str.length(),ans=0;
	    char a[n];
	    for(int i=0;i<n;i++){
	        a[i] = str[i];
	    }
	    for(int i=0;i<n;){
	        int j=i+1;
	        if(j<n && a[i]!='0' && a[j]!='0' && a[i] != a[j]){
	            a[i]=a[j]='0';
	            ans++;
	            i = j+1;
	        }else if(i>0 && a[i]!='0' && a[i-1]!='0' &&a[i] != a[i-1]){
	            a[i]=a[i-1]='0';
	            ans++;
	            i=i+1;
	        }else{
	            i++;
	        }
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
