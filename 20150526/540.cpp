#include<iostream>
#include<queue>
#include<set>
using namespace std;
int t;
set<int> team[1001];
queue<int> teamlist;
queue<int> plist[1001];
void clearall(void){
	for(int i=0;i<1001;i++){
		team[i].clear();
		while(!plist[i].empty())
			plist[i].pop();
	}
	while(!teamlist.empty())
			teamlist.pop();
	return;
}
int findteam(int n){
	for(int i=0;i<t;i++){
		if(team[i].count(n))
			return i;
	}
	return 0;
}
int main(){
	int k=1;
	while(cin>>t&&t){
		clearall();
		printf("Scenario #%d\n",k++);
		int l;
		for(int i=0;i<t;i++){
			cin>>l;
			for(int j=0;j<l;j++){
				int n;
				cin>>n;
				team[i].insert(n);
			}
		}
		string cmd;
		while(cin>>cmd&&cmd!="STOP"){
			if(cmd=="ENQUEUE"){
				int n;
				cin>>n;
				int tn=findteam(n);
				if(plist[tn].empty()){
					teamlist.push(tn);
				}
				plist[tn].push(n);
			}
			else if(cmd=="DEQUEUE"){
				int tn=teamlist.front();
				cout<<plist[tn].front()<<endl;
				plist[tn].pop();
				if(plist[tn].empty()){
					teamlist.pop();
				}
			}
		}
		cout<<endl;
	}
}