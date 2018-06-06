//calculate a num y which is base x to exp n
//2^n=2*2^n-1 (n is an odd)
//2^n=2^(n/2)*2^(n/2) (n is an even)
//judge method:
//if:b&1 <=> b%2==1 (b is an odd)
//else:!(b&1) <=> b%2==0 (b is an even)
#include <stdio.h>

long long pow1(int a,int b){
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

long long pow2(int base, int exp)
{
    long long result = 1;
    while(1){
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
    return result;
}

int main(){
	int base,exp;
	long long y;
	
	printf("enter a base and its exp:\n");
	while(~scanf("%d %d",&base,&exp)){
		y=pow1(base,exp);
		printf("%d^%d=%ld\n",base,exp,y); 
	}
	return 0;
}