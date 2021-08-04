#include<iostream>
using namespace std;
char graph[251][251];
int m,n;
void dp(int xx,int yy,char ccolor,char tar){
	if(xx>=m||xx<0||yy>=n||yy<0||graph[xx][yy]!=tar)
		return;
	graph[xx][yy]=ccolor;
	dp(xx-1,yy,ccolor,tar);
	dp(xx,yy-1,ccolor,tar);
	dp(xx+1,yy,ccolor,tar);
	dp(xx,yy+1,ccolor,tar);
	return;
}
int main(){
	char in;
	int x,y,x1,x2,y1,y2;
	char color,name[1000];
	while(scanf("%c",&in)){
		if(in=='X')
			break;
		else if(in=='I'){
			scanf("%d %d",&n,&m);
			for(int i=0;i<m;++i)
				for(int j=0;j<n;++j)
					graph[i][j]='O';
		}
		else if(in=='C'){
			for(int i=0;i<m;++i)
				for(int j=0;j<n;++j)
					graph[i][j]='O';
		}
		else if(in=='L'){
			scanf("%d %d %c",&x,&y,&color);
			graph[y-1][x-1]=color;
		}
		else if(in=='V'){
			scanf("%d %d %d %c",&x,&y1,&y2,&color);
			if(y1>y2){
				int k=y1;
				y1=y2;
				y2=k;
			}
			for(int i=y1-1;i<=y2-1;++i)
				graph[i][x-1]=color;
		}
		else if(in=='H'){
			scanf("%d %d %d %c",&x1,&x2,&y,&color);
			if(x1>x2){
				int k=x1;
				x1=x2;
				x2=k;
			}
			for(int i=x1-1;i<=x2-1;++i)
				graph[y-1][i]=color;
		}
		else if(in=='K'){
			scanf("%d %d %d %d %c",&x1,&y1,&x2,&y2,&color);
			if(y1>y2){
				int k=y1;
				y1=y2;
				y2=k;
			}
			if(x1>x2){
				int k=x1;
				x1=x2;
				x2=k;
			}
			for(int i=x1-1;i<=x2-1;++i)
				for(int j=y1-1;j<=y2-1;++j)
					graph[j][i]=color;
		}
		else if(in=='F'){
			scanf("%d %d %c",&y,&x,&color);
			if(graph[x-1][y-1]!=color)
				dp(x-1,y-1,color,graph[x-1][y-1]);
		}
		else if(in=='S'){
			scanf("%s",name);
			puts(name);
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++)
					printf("%c",graph[i][j]);
				puts("");
			}
		}
	}
}