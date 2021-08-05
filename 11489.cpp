#include<iostream>
using namespace std;
bool en;
string solve(string s){
	int tol=0;
	for(int i=0;i<s.length();i++)
		tol+=int(s[i])-int('0');
	for(int i=0;i<s.length();i++)
		if(s[i]!='0'&&(tol-int(s[i])-int('0'))%3==0){
			s[i]='0';
			return s;
		}
	en=true;
	return "end";
}
int main(){
	int t;
	cin>>t;
	int k=0;
	while(t--){
		en=0;
		string n;
		cin>>n;
		int p=1;
		while(!en){
			n=solve(n);
			if(p==1) p=2;
			else p=1;
		}
		printf("Case %d: %c\n",++k,(p==1)?'S':'T');
	}
}