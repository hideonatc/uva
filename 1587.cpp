#include<iostream>
#include<set>
#include<map>
using namespace std;
int tab1[13][3]={{0,2,4},{4,2,0},{2,0,4},{4,0,2},{0,4,2},{2,4,0},{2,2,2},{1,2,3},{3,2,1},{2,3,1},{1,3,2},{3,1,2},{2,1,3}};
int tab2[4][2]={{}}
int main(){
	int arr[6][2];
	while(!cin.eof()){
		map<int,int> st;
		map<int,int> m;
		st.clear();
		m.clear();
		for(int i=0;i<6;i++){
			cin>>arr[i][0]>>arr[i][1];
			if(!st.count(arr[i][0])){
				m[arr[i][0]]=1;
				st[arr[i][0]]=1;
			}
			else{
				m[arr[i][0]]++;
				st[arr[i][0]]++;
			}
			if(!st.count(arr[i][1])){
				st[arr[i][1]]=1;
			}
			else
				st[arr[i][1]]++;
		}
		if(st.size()>3){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			for(int i=0;i<13;i++){
				bool ans=1;
				int j=0;
				//printf("test tab[%d][%d]\n",i,j);
				for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
					//cout<<it->second<<endl;
					if(it->second!=tab[i][j++])
						ans=false;
				}
				if(ans){
					cout<<"POSSIBLE"<<endl;
					break;
				}
				if(!ans&&i==12)
					cout<<"IMPOSSIBLE"<<endl;
			}
		}
	}
}