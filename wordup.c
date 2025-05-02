//Jordan Imgard
//April 22nd, 2025
//Project 10

#include <stdio.h>
#define numrow 6
#define numcol 6

void makelower(char guess[]);
void makeupper(char guess[], char word[]);
int lettercheck(char guess[]);
int correctcheck(char guess[], char word[]);
void wordcap(char word[]);
void arrowsfunc(char guess[], char word[], char arrows[]);

int main(){

FILE *wordle;
char word[6];
wordle = fopen("word.txt", "r");
if (wordle == NULL){
	printf("Error opening file\n");
	return 1;
}
fscanf(wordle, " %20s", word);
fclose(wordle);
					
char guess[numrow][numcol], storearrows[numrow][numcol];
int guesstotal = 0, letters = 0;
while(guesstotal < 6){
	printf("GUESS %d! Enter your guess: ", guesstotal + 1);
while(1){
	scanf("%s", &guess[guesstotal]);
	if(lettercheck(guess[guesstotal])){
	break;}
	else{
		printf("Your guess must be 5 letters long and only contain letters.\nPlease try again: ");}}
	printf("================================\n");
	makelower(guess[guesstotal]);
	if(correctcheck(guess[guesstotal], word)){
		wordcap(word);
		printf("                %s\n", word);
		printf("        You won in %d guesses!\n", guesstotal + 1);
		int congrats = guesstotal + 1;
		switch (congrats) {
			case 1:
				printf("                GOATED\n");
				break;
			case 2:
			case 3:
				printf("                Amazing!\n");
				break;
			case 4:
			case 5:
				printf("                Nice!\n");
				break;
		}
	break;
	}
	arrowsfunc(guess[guesstotal], word, storearrows[guesstotal]);
	makeupper(guess[guesstotal], word);
	guesstotal++;
	for(int i = 0; i < guesstotal; i++){
		printf("%s\n", guess[i]);
		printf("%s\n", storearrows[i]);
	}
}
if(guesstotal == 6) {
	printf("You lost, better luck next time!\n");}
return 0;
}

void makelower(char guess[]){
int rowI;
	for(rowI = 0; rowI < numrow; rowI++) {
		if(guess[rowI] >= 'A' && guess[rowI] <= 'Z'){
			guess[rowI] = guess[rowI] + 32;
		}
	}
}
	
void makeupper(char guess[], char word[]){
int rowI;
	for(rowI = 0; rowI < 5; rowI++) {
		if(guess[rowI] == word[rowI]){
			if(guess[rowI] >= 'a' && guess[rowI] <= 'z'){
			guess[rowI] = guess[rowI] - 32;
			}
		}
	}
}

int lettercheck(char guess[]){
int count = 0;

	for(int index = 0; guess[index] != '\0'; index++) {
		char invalid = guess[index];
		if((invalid >= 'a' && invalid <= 'z') || (invalid >= 'A' && invalid <= 'Z')) { 
			count++;
	} else {
		return 0;
	}
	}
	if(count == 5){
	return 1;
	}
	else {
	return 0;
	}
}

int correctcheck(char guess[], char word[]){
int rowI;
	for(rowI = 0; rowI < 5; rowI++) {
		if(guess[rowI] != word[rowI]){
			return 0;
		}
	}
return 1;
}

void wordcap(char word[]){
int rowI;
	for(rowI = 0; rowI < numrow; rowI++) {
		if(word[rowI] >= 'a' && word[rowI] <= 'z'){
			word[rowI] = word[rowI] - 32;
		}
	}
	word[5] = '\0';
}
	
void arrowsfunc(char guess[], char word[], char arrows[]) {
int index, correct, index2, position[5], letterused[5];
	for (int i = 0; i < 5; i++){		//correct letter, correct spot
		arrows[i] = ' ';
		position[i] = 0;
		letterused[i] = 0;
	}
	for (index = 0; index < 5; index++) {	//correct letter, wrong spot
		if (guess[index] == word[index]) {
			position[index] = 1;
			letterused[index] = 1;
		}
	}
	for(index = 0; index < 5; index++){	//check for double letters
		if(position[index] == 0) {		
			for(index2 = 0; index2 < 5; index2++){
				if (index != index2 && guess[index] == word[index2] && letterused[index2] == 0) {
					arrows[index] = '^';
					letterused[index2] = 1;
				}
			}
		}
	}
	arrows[5] = '\0';
}
