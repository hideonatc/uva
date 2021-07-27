#include<iostream>
using namespace std;
bool finger[16][10]={{0,1,1,1,0,0,1,1,1,1},{0,1,1,1,0,0,1,1,1,0},{0,1,1,1,0,0,1,1,0,0},{0,1,1,1,0,0,1,0,0,0},{0,1,1,1,0,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0},{1,1,1,1,0,0,1,1,1,0},{1,1,1,1,0,0,1,1,0,0},{1,1,1,1,0,0,1,0,0,0},{1,1,1,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0}};
string tab="cdefgabCDEFGAB";
int find(char c){
	for(int i=0;i<16;i++)
		if(tab[i]==c)
			return i;
	return -1;
}
int main(){
	int t;
	cin>>t;
	string e;
	getline(cin,e);
	while(t--){
		int cnt[10]={0};
		bool now[10];
		for(int i=0;i<10;i++)
			now[i]=0;
		string s;
		getline(cin,s);
		for(int i=0;i<s.length();i++){
			for(int j=0;j<10;j++){
				if(finger[find(s[i])][j]==1&&now[j]==0){
					cnt[j]++;
				}
				now[j]=finger[find(s[i])][j];
			}
		}
		for(int i=0;i<10;i++){
			cout<<cnt[i];
			if(i!=9)
				cout<<" ";
		}
		cout<<endl;
	}
}