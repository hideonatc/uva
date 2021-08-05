#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,mn=999,mx=-1;
		cin>>n;
		while(n--){
			int p;
			cin>>p;
			if(p>mx)
				mx=p;
			if(p<mn)
				mn=p;
		}
		cout<<(mx-mn)*2<<endl;
	}
}