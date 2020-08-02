#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE 10000
#define MAX_CHAR 200

struct instruction_s {
	int step;
	int index;
};


// Documantations of fuctions are below the main fuction
char* get_word(char* s, int n);
void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence);
void make_lower_del_punct(char *upper,char *lower);



int main(int argc,char *argv[]){
	char * instruction_file_name = argv[2];
	char * book_file_name = argv[1];
	
	FILE * instruction_file = NULL;
	FILE * book_file = NULL;
	instruction_file = fopen(instruction_file_name,"r");
	book_file = fopen(book_file_name,"r");
	
	// memory allocation for book
	char **book = (char **)malloc(MAX_LINE * sizeof(char*)); 
	for(int i = 0;i < MAX_LINE;i++){
		book[i] = (char *) malloc(MAX_CHAR * sizeof(char));
	}
	
	
	//get line by line
	int line_counter = 0;
	while(fgets(book[line_counter],MAX_CHAR,book_file) != NULL){
		line_counter++;
	}


	int n = 0;
	struct instruction_s* instructions =(struct instruction_s*)malloc(MAX_CHAR * sizeof(struct instruction_s*)) ;
	char* instruction_line = (char*) malloc(MAX_CHAR * sizeof(char));
	while(fgets(instruction_line,MAX_CHAR,instruction_file) != NULL){
		sscanf(instruction_line,"%d %d",&(instructions + n)->step,&(instructions + n)->index);
		n++;
	}

	char* upper_sentence = (char*) malloc(MAX_CHAR * sizeof(char));
	get_sentence(book,instructions,n,upper_sentence);
	char lower_sentence[MAX_CHAR] = "";
	
	make_lower_del_punct(upper_sentence,lower_sentence);
	
	
	puts(lower_sentence);
	free(instruction_line);
	free(upper_sentence);
	fclose(instruction_file);
	fclose(book_file);
	for(int i = 0;i < MAX_LINE; i++){
		free(book[i]);
	}
	free(book);
	free(instructions);
	return EXIT_SUCCESS;
}

/*
* @param pointer pointer lines represents the book
* @param pointer instructions represents each pair of instructions
* int n_instructions is the number of instructions
* char pointer sentence is the string which keeps the wanted words
*/
void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence){
	
	int go_line = -1;  //array is 0 based and instruction is 1 based
	char *current_line = (char *) malloc(MAX_CHAR * sizeof(char));
	char *wanted_word = (char *) malloc( 40 * sizeof(char));
	for(int i = 0;i < n_instructions;i++){
		go_line += (instructions + i)->step;
		strcpy(current_line,lines[go_line]);
		strcpy(wanted_word,get_word(current_line,(instructions + i)->index));
		strcat(sentence,wanted_word);
	}
	free(current_line);
	free(wanted_word);
}


/*
* returns the wanted word from specific line of book
* @param char pointer s is the specific line of book
* @param integer n is the index of wanted word
*/
char  *get_word(char *s,int n){
	char *word;
	char tok[] = " ";
	char *explorer = strtok(s,tok);

	int explored = 1;
	while(explorer != NULL){
		if(explored == n){
			word = explorer;
			break;
		}
		explorer = strtok(NULL,tok);//iterate strtok to get wanted word 
		explored++;
		
	}
	word[strlen(word) + 1] = '\0';
	for(int i =0;i<strlen(word);i++){
		if(word[i] == '\n')word[i] = '\0';
	}
	word[strlen(word)] = ' ';
	return word;
}



/*
* @param pointer upper is the first version of the sentence. It can contain uppercase letters and punctuation marks.
* @param pointer lower is the last version of sentence. It does not contain any uppercase letters and punctuation marks.
*/
void make_lower_del_punct(char *upper,char *lower){
	
	/*
	* integer values of uppercase characters according to ascii table [65,90]
	* integer values of lowercase characters according to ascii table [97,122]
	* x - X = 32 (x is some lowercase char and X is uppercase version of x)
	*/
	int u = 0,l = 0;
	while(u < strlen(upper)){
		if(65 <= upper[u] && upper[u] <= 90){
			lower[l] = upper[u] + 32;
			l++;
			u++;
		}
		else if(upper[u] == ' '){
			lower[l] = upper[u];
			u++;
			l++;
		}
		else if(97 <= upper[u] && upper[u] <= 122){
			lower[l] = upper[u];
			u++;
			l++;
		}
		else{
			//ignore chars other than alphabet
			u++;
		}
	}
}
