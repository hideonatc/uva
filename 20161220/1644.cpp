#include<iostream>
#define max 1300000
using namespace std;
bool prime[max];
int gap[max];
void init(void){
	for(int i=0;i<max;i++){
		prime[i]=1;
		gap[i]=1;
	}
	for(int i=2;i*i<max;i++)
		if(prime[i])
			for(int j=i*i;j<max;j+=i)
				prime[j]=0;
	int cnt=0;
	gap[0]=gap[1]=0;
	for(int i=2;i<max;i++){
		if(prime[i]){
			for(int j=i-1;gap[j]!=0;j--)
				gap[j]=cnt+1;
			gap[i]=0;
			cnt=0;
		}
		else
			cnt++;
	}
	return;
}
int main(){
	init();
	int n;
	while(cin>>n&&n)
		cout<<gap[n]<<endl;
}