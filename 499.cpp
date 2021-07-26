#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		int cnt[53]={0};
		for(int i=0;i<s.length();i++){
			if(isupper(s[i]))
				cnt[int(s[i]-int('A'))]++;
			else if(islower(s[i]))
				cnt[int(s[i]-int('a'))+26]++;
		}
		int mx=-1;
		string ans="";
		for(int i=0;i<52;i++)
			if(cnt[i]>mx)
				mx=cnt[i];
		for(int i=0;i<26;i++)
			if(cnt[i]==mx)
				ans+=char(i+int('A'));
		for(int i=26;i<52;i++)
			if(cnt[i]==mx)
				ans+=char(i-26+int('a'));
		cout<<ans<<" "<<mx<<endl;
	}
}