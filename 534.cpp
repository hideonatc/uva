//unfinished , time limit exceeded
#include<iostream>
#include<cmath>
using namespace std;
double map[202][202],pos[202][2]={0};
bool vis[202]={0};
double ds(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double mn=1e9;
void bt(int s,int e,int p,double f){
	//printf("bt(%d,%d,%d,%f) mn=%f \n",s,e,p,f,mn);
	if(p==e){
		if(f<mn) mn=f;
		return;
	}
	for(int i=s+1;i<=e;i++){
		if(!vis[i]){
			vis[i]=1;
			bt(s,e,i,max(f,ds(pos[i][0],pos[i][1],pos[p][0],pos[p][1])));
			vis[i]=0;
		}
	}
	return;
}
int main(){
	int n,t=1;
	while(cin>>n){
		if(!n)break;
		cin>>pos[0][0]>>pos[0][1]>>pos[n-1][0]>>pos[n-1][1];
		for(int i=1;i<n-1;i++)
			cin>>pos[i][0]>>pos[i][1];
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j]=ds(pos[i][0],pos[i][1],pos[j][0],pos[j][1]);
			}
		}*/
		bt(0,n-1,0,-1);
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",t++,mn);
	}
}