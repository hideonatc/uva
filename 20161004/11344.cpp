#include<iostream>
#include<cmath>
using namespace std;
bool by2(string n){
	if((int(n[n.length()-1])-int('0'))%2==0)
		return 1;
	return false;
}
bool by3(string n){
	int t=0;
	for(int i=0;i<n.length();i++){
		t+=int(n[i])-int('0');
	}
	if(t%3==0)
		return 1;
	return 0;
}
bool by4(string n){
	int last=0;
	last+=int(n[n.length()-1])-int('0');
	last+=(int(n[n.length()-2])-int('0'))*10;
	last+=(int(n[n.length()-3])-int('0'))*100;
	if(last%4==0)
		return 1;
	return 0;
}
bool by5(string n){
	if(n[n.length()-1]=='0'||n[n.length()-1]=='5')
		return 1;
	return 0;
}
bool by6(string n){
	if(by2(n)&&by3(n))
		return 1;
	return 0;
}
int strtoint(string n){
	int r=0;
	for(int i=0;i<n.length();i++){
		r+=(int(n[i])-int('0'))*pow(10,n.length()-i-1);
	}
	return r;
}
bool by7(string n){
	if(n.length()<=8){
		if(strtoint(n)%7==0)
			return 1;
		else
			return 0;
	}
	else{
		int l2=0,l=int(n[n.length()-1])-int('0');
		l*=2;
		l2+=int(n[n.length()-2])-int('0')+10*(int(n[n.length()-3])-int('0'));
		l2-=l;
		string nw="";
		for(int i=0;i<n.length()-3;i++)
			nw+=n[i];
		if(l2<10)
			nw+='0';
		else
			nw+=char(l2/10+int('0'));
		nw+=char(l2%10+int('0'));
		return by7(nw);
	}
	return 0;
}
bool by8(string n){
	string s="";
	if(n.length()<=4){
		if(strtoint(n)%8==0)
			return 1;
		return 0;
	}
	else{
		for(int i=3;i>0;i--)
			s+=n[n.length()-i];
		return by8(s);
	}
	return 0;
}
bool by9(string n){
	int t=0;
	for(int i=0;i<n.length();i++)
		t+=int(n[i])-int('0');
	if(t%9==0)
		return 1;
	return 0;
}
bool by10(string n){
	if(n[n.length()-1]=='0')
		return 1;
	return 0;
}
bool by11(string n){
	int odd=0,even=0;
	if(n=="0")
		return 1;
	for(int i=0;i<n.length();i+=2)
		odd+=int(n[i])-int('0');
	for(int i=1;i<n.length();i+=2)
		even+=int(n[i])-int('0');
	if(abs(odd-even)%11==0)
		return 1;
	return 0;
}
bool by12(string n){
	if(by3(n)&&by4(n))
		return 1;
	return 0;
}
int main(){
	int n;
	cin>>n;
	bool f=1;
	while(n--){
		if(f)f=0;
		else cout<<endl;
		string m;
		cin>>m;
		int t;
		cin>>t;
		bool ans=1;
		for(int i=0;i<t;i++){
			int c;
			cin>>c;
			if(c==2)
				if(!by2(m)){
					ans=0;
					break;
				}
			if(c==3)
				if(!by3(m)){
					ans=0;
					break;
				}
			if(c==4)
				if(!by4(m)){
					ans=0;
					break;
				}
			if(c==5)
				if(!by5(m)){
					ans=0;
					break;
				}
			if(c==6)
				if(!by6(m)){
					ans=0;
					break;
				}
			if(c==7)
				if(!by7(m)){
					ans=0;
					break;
				}
			if(c==8)
				if(!by8(m)){
					ans=0;
					break;
				}
			if(c==9)
				if(!by9(m)){
					ans=0;
					break;
				}
			if(c==10)
				if(!by10(m)){
					ans=0;
					break;
				}
			if(c==11)
				if(!by11(m)){
					ans=0;
					break;
				}
			if(c==12)
				if(!by12(m)){
					ans=0;
					break;
				}
		}
		if(ans)
			cout<<m<<" - Wonderful.";
		else
			cout<<m<<" - Simple.";
	}
}