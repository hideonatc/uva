#include<iostream>
using namespace std;
int fb[1000001];
void init(void){
	fb[0]=fb[1]=1;
	for(int i=2;;i++){
		//printf("fb[%d]=%d\n",i-1,fb[i-1]);
		if(fb[i-1]+fb[i-2]>100000000){
			return;
		}
		fb[i]=fb[i-1]+fb[i-2];
	}
	return;
}
void solve(int t){
	int idx=0;
	while(idx<38&&t>=fb[idx+1])
		idx++;
	int r=t;
	cout<<r<<" = ";
	while(idx){
		if(r>=fb[idx]){
			cout<<"1";
			r-=fb[idx--];
		}
		else{
			cout<<"0";
			idx--;
		}
	}
	cout<<" (fib)"<<endl;
	return;
}
int main(){
	init();
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		solve(t);
	}
}