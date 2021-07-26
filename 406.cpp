#include<iostream>
using namespace std;
bool prime[1001];
int prime_list[1001],idx=0;
int prime_num[1001]={0};
void init(void){
	for(int i=0;i<1001;i++)
		prime[i]=1;
	prime[0]=false;
	for(int i=2;i<1001;i++){
		if(prime[i]){
			for(int j=2*i;j<1001;j+=i)
				prime[j]=false;
		}
	}
	for(int i=1;i<1001;i++)
		if(prime[i])
			prime_list[idx++]=i;
	for(int i=1;i<1001;i++){
		prime_num[i]=prime_num[i-1]+prime[i];
	}
	return;
}
void print(void){
	for(int i=0;i<idx;i++)
		cout<<prime_list[i]<<" ";
	cout<<endl;
	return;
}
int main(){
	init();
	int n,c;
	while(cin>>n>>c){
		printf("%d %d:",n,c);
		if(prime_num[n]%2){
			if(prime_num[n]<=2*c-1)
				for(int i=0;i<prime_num[n];i++)
					cout<<" "<<prime_list[i];
			else{
				int k=(prime_num[n]-1)/2;
				for(int i=k-c+1;i<=k+c-1;i++)
					cout<<" "<<prime_list[i];
			}
		}
		else{
			if(prime_num[n]<=2*c)
				for(int i=0;i<prime_num[n];i++)
					cout<<" "<<prime_list[i];
			else{
				int k=prime_num[n]/2-1;
				for(int i=k-c+1;i<=k+c;i++)
					cout<<" "<<prime_list[i];
			}
		}
		cout<<endl<<endl;
	}
}