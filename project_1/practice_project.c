#include <stdio.h>
#include <stdlib.h> //for error calling exit()
#include <string.h>
#include <math.h>

int hexadecimal_to_decimal(int x)
{
    int decimal_number, remainder, count = 0;
    while(x > 0){
    	remainder = x % 10;
    	decimal_number = decimal_number + remainder * pow(16, count);
    	x = x / 10;
    	count++;
    }
    return decimal_number;
}

int main(int argc, char * argv[]){
	// opens the file to read from and creates the file to write to
	FILE *fp_i = fopen( argv[1], "r");
	FILE *fp_o = fopen( argv[2], "w+");
	char c;
	char type[2];
	char amount[2];
	int int_amount;
	char * output;
	int i = 0;
	int counter;
	char * number;


	// checks to see if input file could open
	if(fp_i == NULL){
		printf("Cannot open input file");
	}
	// check to see if output file could be created/opened
	if(fp_o == NULL){
		printf("Cannot open and create output file");
	}

	//while(1) {
    	for(counter = 0; counter<2; counter++) { 
			c = fgetc(fp_i);
			//strcat(type, c);
			//printf("%c",c); //prints character 
			type[counter] = c;

		}
		printf("%c", type[0]);
		printf("%c\n", type[1]);

		// check if type is 0
		if (type[1] == '0'){
			// loop to get amount
			for(counter = 0; counter < 2; counter++) { 
				c = fgetc(fp_i);
				//strcat(amount, c);
				amount[counter] = c;
			}
			printf("%c", amount[0]);
			printf("%c\n", amount[1]);

			int_amount = hexadecimal_to_decimal(atoi(amount));
			printf("%d\n",int_amount);
			/*
			// itoa(99, str, 10);
			snprintf(amount,10,"%d", int_amount);
			//bitoa(int_amount, amount, 10);
			strcat(output, amount);
			while(i < int_amount){
				for(counter = 0; counter < 4; counter++){
					c = fgetc(fp_i);
					//strcat(number, c);
					number[strlen(number)] = c;
				if (feof(fp_i)){
      				break;
				}
			}
			}*/
		}
		// check to see if the type is 1
		else if(type[1] == 1){

		}
	//}
 	//printf("%c", c);
	//fputc(c, fp_o);	

	fclose(fp_o);
	fclose(fp_i);
	
	printf("Wrote successfully");   
	return 0;
}
