#include<iostream>
#include<cmath>
using namespace std;
bool prime[1000001];
int iscircle[1000001]={0};
int ans[1000001]={0};
int leng(int n){
	int r=0;
	while(n>0){
		n/=10;
		r++;
	}
	return r;
}
int checkcircle(int n){
	if(iscircle[n]==1)
		return 1;
	if(iscircle[n]==2)
		return 0;
	int l=leng(n);
	int c[9];
	c[0]=n;
	for(int i=1;i<l;i++){
		c[i]=c[i-1]/10+(c[i-1]%10)*pow(10,l-1);
	}
	for(int i=0;i<l;i++){
		if(iscircle[c[i]]==1)
			return 1;
		if(iscircle[c[i]]==2)
			return 0;
		if(!prime[c[i]]){
			for(int j=0;j<l;j++)
				iscircle[c[j]]=2;
			return 0;
		}
	}
	for(int j=0;j<l;j++)
		iscircle[c[j]]=1;
	return 1;
}
void init(void){
	prime[0]=prime[1]=0;
	prime[2]=1;
	for(int i=3;i<=1000000;i++)
		prime[i]=1;
	for(int i=2;i<=1000000;i++){
		if(prime[i])
			for(int j=2*i;j<=1000000;j+=i)
				prime[j]=0;
	}
	for(int i=2;i<=1000000;i++){
		ans[i]=ans[i-1]+checkcircle(i);
	}
	return;
}
int main(){
	int a,b;
	init();
	while(scanf("%d",&a)&&a!=-1){
		scanf("%d",&b);
		int cnt=ans[b]-ans[a-1];
		if(!cnt)
			printf("No Circular Primes.\n");
		else if(cnt==1)
			printf("1 Circular Prime.\n");
		else
			printf("%d Circular Primes.\n",cnt);
	}
}