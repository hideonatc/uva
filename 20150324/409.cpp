#include<iostream>
using namespace std;
int mx=-1;
int cp(string line,string key){
	int r=0;
	for(int i=0;i<line.length();i++){
		string s="";
		while(i!=line.length()&&isalpha(line[i])){
			s+=line[i];
			i++;
		}
		for(int i=0;i<s.length();i++)
			s[i]=tolower(s[i]);
		//cout<<"***"<<s<<" vs "<<key<<endl;
		if(s==key)
			r++;
	}
	//cout<<r<<endl;
	return r;
}
int main(){
	int n,m,t=1;
	while(cin>>n>>m){
		mx=-1;
		string kw[21],emp;
		getline(cin,emp);
		for(int i=0;i<n;i++)
			cin>>kw[i];
		getline(cin,emp);
		string line[21];
		for(int i=0;i<m;i++)
			getline(cin,line[i]);
		int num[21]={0};
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				num[i]+=cp(line[i],kw[j]);
				//cout<<num[i]<<endl;
				if(num[i]>mx)mx=num[i];
			}
		//cout<<mx<<endl;
		printf("Excuse Set #%d\n",t++);
		for(int i=0;i<m;i++)
			if(mx==num[i])
				cout<<line[i]<<endl;
		cout<<endl;
	}
}