#include "stdio.h"

int fibonacci1(int n);
int fibonacci2(int n);
int fibonacci3(int n);
int fibonacci4(int n,int m1,int m2);
void output1(int (*pf)(int ),int n);
void output2(int (*pf)(int ,int ,int ),int n,int m1,int m2);

int main()
{
	int n;
	while(~scanf("%d",&n)){
		//output1(fibonacci3,n); //fit fibonacci1~3
		output2(fibonacci4,n,1,1); //fit fibonacci4
		printf("\n");
	}
	return 0;
}

int fibonacci1(int n){
	int f1,f2,i,t;
	
	if(n<0) 		return 0;
	if(n==1||n==2)  return 1;
	f1=f2=1;
	
	for(i=0;i<n-2;i++){
		t=f1+f2;
		f1=f2;
		f2=t;
	}
	return t;
}

int fibonacci2(int n){
	int first,second,next,c;
	first=second=1,next,c;
	
	if(n<0) return 0;
	for ( c = 0 ; c < n ; c++ ){
		if ( c <= 1 ){
			next=1;
		}else{
			next = first + second;
			first = second;
			second = next;
		}
	}
	return next;
 }

int fibonacci3(int n){
	if(n<0) return 0;
	if(n==1||n==2){
		return 1;
	}else{
		return fibonacci3(n-1)+fibonacci3(n-2);
	}
}

int fibonacci4(int n,int m1,int m2){
	if(n<0) return 0;
	if(n==1) return m1;
	if(n==2){
		return m2;
	}else{
		return fibonacci4(n-1,m2,m1+m2);
	}
}

void output1(int (*pf)(int ),int n){
	int i=1;
	while(i<=n)
		printf("%d ",(*pf)(i++));
}

void output2(int (*pf)(int ,int ,int ),int n,int m1,int m2){
	int i=1;
	while(i<=n)
		printf("%d ",(*pf)(i++,m1,m2));
}
