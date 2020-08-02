#include<stdio.h>
#include<stdlib.h>

int main(){
	int year, month, day, endYear;
	printf("Enter date [year month day]: ");
	scanf("%d %d %d",&year,&month,&day);
	if(month > 12 || month < 1){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else if(day < 1 || day > 31){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else if(month == 2 && day > 28){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else if(month == 4 && day > 30){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else if(month == 6 && day > 30){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else if(month == 9 && day > 30){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	else if(month == 11 && day > 30){
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	printf("Enter end year: ");
	scanf("%d",&endYear);
	int q,m,j,k,ryear,intday;
	if(month <= 2){
		q = day;
		m = month + 12;
		ryear = year - 1;
		k = ryear % 100;
		j = ryear / 100;
		intday = ( q + ( 13 * (m + 1) ) / 5 + k + (k / 4) + (j / 4) + ( 5 * j) ) % 7; 
	}
	else{
		q = day;
		m = month;
		ryear = year;
		k = ryear % 100;
		j = ryear / 100;
		intday = ( q + ( 13 * (m + 1) ) / 5 + k + (k / 4) + (j / 4) + ( 5 * j) ) % 7;
	}
	int counter = 0,startyear,testday;
	if(intday == 0)printf("It's a Saturday.\n");
	else if(intday == 1)printf("It's a Sunday.\n");
	else if(intday == 2)printf("It's a Monday.\n");
	else if(intday == 3)printf("It's a Tuesday.\n");
	else if(intday == 4)printf("It's a Wednesday.\n");
	else if(intday == 5)printf("It's a Thursday.\n");
	else if(intday == 6)printf("It's a Friday.\n");
	for(startyear = year + 1;startyear <= endYear;startyear++){
		if(month <= 2){
			q = day;
			m = month + 12;
			ryear = startyear - 1;
			k = ryear % 100;
			j = ryear / 100;
			testday = ( q + ( 13 * (m + 1) ) / 5 + k + (k / 4) + (j / 4) + ( 5 * j) ) % 7; 
		}
		else{
			q = day;
			m = month;
			ryear = startyear;
			k = ryear % 100;
			j = ryear / 100;
			testday = ( q + ( 13 * (m + 1) ) / 5 + k + (k / 4) + (j / 4) + ( 5 * j) ) % 7;
		}
		if(testday == intday)counter++;
	}
	printf("Same day-and-month on same weekday between %d and %d: %d\n",year + 1,endYear,counter);
	return EXIT_SUCCESS;
}
