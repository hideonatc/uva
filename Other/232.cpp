#include<iostream>
using namespace std;
int narr[11][11]={0};
char arr[11][11];
void num(int r,int c){
	int n=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]!='*'){
				if(i>0&&j>0&&isalpha(arr[i-1][j])&&isalpha(arr[i][j-1]))
					narr[i][j]=0;
				else
					narr[i][j]=n++;
			}
			else
				narr[i][j]=0;
		}
	}
	return;
}
int main(){
	int r,c,n=1;
	while(cin>>r){
		if(r==0)
			break;
		if(n!=1)
			cout<<endl;
		cin>>c;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>arr[i][j];
			}
		}
		num(r,c);
		printf("puzzle #%d:\nAcross\n",n++);
		for(int i=0;i<r;i++){
			int j=0;
			string s="";
			while(j<c){
				if(arr[i][j]=='*'||j==c-1){
					if(arr[i][j]!='*')
						s+=arr[i][j++];
					if(s!=""){
						if(narr[i][j-s.length()]<10)
							cout<<" ";
						cout<<" "<<narr[i][j-s.length()]<<'.'<<s<<endl;
					}
					s="";
					j++;
				}
				else
					s+=arr[i][j++];
			}
		}
		printf("Down\n");
		string sarr[101];
		for(int i=0;i<=r*c;i++)
			sarr[i]="";
		for(int j=0;j<c;j++){
			int i=0;
			string s="";
			while(i<r){
				if(arr[i][j]=='*'||i==r-1){
					if(arr[i][j]!='*')
						s+=arr[i++][j];
					if(s!=""){
						sarr[narr[i-s.length()][j]]=s;
					}
					s="";
					i++;
				}
				else
					s+=arr[i++][j];
			}
		}
		for(int i=1;i<=r*c;i++){
			if(sarr[i]!=""){
				if(i<10)
						cout<<" ";
				cout<<" "<<i<<'.'<<sarr[i]<<endl;
			}
		}
	}
}