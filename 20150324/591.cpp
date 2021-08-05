#include<iostream>
using namespace std;
int main(){
	int total,n;
	int t=1;
	while(cin>>n){
		total=0;
		if(n==0)break;
		int k[101]={0};
		for(int i=1;i<=n;i++){
			cin>>k[i];
			total+=k[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(k[i]<total/n)
				ans+=total/n-k[i];
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",t++,ans);
	}
}