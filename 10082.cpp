#include<iostream>
using namespace std;
string s1="1234567890-=",s2="QWERTYUIOP[]\\",s3="ASDFGHJKL;'",s4="ZXCVBNM,./";
char find(char c){
	for(int i=0;i<s1.length();i++)
		if(s1[i]==c)return s1[i-1];
	for(int i=0;i<s2.length();i++)
		if(s2[i]==c)return s2[i-1];
	for(int i=0;i<s3.length();i++)
		if(s3[i]==c)return s3[i-1];
	for(int i=0;i<s4.length();i++)
		if(s4[i]==c)return s4[i-1];
}
int main(){
	bool fir=1;
	while(!cin.eof()){
		if(fir)
			fir=0;
		else
			cout<<endl;
		string in;
		getline(cin,in);
		for(int i=0;i<in.length();i++){
			if(in[i]==' ')cout<<" ";
			else cout<<find(in[i]);
		}
	}
}