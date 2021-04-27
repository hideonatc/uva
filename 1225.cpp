#include<iostream>
using namespace std;
inline void count(int n ,int arr[][10]){
	int k=n;
	for(int i=0;i<10;i++)
		arr[k][i]=arr[k-1][i];
	while(n>0){
		arr[k][n%10]++;
		n/=10;
	}
	return;
}
int main(){
	int cnt[10001][10]={0};
	for(int i=1;i<=10000;i++)
		count(i,cnt);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<9;i++)
			cout<<cnt[n][i]<<" ";
		cout<<cnt[n][9]<<endl;
	}
}