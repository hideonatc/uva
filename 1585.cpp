#include<iostream>
using namespace std;
int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		int sc = 0 , idx = 1;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s[i]=='X') idx = 0;
			sc += idx++;
		}
		cout<<sc<<endl;
	}
}