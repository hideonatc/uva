#include<iostream>
using namespace std;
string a,b;
bool find(char c){
	for(int i=0;i<a.length();i++)
		if(c==a[i])
			return true;
	return false;
}
char sub(char c){
	for(int i=0;i<a.length();i++)
		if(c==a[i])
			return b[i];
	return '0';
}
int main(){
	int t;
	cin>>t;
	getline(cin,a);
	getline(cin,a);
	bool f=1;
	while(t--){
		if(f)f=0;
		else cout<<endl;
		getline(cin,a);
		getline(cin,b);
		string in;
		cout<<b<<endl<<a<<endl;
		while(getline(cin,in)){
			if(in=="")
				break;
			for(int i=0;i<in.length();i++){
				if(find(in[i]))
					cout<<sub(in[i]);
				else
					cout<<in[i];
			}
			cout<<endl;
		}
	}
}