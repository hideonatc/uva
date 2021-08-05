#include<iostream>
using namespace std;
struct cor{
	double x,y;
	bool operator==(const cor& a) const
    {
        return (x == a.x && y == a.y);
    }
    bool operator!=(const cor& a) const
    {
        return (x != a.x && y != a.y);
    }
    cor& operator=(const cor& a)
    {
        x=a.x;
        y=a.y;
        return *this;
    }
}ip[4],pt[3];
int main(){
	bool f=1;
	while(!cin.eof()){
		if(f)
			f=0;
		else
			cout<<endl;
		for(int i=0;i<4;i++)
			cin>>ip[i].x>>ip[i].y;
		for(int i=0;i<2;i++)
			for(int j=2;j<4;j++)
				if(ip[i]==ip[j]){
					pt[0]=ip[i];
					break;
				}
		for(int i=0,idx=1;i<4;i++){
			if(!(ip[i]==pt[0])){
				pt[idx++]=ip[i];
			}
		}
		printf("%.3lf ",pt[1].x+(pt[2].x-pt[0].x));
		printf("%.3lf",pt[1].y+(pt[2].y-pt[0].y));
	}
}