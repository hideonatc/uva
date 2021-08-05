#include<iostream>
using namespace std;
//  2011/1/1 Friday
int md[12]={0,31,59,90,120,151,181,212,243,273,304,334};
string day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main(){
	int t;
	cin>>t;
	while(t--){
		int m,d;
		cin>>m>>d;
		int k=md[m-1]+d;
		cout<<day[(k%7+4)%7]<<endl;
	}
}