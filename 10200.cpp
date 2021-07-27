#include<iostream>
#define MAX 100100000
using namespace std;
bool prime[MAX];
bool euler[10001];
int euler_num[10001]={0};
int func(int n){
	return n*n+n+41;
}
void init(void){
	for(int i=0;i<MAX;i++)
		prime[i]=1;
	for(int i=2;i*i<MAX;i++)
		if(prime[i])
			for(int j=i*i;j<MAX;j+=i)
				prime[j]=0;
	for(int i=0;i<10001;i++){
		if(prime[func(i)]){
			//printf("prime[func(%d)]=1\n",i);
			euler[i]=1;
		}
		else{
			euler[i]=0;
			//printf("prime[func(%d)]=0\n",i);
		}
	}
	euler_num[0]=1;
	for(int i=1;i<10001;i++){
		euler_num[i]=euler_num[i-1]+euler[i];
		//printf("euler_num[%d]=%d\n",i,euler_num[i]);
	}
	//cout<<"End initialize!"<<endl;
	return;
}
int main(){
	init();
	while(!cin.eof()){
		int a,b;
		cin>>a>>b;
		//printf("euler[%d,%d]=%d,%d\n",a,b,euler_num[a],euler_num[b]);
		int s=(a==0)?0:euler_num[a-1];
		//printf("s=%d\n",s);
		printf("%.2f\n",100*double(euler_num[b]-s)/(b-a+1)+1e-8);
	}
}