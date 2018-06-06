//calculate a num y which is base x to power n
//2^n=2*2^n-1 (n is an odd)
//2^n=2^(n/2)*2^(n/2) (n is an even)
//judge method:
//if:b&1 <=> b%2==1 (b is an odd)
//else:!(b&1) <=> b%2==0 (b is an even)
#include <stdio.h>

long long pow(int a,int b){
	if(b==0)
		return 1;
	if(b&1){
		return a*pow(a,b-1);
	}else{
		long long mul;
		mul=pow(a,b/2);
		return mul*mul;
	}
}

int main(){
	int base,power;
	long long y;
	
	printf("enter a base and its power:\n");
	while(~scanf("%d %d",&base,&power)){
		y=pow(base,power);
		printf("%d^%d=%ld\n",base,power,y); 
	}
	return 0;
}