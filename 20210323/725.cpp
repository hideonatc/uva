#include<iostream>
#include<set>
using namespace std;
int tab[80][100],n;
int rp[99999];
set<int> k;
bool rep(int n){
	int sv=n;
	if(rp[n]==1)
		return true;
	else if(rp[n]==2)
		return false;
	if(n<10000) k.insert(0);
	while(n>0){
		int l=n%10;
		if(k.count(l)){
			rp[sv]=1;
			return true;
		}
		k.insert(l);
		n/=10;
	}
	rp[n]=2;
	return false;
}
bool rep2(int n){
	if(n>99999){
		return true;
	}
	if(rp[n]==1)
		return true;
	else if(rp[n]==2)
		return false;
	if(n<10000){
		if(k.count(0))
			return true;
		k.insert(0);
	}
	while(n>0){
		int l=n%10;
		if(k.count(l))
			return true;
		n/=10;
		k.insert(l);
	}
	return false;
}
void prt(int n,int i){
	if(n*tab[n][i]<10000)
		cout<<"0";
	cout<<n*tab[n][i]<<" / ";
	if(tab[n][i]<10000)
		cout<<"0";
	cout<<tab[n][i]<<" = "<<n<<endl;
	return;
}
void init(void){
	for(int i=0;i<80;++i)
		for(int j=0;j<100;++j)
			tab[i][j]=0;
	for(int i=2;i<80;++i){
		int idx=0;
		for(int j=1023;j<=98765;++j){
			k.clear();
			if(!rep(j)){
				if(!rep2(i*j))
					tab[i][idx++]=j;
			}
		}
	}
	return;
}
int main(){
	for(int i=0;i<99999;i++)
		rp[i]=0;
	init();
	while(cin>>n&&n){
		if(tab[n][0]==0)
			printf("There are no solutions for %d.\n",n);
		else 
			for(int i=0;tab[n][i]!=0;i++)
				prt(n,i);
		cout<<endl;
	}
}