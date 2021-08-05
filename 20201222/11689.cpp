#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int e,f,c;
		cin>>e>>f>>c;
		int t=e+f,ans=0;
		while(t>=c){
			t-=c-1;
			ans++;
		}
		cout<<ans<<endl;
	}
}