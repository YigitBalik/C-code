#include<stdio.h>	// printf & scanf
#include<stdlib.h>	// EXIT_SUCCESS
#define MAX_DISTANCE 100  // MAX_DISTANCE is the value that manhattan formula can take in the biggest parking area
/*
* Return the absolute value of operation
* @param integer x
* @param integer y
*/
int absolute_value(int x,int y){
	int result = 0;
	if(x >= y){
		result = x - y;
	}
	else{
		result = y - x;
	}
	return result;
}

int main(){
	int size = 0;
	printf("Size: ");
	scanf("%d",&size);
	while(size < 1 || size > 50){
		printf("Size must be between 50 and 1\n");
		printf("Size: ");
		scanf("%d",&size);	
	}
	int parking_area[size][size];
	for(int i = 0;i < size;i++){
		for(int j = 0;j < size;j++){
			parking_area[i][j] = 0;
		}
	}
	int cars = 0;
	printf("Cars: ");
	scanf("%d",&cars);
	//If the parkin area is full best slot is 0 0
	if(cars >= (size * size)){
		printf("Best Slot Found In: 0 0\n");
		return EXIT_SUCCESS;
	}
	//If there is no car best slot is 1 1
	else if(cars == 0){
		printf("Best Slot Found In: 1 1\n");
		return EXIT_SUCCESS;
	}
	//For loop below fills the cars to the area
	for(int i = 0;i < cars;i++){
		int input_x = 0,input_y = 0;
		printf("Locations: ");
		scanf("%d %d",&input_x,&input_y);
		//array_x and array_y are the respons to location inputs for an array
		int array_x = input_x - 1, array_y = input_y - 1;
		parking_area[array_y][array_x] = 1;
	}
	//The distance_array will keep the distances of points to nearest car
	int distance_array[size][size];
	//Nested for loops below are the first step to check for largest distance to nearest car
	for(int i = 0;i < size;i++){
		for(int j = 0;j < size;j++){
			if(parking_area[i][j] == 1)distance_array[i][j] = 0;//Points with car has distance 0
			else{
				int closest = MAX_DISTANCE;
				//Nested for loop below calculates the distance of points to the nearest car
				for(int row = 0;row < size;row++){
					for(int col = 0;col < size;col++){
						if(parking_area[row][col] == 1){
							//int manhattan = abs(i - row) + abs(j - col);
							int manhattan = absolute_value(i,row) + absolute_value(j,col);
							if(manhattan < closest){
								closest = manhattan;
							}
						}
					}
				}
				distance_array[i][j] = closest;//Fill the points with the distances
			}
		}
	}
	int parking_x = 0, parking_y = 0;//These variables are array response to real parking location
	int max_distance = 0;
	//As a final step nested for loop and sequence of if-else statements determines to the parking slot
	for(int i = 0;i < size;i++){
		for(int j = 0;j < size;j++){
			if(distance_array[i][j] > max_distance){
				max_distance = distance_array[i][j];
				parking_x = j;
				parking_y = i;
			}
			else if(distance_array[i][j] == max_distance && j < parking_x){
				parking_x = j;
				parking_y = i;
			}
			else if((distance_array[i][j] == max_distance && j == parking_x) && i < parking_y){
				parking_x = j;
				parking_y = i;
			}
		}
	}
	printf("Best Slot Found In: %d %d\n",parking_x + 1,parking_y + 1);
	return EXIT_SUCCESS;
}