#include<iostream>
#include<cmath>
using namespace std;
int isprime[1000001]={0};
int iscircle[1000001]={0};
bool checkprime(int n){
	if(isprime[n]==1)
		return 1;
	if(isprime[n]==2)
		return 0;
	for(int i=2;i<n/2;i++)
		if(n%i==0){
			isprime[n]=2;
			return 0;
		}
	isprime[n]=1;
	return 1;
}
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
		if(!checkprime(c[i])){
			for(int j=0;j<l;j++)
				iscircle[c[j]]=2;
			return 0;
		}
	}
	for(int j=0;j<l;j++)
		iscircle[c[j]]=1;
	return 1;
}
int main(){
	int a,b;
	while(scanf("%d",&a)&&a!=-1){
		scanf("%d",&b);
		int cnt=0;
		for(int i=a;i<=b;i++){
			cnt+=checkcircle(i);
			if(checkcircle(i))
				cout<<i<<",";
		}
		if(!cnt)
			printf("No Circular Primes.\n");
		else
			printf("%d Circular Prime.\n",cnt);
	}
}