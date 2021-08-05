#include<iostream>
#include<stack>
using namespace std;
bool ch(char a,char b){
	if(a=='('&&b==')')
		return 1;
	else if(a=='['&&b==']')
		return 1;
	else
		return 0;
}
int main(){
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		stack<char> st;
		for(int i=0;i<s.length();i++){
			if(st.empty())
				st.push(s[i]);
			else{
				if(ch(st.top(),s[i]))
					st.pop();
				else
					st.push(s[i]);
			}
		}
		if(st.empty())
			printf("Yes\n");
		else
			printf("No\n");
	}
}