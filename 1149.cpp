#include<iostream>
#include<algorithm>
using namespace std;
int m,w[10002];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>w[i];
		sort(w,w+n);
		int ans=0,s=0,e=n-1;
		while(s<=e){
			if(w[e]+w[s]<=m){
				e--;
				s++;
			}
			else e--;
			ans++;
		}
		cout<<ans<<endl;
		if(t) cout<<endl;
	}
	return 0;
}