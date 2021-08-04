#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
string tab="0123456789ABCDEF";
int trans(char c){
	for(int i=0;i<16;i++)
		if(c==tab[i])
			return i;
	return -1;
}
int todec(string s,int b){
	bool l=true;
	int r=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!='0')break;
		if(s[i]=='0'&&i==s.length()-1)return 0;
	}
	for(int i=0;i<s.length();i++){
		while(l&&s[i]=='0')
			i++;
		l=0;
		r+=int(pow(b,s.length()-1-i))*trans(s[i]);
	}
	return r;
}
string totar(int d,int a){
	if(d==0)return "0";
	string r="";
	if(d>=int(pow(a,7)))
		return "ERROR";
	for(int i=0;i<7;i++){
		r+=tab[d/int(pow(a,6-i))];
		d=d%int(pow(a,6-i));
	}
	while(r[0]=='0'){
		string n="";
		for(int i=1;i<r.length();i++)
			n+=r[i];
		r=n;
	}
	return r;
}
int main(){
	string s;
	int b,a;
	bool f=true;
	while(!cin.eof()){
		if(f)f=0;
		else cout<<endl;
		cin>>s>>b>>a;
		cout<<setw(7)<<totar(todec(s,b),a);
	}
}