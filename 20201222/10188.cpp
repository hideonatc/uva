#include<iostream>
#include<cstdlib>
using namespace std;
string numonly(string s){
	string r="";
	for(int i=0;i<s.length();i++)
		if(isdigit(s[i]))
			r+=s[i];
	return r;
}
int main(){
	int l1,l2,t=1;
	string e;
	while(cin>>l1&&l1){
		getline(cin,e);
		string in[101],ans[101];
		for(int i=0;i<l1;i++)
			getline(cin,ans[i]);
		cin>>l2;
		getline(cin,e);
		for(int i=0;i<l2;i++)
			getline(cin,in[i]);
		printf("Run #%d: ",t++);
		bool ac=true,pe=true;
		if(l1!=l2)
			ac=false;
		for(int i=0;l1==l2&&i<l1;i++){
			if(ans[i]!=in[i]){
				ac=false;
				break;
			}
		}
		string innum="",ansnum="";
		if(l1!=l2){
			while(l1>l2)
				in[++l2]="";
			while(l2>l1)
				ans[++l1]="";
		}
		for(int j=0;j<l1;j++){
			innum+=numonly(in[j]);
			ansnum+=numonly(ans[j]);
		}
		if(innum!=ansnum)
			pe=false;
		if(ac)
			printf("Accepted\n");
		else if(pe)
			printf("Presentation Error\n");
		else
			printf("Wrong Answer\n");
	}
}