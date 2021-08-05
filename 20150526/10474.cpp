#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,q,in,t=1;
	int a[10001];
	bool f;
	while(cin>>n>>q&&n&&q){
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<q;i++){
			f=false;
			cin>>in;
			if(!i) printf("CASE# %d:\n",t++);
			for(int j=0;j<n;j++)
				if(a[j]==in){
					f=true;
					printf("%d found at %d\n",in,j+1);
					break;
				}
			if(!f) printf("%d not found\n",in);
		}
	}
}