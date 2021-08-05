#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,p,h[101];
		cin>>n>>p;
		for(int i=0;i<p;i++)
			cin>>h[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i%7==6||i%7==0)
				continue;
			for(int j=0;j<p;j++)
				if(i%h[j]==0){
					ans++;
					break;
				}
		}
		cout<<ans<<endl;
	}
}