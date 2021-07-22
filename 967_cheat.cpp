#include<iostream>
using namespace std;
int ans[42]={113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,199933,319993,331999,391939,393919,919393,933199,939193,939391,993319,999331};
int s[1000001]={0};
void init(void){
	for(int i=0;i<42;i++)
		s[ans[i]]=1;
	return;
}
int main(){
	int a,b;
	init();
	while(scanf("%d",&a)&&a!=-1){
		scanf("%d",&b);
		int cnt=0;
		for(int i=a;i<=b;i++){
			cnt+=s[i];
		}
		if(!cnt)
			printf("No Circular Primes.\n");
		else
			printf("%d Circular Prime.\n",cnt);
	}
}