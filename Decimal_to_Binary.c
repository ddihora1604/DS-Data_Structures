
#include <stdio.h> 

void decToBinary(int n) 
{ 
	
	int binaryNum[32]; 
	int i = 0,j; 
	while (n > 0) { 
		binaryNum[i] = n % 2; 
		n = n / 2; 
		i++; 
	} 

	for (j = i - 1; j >= 0; j--) 
		printf("%d", binaryNum[j]); 
} 
int main() 
{ 
	int n = 17; 
	decToBinary(n); 
	return 0; 
}
