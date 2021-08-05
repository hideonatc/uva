#include<iostream>
using namespace std;
int main(){
	int n,m,t=1;
	while(cin>>n&&n){
		int an[1001],am[26];
		for(int i=0;i<n;i++)
			cin>>an[i];
		cin>>m;
		for(int i=0;i<m;i++)
			cin>>am[i];
		int ans;
		printf("Case %d:\n",t++);
		for(int k=0;k<m;k++){
			bool done=false;
			for(int i=0;i<n&&!done;i++){
				for(int j=0;j<i&&!done;j++){
					if(an[i]+an[j]==am[k]){
						ans=am[k];
						done=true;
					}
					if(abs(an[i]+an[j]-am[k])<abs(ans-am[k]))
						ans=an[i]+an[j];
				}
			}
			printf("Closest sum to %d is %d.\n",am[k],ans);
		}
	}
}