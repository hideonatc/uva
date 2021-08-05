#include<iostream>
using namespace std;
int pw(int a){
	int r=1;
	for(int i=1;i<=a;i++)
		r*=2;
	return r;
}
int main(){
	int n;
	int cs=1;
	while(cin>>n){
		if(n==0)
			break;
		string s;
		getline(cin,s);
		getline(cin,s);
		string arr;
		cin>>arr;
		int c;
		cin>>c;
		printf("S-Tree #%d:\n",cs);
		for(int i=0;i<c;i++){
			string in;
			cin>>in;
			int tar=pw(n);
			for(int j=0;j<n;j++){
				if(in[j]=='0')
					tar-=pw(n-j-1);
			}
			cout<<arr[tar-1];
		}
		cout<<endl;
		cout<<endl;
		cs++;
	}
}