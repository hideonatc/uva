#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,d,r;
	while(cin>>n>>d>>r){
		if(!n&&!d&&!r)break;
		int am[101],pm[101];
		for(int i=0;i<n;i++)
			cin>>am[i];
		for(int i=0;i<n;i++)
			cin>>pm[i];
		sort(am,am+n);
		sort(pm,pm+n);
		int total=0;
		for(int i=0;i<n;i++)
			if(am[i]+pm[n-1-i]>d)
				total+=am[i]+pm[n-1-i]-d;
		cout<<total*r<<endl;
	}
}