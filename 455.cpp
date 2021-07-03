#include<iostream>
using namespace std;
int main(){
	string bk;
	int t;
	cin>>t;
	getline(cin,bk);
	while(t--){
		string s;
		cin>>s;
		getline(cin,bk);
		int i;
		for(i=1;i<=s.length();i++){
			bool flag = true;
			for(int j=0;j<s.length()-i;j++){
				if(s[j]!=s[j+i]||s.length()%i){
					flag = false;
					break;
				}
			}
			if(flag)
				break;
		}
		cout<<i<<endl;
		if(t>=1)
			cout<<endl;
	}
}