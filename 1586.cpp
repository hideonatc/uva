#include<iostream>
#include<ctype.h>
using namespace std;
inline double g(char c,int n){
	if(c=='C') return 12.01*n;
	if(c=='H') return 1.008*n;
	if(c=='O') return 16.00*n;
	return 14.01*n;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = 0;
		double ans = 0;
		char c;
		for(int i=0;i<s.length();i++){
			c = s[i];
			if(i==s.length()-1||isalpha(s[i+1])) n = 1;
			else
				while(i+1<s.length()&&!isalpha(s[i+1]))
					n = n*10+int(s[++i])-int('0');	
			ans+=g(c,n);
			n = 0;
		}
		printf("%.3f\n",ans);
	}
}