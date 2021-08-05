//unfinished
#include<iostream>
using namespace std;
char pz[5][5];
void printpz(bool e){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(j==4)cout<<pz[i][j]<<endl;
			else cout<<pz[i][j]<<' ';
		}
	}
	if(!e)cout<<endl;
	return;
}
struct point{
	int x,y;
}p;
int main(){
	string on,in;
	int n=1;
	while(1){
		bool end=false;
		for(int i=0;i<5;i++){
			getline(cin,on);
			if(n!=1&&i==0)getline(cin,on);
			if(on[0]=='Z'){
				end=true;
				break;
			}
			for(int j=0;j<5;j++){
				pz[i][j]=on[j];
				if(on[j]==' '){
					p.x=i;
					p.y=j;
				}
			}
		}
		//printpz();
		if(end)break;
		bool error = false , fin = false;
		while(cin>>in){
			for(int i=0;i<in.length();i++){
				if(in[i]=='A'&&p.x>0){
					swap(pz[p.x][p.y],pz[p.x-1][p.y]);
					p.x-=1;
				}
				else if(in[i]=='B'&&p.x<4){
					swap(pz[p.x][p.y],pz[p.x+1][p.y]);
					p.x+=1;
				}
				else if(in[i]=='L'&&p.y>0){
					swap(pz[p.x][p.y],pz[p.x][p.y-1]);
					p.y-=1;
				}
				else if(in[i]=='R'&&p.y<4){
					swap(pz[p.x][p.y],pz[p.x][p.y+1]);
					p.y+=1;
				}
				else if(in[i]=='0'){
					fin = true;
					break;
				}
				else{
					printf("error at i=%d\n",i);
					error = true;
				}
			}
			if(fin)break;
		}
		printf("Puzzle #%d:\n",n++);
		if(error){
			printf("This puzzle has no final configuration.\n");
			if(!end)cout<<endl;
			continue;
		}
		printpz(end);
	}
}
/*
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAAAABBRRRLL0
Z
*/