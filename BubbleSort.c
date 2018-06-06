#include <stdio.h>
#include <stdlib.h> /*required for random()*/
#include <time.h> /*required for time()*/

#define N 10 /*size of array*/
#define TRUE 1
#define FALSE 0

void swap(int *a,int *b);
int GenRandom();
void Initialize(int *a,int n);
void Output(int *a,int n);
void FunctionControl(void (*f)(int *a,int n),int *a,int n);
void BubbleSort1(int *a,int n);
void BubbleSort2(int *a,int n);
void BubbleSort3(int *a,int n);
void BubbleSort4(int *a,int n);

int main(int argc,char *argv[]){
	int a[N],i;
	void (*fp)(int *,int );
	
	printf("Initial:\n");
	Initialize(a,N);
	Output(a,N);
	
	fp=BubbleSort4; //points a function to run
	FunctionControl(fp,a,N);

	printf("\nArranged:\n");
	Output(a,N);
	
	return 0;
}

void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

int GenRandom(){
	int roll;
	//roll=srand((unsigned)time(NULL))%100; //error, generated the same num
	roll=rand()%100;
	return roll;
}

void Initialize(int *a,int n){
	int i;
	for(i=0;i<N;i++){
			//a[i]=GenRandom();
			a[i]=N-i;
		}
}

void Output(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		if(i%10==0)  
			printf("\n");
		printf("%2d ",a[i]);
	}
}

void FunctionControl(void (*func)(int *,int ),int *a,int n){
	func(a,n);
}
//normal version,j start from i+1,because {a[x]|x<=i} is arranged
void BubbleSort1(int *a,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(*(a+i)>*(a+j)){
				swap(a+i,a+j);
			}
		}
	}
}
//from last to first unit, firstly can let a[n-1],a[n-1] in order..
//go ahead, till a[0],a[1] in order
void BubbleSort2(int *a,int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
//if in a j loop no one was swaped, then break the i loop
void BubbleSort3(int *a,int n){
	int swaped=TRUE,i,j;
	
	for(i=0;i<n-1&&swaped;i++){
		swaped=FALSE;
		for(j=n-1;j>=i;j--){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				swaped=TRUE;
			}
		}
	}
}

void BubbleSort4(int *a,int n){
	int last_change,i,j;
	i=n-1;
	
	while(i>0){
		last_change=0;
		for(j=0;j<i;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				last_change=j;
			}
		}
		i=last_change;
	}
}
