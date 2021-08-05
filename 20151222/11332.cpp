#include<iostream>
using namespace std;
string solve(string s){
	if(s.length()==1)
		return s;
	int r=0;
	for(int i=0;i<s.length();i++)
		r+=int(s[i]-int('0'));
	string rs="";
	while(r>0){
		rs=char(r%10+int('0'))+rs;
		r/=10;
	}
	return solve(rs);
}
int main(){
	string in;
	while(cin>>in&&in!="0"){
		if(in.length()==1)
			cout<<in<<endl;
		else
			cout<<solve(in)<<endl;
	}
}