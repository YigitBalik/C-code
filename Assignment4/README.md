Your program that takes two command line arguments:
• The name of the file that contains the book. You can assume that there will be
at most 10000 lines in the file, and that each line will be at most 200 characters
long.
• The name of the file that contains the instructions. Each line in the file describes
an instruction.
Each instruction specifies how to extract the next word. The first instruction gives the
index of the line and the index of the word within the line. Note that both indexes are
1-based (not 0-based). Subsequent instructions specify the offset of the next line
(positive offsets move forward, negative offsets move backward) and the index of the
word in that line. For example if the instruction lines are 5 2, 2 4, -3 1, the words to
be selected are: line 5 word 2, line 7 word 4, line 4 word 1.
Your program will read both files and store the data in two arrays. To represent the
book, use a char** (an array of strings). To represent the instructions, use a struct
instruction_s* where each instruction is represented by the following struct type:
struct instruction_s {
int step; int index;
}
The step specifies the offset of the next line and the index specifies the index of the
word in the line.
Write the following functions to accomplish your task:
• A function get_word that takes a line s and an index n, and returns the selected
word. This function should have the following signature:
char* get_word(char* s, int n)
• A function that takes the lines of a book, a sequence of instructions, the number
of instructions n_instructions, and an empty sentence where to store the
extracted sentence. This function should have the signature:
void get_sentence(char** lines, struct instruction_s* instructions, int
n_instructions, char* sentence)
As you are processing the text, you have to remove all punctuation marks attached to
the words (e.g. hi! should be converted to hi ) and convert all upper case letters to
lower case (e.g. Hi! should be converted to hi).
You can assume that the instructions will not result in locations that do not exist in
the text.
