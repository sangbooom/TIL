#include <iostream>
#define MAX 13
//홀수만 입력하되 19미만 
using namespace std;

int main(void){
	int row,col;
	int begin,end;
	int num=1;
	int center = MAX/2;
	int arr[MAX][MAX] = {0, };
	
	for(row=0; row<MAX; row++){
		if(row <= center){
			begin = row;
			end = MAX - row;
		}
		if(row > center){
			begin = (MAX-1)-row;
			end = row + 1;
		}
		for(col=begin; col<end; col++){
			arr[row][col] = num;
			num++;
		}
	}
	for(row=0; row<MAX; row++){
		for(col=0; col<MAX; col++){
			printf("%4d",arr[row][col]);
		}
		printf("\n");
	}
		

	return 0;
}
