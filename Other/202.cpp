//unfinished
#include<iostream>
using namespace std;
bool check(string s){
	int l=(s.length()-1)/2;
	for(int i=1;i<=l;i++)
		if(s[i]!=s[i+l])
			return 0;
	return 1;
}
int main(){
	int a,b;
	while(!cin.eof()){
		cin>>a>>b;
		int p=a/b;
		string ans=".";
		int r=a%b;
		int t=0;
		string rp="";
		int cycle;
		while(++t){
			ans+=char(int(r*10/b)+int('0'));
			r=(r*10)%b;
			if(!r){
				rp="0";
				cycle=1;
				break;
			}
			if(t%2==0)
				if(check(ans)){
					for(int i=1;i<=(ans.length()-1)/2;i++)
						rp+=ans[i];
					cycle=(ans.length()-1)/2;
					break;
				}
		}
		if(rp.length()>50){
			string m="";
			for(int i=0;i<50;i++)
				m+=rp[i];
			m+="...";
			rp=m;
		}
		printf("%d/%d = %d",a,b,p);
		cout<<ans<<"("<<rp<<")"<<endl;
		printf("   %d = number of digits in repeating cycle\n",cycle);
	}
}