#include<iostream>
using namespace std;
bool prime[1000001];
int ans[1000001]={0};
int todigit(int n){
	int r=0;
	while(n>0){
		r+=n%10;
		n/=10;
	}
	return r;
}
void init(void){
	for(int i=3;i<=1000000;i++)
		prime[i]=1;
	for(int i=2;i<=1000000;i++){
		if(prime[i])
			for(int j=2*i;j<=1000000;j+=i)
				prime[j]=0;
	}
	for(int i=2;i<=1000000;i++){
		ans[i]=ans[i-1]+(prime[todigit(i)]&&prime[i]);
		//printf("ans[%d]=%d\n",i,ans[i]);
	}
	return;
}
int main(){
	int n;
	prime[0]=prime[1]=0;
	prime[2]=1;
	init();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",ans[b]-ans[a-1]);
	}
}