#include<iostream>
using namespace std;
bool tab[10][7]={{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
void p(int n,char c){
	for(int i=0;i<n;i++)
		cout<<c;
	return;
}
int main(){
	int n;
	string s;
	while(cin>>n>>s&&!(n==0&&s=="0")){
		if(n==0){
			cout<<endl;
			continue;
		}
		for(int i=0;i<s.length();i++){
			p(1,' ');
			if(tab[int(s[i])-int('0')][0]) p(n,'-');
			else p(n,' ');
			p(1,' ');
			if(i!=s.length()-1) p(1,' ');
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<s.length();j++){
				if(tab[int(s[j])-int('0')][5]) p(1,'|');
				else p(1,' ');
				p(n,' ');
				if(tab[int(s[j])-int('0')][1]) p(1,'|');
				else p(1,' ');
				if(j!=s.length()-1) p(1,' ');
			}
			cout<<endl;
		}
		for(int i=0;i<s.length();i++){
			p(1,' ');
			if(tab[int(s[i])-int('0')][6]) p(n,'-');
			else p(n,' ');
			p(1,' ');
			if(i!=s.length()-1) p(1,' ');
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<s.length();j++){
				if(tab[int(s[j])-int('0')][4]) p(1,'|');
				else p(1,' ');
				p(n,' ');
				if(tab[int(s[j])-int('0')][2]) p(1,'|');
				else p(1,' ');
				if(j!=s.length()-1) p(1,' ');
			}
			cout<<endl;
		}
		for(int i=0;i<s.length();i++){
			p(1,' ');
			if(tab[int(s[i])-int('0')][3]) p(n,'-');
			else p(n,' ');
			p(1,' ');
			if(i!=s.length()-1) p(1,' ');
		}
		cout<<endl<<endl;
	}
}