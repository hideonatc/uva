#include<iostream>
using namespace std;
int trans(int t){
	int r=0;
	while(t>=10){
		r+=t%10;
		t/=10;
	}
	r+=t;
	return r;
}
int main(){
	string s;
	while(cin>>s){
		if(s=="0")break;
		int total=0;
		int deg=0;
		for(int i=0;i<s.length();i++)
			total+=int(s[i]-int('0'));
		while(total%9==0){
			if(total==9){
				deg++;
				break;
			}
			deg++;
			total=trans(total);
		}
		if(deg){
			cout<<s;
			printf(" is a multiple of 9 and has 9-degree %d.\n",deg);
		}
		else
			cout<<s<<" is not a multiple of 9."<<endl;
	}
}