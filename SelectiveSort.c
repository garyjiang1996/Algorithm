#include <stdio.h>
#include <time.h>

#define N 20
#define CLOCK_PER_SEC 1000
#define MAX_SIZE 128
#define SWAP(x,y,t) t=(x);(x)=(y);(y)=t;

void selective_sort(int list[],int n);
void init_list(int list[],int n);
void output_list(int list[],int n);

int main(){
	int i,step;
	int list[N];
	double duration;
	clock_t start,stop;

	printf("initial:\n");
	init_list(list,N);
	output_list(list,N);
	printf("\n");
	
	start=clock();
	selective_sort(list,N);	
	stop=clock();
	duration=(double)(stop-start)/CLOCKS_PER_SEC;
	
	printf("arranged:\n");
	output_list(list,N);
	printf("\ntime spent:%f\n",duration);

	return 0;
}

void init_list(int list[],int n){
	while(1+--n)
		list[n]=rand()%100;
}

void selective_sort(int list[],int n){
	int i,j,t,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<=n-1;j++){
			if(list[min]>list[j])
				min=j;
			SWAP(list[i],list[min],t);
		}
	}
}

void output_list(int list[],int n){
	int i;
	for(i=0;i<n;i++){
		if(i%10==0)
			printf("\n");
		printf("%03d ",list[i]); 
	}
}