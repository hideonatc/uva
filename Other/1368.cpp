#include<iostream>
using namespace std;
int toint(char c){
	if(c=='A')
		return 0;
	if(c=='C')
		return 1;
	if(c=='G')
		return 2;
	return 3;
}
char getmax(int a[4]){
	int m=max(max(a[0],a[1]),max(a[2],a[3]));
	if(m==a[0])
		return 'A';
	if(m==a[1])
		return 'C';
	if(m==a[2])
		return 'G';
	return 'T';
}
int error(string s,string c){
	int r=0;
	for(int i=0;i<s.length();i++)
		if(s[i]!=c[i]) r++;
	return r;
}
int main(){
	int n,m,l;
	cin>>n;
	while(n--){
		cin>>m>>l;
		string s[51];
		string res="";
		for(int i=1;i<=m;i++)
			cin>>s[i];
		for(int i=0;i<l;i++){
			int acgt[4]={0};
			for(int j=1;j<=m;j++)
				acgt[toint(s[j][i])]++;
			res+=getmax(acgt);
		}
		int e=0;
		for(int i=1;i<=m;i++)
			e+=error(res,s[i]);
		cout<<res<<endl<<e<<endl;
	}
}