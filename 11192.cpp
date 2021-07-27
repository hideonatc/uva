#include<iostream>
using namespace std;
string rev(string s,int n){
	string r="";
	for(int i=n-1;i>=0;i--)
		r+=s[i];
	return r;
}
int main(){
	int n;
	while(cin>>n&&n){
		string s,ans="";
		cin>>s;
		n=s.length()/n;
		for(int i=0;i<s.length();i+=n){
			string c="";
			for(int j=0;j<n;j++)
				c+=s[i+j];
			ans+=rev(c,n);
		}
		cout<<ans<<endl;
	}
}