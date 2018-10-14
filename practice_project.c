#include <stdio.h>
#include <stdlib.h> //for error calling exit()
#include <string.h>
#include <ctype.h>
#include <math.h>

unsigned long hex2int(char *a, unsigned int len)
{
    int i;
    unsigned long val = 0;

    for(i=0;i<len;i++)
       	if(a[i] <= 57)
        	val += (a[i]-48)*(1<<(4*(len-1-i)));
       	else if(a[i]<71)
        	val += (a[i]-55)*(1<<(4*(len-1-i)));
    	else
    		val += (a[i]-87)*(1<<(4*(len-1-i)));
    return val;
}

// takes in 1 byte and converts it to binary and then to its ascii representation and then to an int
char int_to_bin_amount(int n, int m) {
	// Size of an integer is assumed to be 32 bits 
	//array for first an second chars read, representing the amount
   	int ans1[5];
    char ans2[5];
    int result = 0;
    char res;
    ans1[4] = '\0';
    ans2[4] = '\0';
    for (int i = 0; i < 4; i++) { 
        int k = n >> i; 
        if (k & 1) 
            ans1[i] = 1; 
        else
            ans1[i] = 0; 
    }
    for (int i = 0; i < 4; i++) { 
        int k = m >> i; 
        if (k & 1) 
            ans2[i] = 1; 
        else
            ans2[i] = 0; 
    }

    int loop1 = 3;
    int loop2 = 3;
    int counter = 7;
    while(loop1>=0){
    	if(ans1[loop1] == 1){
    		result += pow(2,counter);
    	}
    	counter--;
    	loop1--;
    }
    while(loop2>=0){
    	if(ans2[loop2] == 1){
    		result += pow(2,counter);
    	}
    	counter--;
    	loop2--;	
    }
    // converts to int
    res = result;
    // write to a file
    return res;
}

int main(int argc, char * argv[]){
	// opens the file to read from and creates the file to write to
	FILE *fp_i = fopen( argv[1], "r");
	FILE *fp_o = fopen( argv[2], "w+");
	// checks to see if input file could open
	if(fp_i == NULL){
		printf("Cannot open input file");
	}
	// check to see if output file could be created/opened
	if(fp_o == NULL){
		printf("Cannot open and create output file");
	}
	char c;
	int x = 0;
	while(!feof(fp_i)) {

		// holds the type for both types
		char type[2];
		// holds the amount for when type is 0
		char amount_0[3];
		// conversion variable for amount as int (type 0)
		int int_amount;
		// variable used to represent each digit of the amount
		int result = 0;
		int counter;
		//char * number;

		for(counter = 0; counter<2; counter++) { 
			c = fgetc(fp_i);
			if(c == ' ' || c == '\n'){
				c = fgetc(fp_i);
			}
			type[counter] = c;
		}

		// check if type is 0
		if (type[1] == '0'){
			// loop to get amount
			for(counter = 0; counter < 2; counter++) { 
				c = fgetc(fp_i);
				if(c == ' ' || c == '\n'){
					c = fgetc(fp_i);
				}
				amount_0[counter] = c;
			}
			// writes type to file 
			amount_0[2] = '\0';
			fprintf(fp_o, "%c", '0');
			fprintf(fp_o, "%s", amount_0);
			fprintf(fp_o, "%c", ' ');
			int_amount = atoi(amount_0);
			// intializes chr array to hold ouput
			char output[int_amount];
			for(int i = 0; i < int_amount; i++){
				// intializes new array for the result/number
				char number[5];
				for(counter = 0; counter < 4; counter++){
					// reads in char
					c = fgetc(fp_i);
					// skips over space
					if(c == ' '){
						c = fgetc(fp_i);
					}
					// adds char to the char* for the number
					number[counter] = c;
					if (feof(fp_i)){
	  					break;
					}
				}
				number[4] = '\0';
				// converts hex to decimal and writes to file
				fprintf(fp_o,"%lu",hex2int(number,4));
				// writes to file with comma
				if(i<int_amount-1){
					fprintf(fp_o,"%c",',');
				}
				// prints newline for next input
				if(i == int_amount-1){
					fprintf(fp_o,"\n");
				}
			}
		}
		// check to see if the type is 1
		else if(type[1] == '1'){
			int final_amount = 0;
			int amount1;
			int amount2;
			int digit;

			for(counter = 0; counter < 3; counter++) { 
				// gets first byte 
				c = fgetc(fp_i);
				// skips over space
				if(c == ' '){
					c = fgetc(fp_i);
				}
				amount1 = atoi(&c);
				c = fgetc(fp_i);
				// skips over space
				if(c == ' '){
					c = fgetc(fp_i);
				}
				amount2 = atoi(&c);
				final_amount *= 10;
				if(isdigit(int_to_bin_amount(amount1, amount2))){
					digit = int_to_bin_amount(amount1, amount2) - '0';
				}
		
				//returns first ascii chracter(as an integer) for amount and adds it to final amount
				final_amount += digit;
			}
			fprintf(fp_o, "%s%d", "00", final_amount);
			fprintf(fp_o, "%c", ' ');

			// loop to find the numbers that will be printed to the file
			while(1){
				char char1 = fgetc(fp_i);
				// skips over space
				if(char1 == ' '|| char1 == '\n'){
					char1 = fgetc(fp_i);
				}
				char char2 = fgetc(fp_i);
				// skips over space and new line
				if(char2 == ' ' || char2 == '\n'){
					char2 = fgetc(fp_i);
				}
				if(feof(fp_i)){
					break;
				} 
				if(char1 == '0' && (char2 == '0'|| char2 == '1' )){
					fseek (fp_i , -2, SEEK_CUR);
					fprintf(fp_o, "%c", '\n');
					//ascii = 0;
					break;
				}
				if(char1 == '2' && char2 == 'c'){
					fprintf(fp_o, "%c", ',');
				}
				else{
					digit = int_to_bin_amount(char1, char2) - '0';
					fprintf(fp_o, "%d", digit);
				}			
			}
		}	
	}
	fclose(fp_o);
	fclose(fp_i); 
	return 0;
}
