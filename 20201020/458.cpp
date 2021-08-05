#include<iostream>
#define A -7
using namespace std;
int main(){
	string s;
	bool f=true;
	while(!cin.eof()){
		if(f)f=0;
		else cout<<endl;
		getline(cin,s);
		for(int i=0;i<s.length();i++)
			cout<<char(int(s[i])+A);
	}
}