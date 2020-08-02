#include"spylib.h"

void press_key(){
	char dummy;
	printf("Press a key to continue...\n");
	scanf(" %c",&dummy);
}

bool game(char *file_name){
	system("clear");
	printf("\n--------Welcome to the SpyFy--------\n");
	printf("1. Edit Game\n");
	printf("2. Strart Game\n");
	printf("3. Exit Game\n");
	int selection = 0;
	printf("Selection: ");
	scanf("%d",&selection);
	switch(selection){
		case 1:
			system("clear");
			printf("\n--------Options--------\n");
			printf("1. Add country\n");
			printf("2. Delete countr\n");
			printf("Selection: ");
			scanf("%d",&selection);
			char country[20] = "";
			switch(selection){
				case 1:
					system("clear");
					printf("Enter country: ");
					scanf("%s",country);
					add(file_name,country);
					press_key();
				break;
				case 2:
					system("clear");
					copy_file(file_name);
					printf("Enter country: ");
					scanf("%s",country);
					del(file_name,country);
					press_key();
				break;
			}
		break;
		case 2:
			system("clear");
			int n = 0;
			printf("How many players: ");
			scanf("%d",&n);
			create_game(file_name,n);
		break;
		case 3: return 0;break;
		
		
		
	}


	return true;
}






int main(int argc, char *argv[]){
	srand(time(0));
	printf("%ld",clock());
	if(argc != 2){
		printf("Please enter %s and settings file!",argv[0]);
		return EXIT_FAILURE;
	}
	char *file_name = argv[1];
	while(game(file_name));
	
	
	return EXIT_SUCCESS;
}