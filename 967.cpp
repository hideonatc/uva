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
	for(int i=2;i<n/2+1;i++)
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
	while(cin>>a&&a!=-1){
		cin>>b;
		int cnt=0;
		for(int i=a;i<=b;i++){
			if(iscircle[i]==1)
				cnt++;
			if(iscircle[i]==0){
				cnt+=checkcircle(i);
			}
		}
		if(!cnt)
			printf("No Circular Primes.\n");
		else
			printf("%d Circular Prime.\n",cnt);
	}
}