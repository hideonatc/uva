//unfinished fuck you ^^
#include<iostream>
#include<set>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(!n)
			break;
		set<string> s;
		string in;
		for(int i=1;i<=n;i++){
			cin>>in;
			s.insert(in);
		}
		string s1,s2;
		set<string>::iterator it=s.begin();
		for(int i=1;i<n/2;i++)
			it++;
		s1=*it;
		it++;
		s2=*it;
		for(int i=0;i<s1.length();i++){
			if(s1[i]==s2[i])
				cout<<s1[i];
			else if(s1[i]==char(int(s2[i])-1)&&i+1==s2.length()){
				if(i+1==s1.length())
					cout<<s1[i];
				else if(i+2==s1.length())
					cout<<s1[i]<<s1[i+1];
				else{
					cout<<s1[i];
					i++;
					while(i<s1.length()){
						if(s1[i]=='Z')
							cout<<'Z';
						else{
							cout<<char(int(s1[i])+1);
							break;
						}
						i++;
					}
				}
				break;
			}
			else{
				if(i+1==s1.length())
					cout<<s1[i];
				else
					cout<<char(int(s1[i])+1);
				break;
			}
		}
		cout<<endl;
	}
}