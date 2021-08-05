#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int w,l,hj=0,sj=0;
		cin>>l;
		for(int j=1;j<n;j++){
			cin>>w;
			if(w>l)hj++;
			else if(l>w)sj++;
			l=w;
		}
		printf("Case %d: %d %d\n",i,hj,sj);
	}
}