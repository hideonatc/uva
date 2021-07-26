#include<iostream>
using namespace std;
int main(){
	int n,arr[10];
	cin>>n;
	cout<<"Lumberjacks:"<<endl;
	for(int k=0;k<n;k++){
		bool o1=true,o2=true;
		cin>>arr[0];
		for(int i=1;i<10;i++){
			cin>>arr[i];
			if(arr[i]<arr[i-1])
				o1=false;
			if(arr[i]>arr[i-1])
				o2=false;
		}
		if(o1||o2)
			cout<<"Ordered"<<endl;
		else
			cout<<"Unordered"<<endl;
	}
}