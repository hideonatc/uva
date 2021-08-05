#include<iostream>
#define ulli unsigned long long int
ulli cn2(ulli n){
	return n*(n-1)/2;
}
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		if(!a&&!b)break;
		ulli ans=0;
		ulli x=max(a,b),y=min(a,b);
		int dy=(x-y)+1;
		ans+=cn2(y)*dy;
		for(ulli i=y-1;i>=2;i--){
			ans+=cn2(i)*2;
		}
		ans*=2;
		ans+=cn2(y)*x;
		ans+=cn2(x)*y;
		ans*=2;
		cout<<ans<<endl;
	}
}