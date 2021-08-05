#include<iostream>
#include<map>
using namespace std;
map<char,int> cnt;
void show(void){
	int tar=1;
	while(!cnt.empty()){
		bool f=false;
		for(map<char,int>::reverse_iterator it=cnt.rbegin(); it!=cnt.rend();it++){
			if(it->second==tar){
				printf("%d %d\n",int(it->first),it->second);
				cnt.erase(cnt.find(it->first));
				f=true;
				break;
			}
		}
		if(!f) tar++;
	}
	return;
}
int main(){
	string s;
	bool fir=1;
	while(getline(cin,s)){
		if(fir)
			fir=0;
		else
			cout<<endl;
		for(int i=0;i<s.length();i++)
			cnt[s[i]]++;
		show();
	}
}