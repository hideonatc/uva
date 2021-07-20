#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string line[101],e;
	int t=0,mx=-1;
	/*int n;
	cin>>n;
	getline(cin,e);*/
	while(!cin.eof()){
		getline(cin,line[t]);
		int l=line[t].length();
		if(l>mx){
			mx=l;
		}
		t++;
	}
	//cout<<t<<endl;
	for(int i=0;i<mx;i++){
		for(int j=t-2;j>=0;j--){
			if(i>line[j].length()-1){
				cout<<" ";
				continue;
			}
			cout<<line[j][i];
		}
		cout<<endl;
	}
}