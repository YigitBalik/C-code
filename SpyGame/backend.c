#include"spylib.h"
#define SAVE "save.txt"

int line_count = 197;

void start_game(char player[][20], int n){
	char dummy;
	clock_t start,end;
	for(int i = 0;i < n;i++){
		system("clear");
		printf("Player-%d Role: press any key to see\n",i+1);
		scanf(" %c",&dummy);
		printf("%s",player[i]);
		press_key();
	}
	system("clear");
	printf("...Game Continues...\n");
	printf("When spy is found press any key to finish game\n");
	start = clock();
	scanf(" %c",&dummy);
	end = clock();
	printf("%ld\n",(end - start)/1000);
	press_key();
}


void create_game(char *file_name, int n){
	FILE *fp = fopen(file_name,"r");
	char players[n][20];
	int country_line = rand() % line_count + 1;
	char country[20] = "";
	int i = 0;
	while(i < country_line){
		fgets(country,sizeof(country),fp);
		i++;
	}
	int spy = rand()% n;
	fseek(fp,0,SEEK_SET);
	for(i = 0;i < n;i++){
		if(i != spy){
			strcpy(players[i],country);
		}
		else{
			fgets(players[i],20,fp);
		}
	}
	start_game(players,n);
	fclose(fp);
}





void add(char * file_name,char * country){
	int check = 0;
	FILE *set = fopen(file_name,"a+");
	char line[20] = "";
	while(fgets(line,sizeof(line),set) != NULL){
		if(strncmp(country,line,strlen(country)) == 0){
			printf("Country %s is already part of game!\n",country);
			check = 1;
		}
	}
	if(!check){
		fprintf(set,"%s\n",country);
		printf("Country %s successfully added to game!\n",country);
	}
	
	fclose(set);
}


void copy_file(char * file_name){
	FILE * save = fopen(SAVE,"w");
	FILE * set = fopen(file_name,"r");
	char line[20] = "";
	while(fgets(line,sizeof(line),set) != NULL){
		fprintf(save,"%s",line);
	}
	fclose(save);
	fclose(set);
}


void del(char *file_name,char *country){
	FILE * save = fopen(SAVE,"r");
	FILE * set = fopen(file_name,"w");
	char line[20] = "";
	int check = 0;
	while(fgets(line,sizeof(line),save) != NULL){
		if(strncmp(country,line,strlen(country)) != 0){
			fprintf(set,"%s",line);
		}
		else{
			printf("Country %s is deleting...\n",country);
			check = 1;
			line_count--;
		}
	}
	if(!check)printf("Country %s already not part of the game!\n",country);
	
	
	fclose(save);
	fclose(set);
}