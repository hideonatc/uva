#include<iostream>
#include<stack>
using namespace std;
stack<string> pile[52];
int ch(int t,int a){
	int n=0;
	t--;
	while(n<a){
		if(!pile[t].empty())
			n++;
		t--;
	}
	t+=1;
	return t;
}
int rem_p(int t){
	int r=0;
	for(int i=t-1;i>=0;i--){
		if(!pile[i].empty())
			r++;
	}
	return r;
}
int main(){
	string s;
	while(cin>>s){
		if(s=="#")
			break;
		for(int i=0;i<52;i++)
			while(!pile[i].empty())
				pile[i].pop();
		pile[0].push(s);
		for(int i=1;i<52;i++){
			string s;
			cin>>s;
			pile[i].push(s);
		}
		bool can=1;
		while(can){
			can=0;
			for(int i=0;i<52;i++){
				if(pile[i].empty())
					continue;
				int idx=i;
				while(idx>0){
					bool han=0;
					if(rem_p(idx)>=3){
						if(pile[idx].top()[0]==pile[ch(idx,3)].top()[0]||pile[idx].top()[1]==pile[ch(idx,3)].top()[1]){
							//printf("ch(idx,3)=%d , move %c%c to pile[%d]\n",ch(idx,3),pile[idx].top()[0],pile[idx].top()[1],ch(idx,3));
							string m=pile[idx].top();
							pile[idx].pop();
							pile[ch(idx,3)].push(m);
							idx=ch(idx,3);
							han=1;
							can=1;
						}
					}
					if(!han&&rem_p(idx)>=1){
						if(pile[idx].top()[0]==pile[ch(idx,1)].top()[0]||pile[idx].top()[1]==pile[ch(idx,1)].top()[1]){
							//printf("ch(idx,1)=%d , move %c%c to pile[%d]\n",ch(idx,1),pile[idx].top()[0],pile[idx].top()[1],ch(idx,1));
							string m=pile[idx].top();
							pile[idx].pop();
							pile[ch(idx,1)].push(m);
							idx=ch(idx,1);
							han=1;
							can=1;
						}
					}
					if(!han)
						break;
				}
				if(can)
					break;
			}
		}
		int rem=0;
		int ans[52];
		for(int i=0;i<52;i++)
			if(!pile[i].empty())
				ans[rem++]=pile[i].size();
		if(rem>1)
			printf("%d piles remaining:",rem);
		else
			printf("%d pile remaining:",rem);
		for(int i=0;i<rem;i++)
			cout<<" "<<ans[i];
		cout<<endl;
	}
}

/*
QD AD 8H 5S 3H 5H TC 4D JH KS 6H 8S JS AC AS 8D 2H QS TS 3S AH 4H TH TD 3C 6S
8C 7D 4C 4S 7S 9H 7C 5D 2S KD 2D QH JD 6D 9D JC 2C KH 3D QC 6C 9S KC 7H 9C 5C
#
*/