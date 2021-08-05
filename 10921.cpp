#include<iostream>
using namespace std;
int trans[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int main(){
	string s;
	bool f=1;
	while(!cin.eof()){
		if(f)f=0;
		else cout<<endl;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(isupper(s[i]))
				cout<<trans[int(s[i])-int('A')];
			else
				cout<<s[i];
		}
	}
}