#include <stdio.h>
#define numrow 6
#define numcol 6
void makelower(char guess[]){
int rowI, colI;
for(rowI = 0; rowI < numrow; rowI++) {
	//for(colI = 0; colI < numcol; colI++) {
	if(guess[rowI] >= 'A' && guess[rowI] <= 'Z'){
	guess[rowI] - 25;}}}

int main(){
FILE *wordle;
char word[6], guess[numrow][numcol];
int guesstotal = 0, letters = 0;
scanf("%s", &guess[guesstotal]);
makelower(guess[guesstotal]);
return 0;
}
