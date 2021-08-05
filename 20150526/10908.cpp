#include<iostream>
using namespace std;
int m,n,r;
char arr[101][101];
void test(int a,int b,int l){
	bool c=1;
	if(a-l<0||a+l>m-1||b-l<0||b+l>n-1)
		c=0;
	for(int i=b-l;c&&i<=b+l;i++){
		if(arr[a-l][b-l]!=arr[a-l][i]||arr[a-l][b-l]!=arr[a+l][i]){
			c=0;
			break;
		}
	}
	for(int i=a-l;c&&i<=a+l;i++){
		if(arr[a-l][b-l]!=arr[i][b-l]||arr[a-l][b-l]!=arr[i][b+l]){
			c=0;
			break;
		}
	}
	if(c){
		r=l;
		test(a,b,l+1);
	}
	return;
}
int main(){
	int t,q,a,b;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>m>>n>>q;
		for(int j=0;j<m;j++)
			for(int k=0;k<n;k++)
				cin>>arr[j][k];
		for(int j=0;j<q;j++){
			if(!j)printf("%d %d %d\n",m,n,q);
			cin>>a>>b;
			test(a,b,0);
			if(m==0||n==0)cout<<0<<endl;
			else cout<<r*2+1<<endl;
		}
		if(m==0&&n==0&&q==0)printf("%d %d %d\n",m,n,q);
	}
}