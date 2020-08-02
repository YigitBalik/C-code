#include<stdio.h>
#include<stdlib.h>

/**
* Return the point value for throw
* @param (integer) segment, 1<= segment <= 20
* @param (char) ring, ring can be S,D,T,O or I.
**/
int throw_value(int segment,char ring){
	int value = 0;
	//if-else if statements calculates the point value of throw
	if(ring == 'S'){
		value = segment * 1; 
	}
	else if(ring == 'D'){
		value = segment * 2;
	}
	else if(ring == 'T'){
		value = segment * 3;
	}
	else if(ring == 'O'){
		value = 25;
	}
	else if(ring == 'I'){
		value = 50;
	}
	return value;
}
/**
* Return remaining point
* @param (integer) current point, 0 <= current <= Target
* @param (integer) segment, 1 <= segment <= 20 
* @param (char) ring, ring can be S,D,T,O or I.
**/
int remaining_pts(int current,int segment,char ring){
	int remaining = current;
	int throw = throw_value(segment,ring);
	remaining = remaining - throw;
	//if-else if-else statements checks the rules of scoring
	if(remaining == 0 && ring != 'D'){
		return (remaining + throw);
	}
	else if(remaining < 0 || remaining == 1){
		return (remaining + throw);
	}
	else{
		return remaining; 
	}
}

int main(){
	int target = 0,segment = 0;
	char ring;
	printf("Target: ");
	scanf("%d",&target);
	int current = target;
	//do while loop checks the rule for start to scoring
	do{
		printf("Throw: ");
		scanf("%d %c",&segment,&ring);
		printf("Points: %d\n",current);
	}while(current == target && ring != 'D');
	current = remaining_pts(current,segment,ring);
	printf("Points: %d\n",current);
	//while loop continues the game until finish
	while(current != 0){
		printf("Throw: ");
		scanf("%d %c",&segment,&ring);
		current = remaining_pts(current,segment,ring);
		printf("Points: %d\n",current);
	}
	
	return EXIT_SUCCESS;
}