#include <stdio.h>
#include <stdlib.h> //for error calling exit()
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char * argv[]){

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
	char final_string[1024];
	c = fgetc(fp_i);
	int counter = 0;
	char holder[1];
	if(c == '0'){
		printf("%s\n", "type 0");
		strcat(final_string, "01");
		c = fgetc(fp_i);
		//convert amount
		for(counter = 0; counter<3; counter++){
			strcat(final_string, "3");
			holder[0]= c;
			strcat(final_string, holder);
			printf("%s\n", final_string);
			c = fgetc(fp_i);
		}
		//add nums
		//skip space
		c = fgetc(fp_i);
		while(c != '\n' || c == '\r'){
			if(c == ','){
				strcat(final_string, "2c");
			}
			else{
				strcat(final_string, "3");
				holder[0]= c;
				strcat(final_string, holder);
			}
			c = fgetc(fp_i);
			
		}
		printf("%s\n", final_string);
	}

	else if(c == '1'){
		int digit = 0;
		char hex[5];
		printf("%s\n", "type 1");
		strcat(final_string,"00");
		printf("%s\n", final_string);
		//discard extra 0
		c = fgetc(fp_i);
		// get amount
		c = fgetc(fp_i);
		holder[0] = c;
		strcat(final_string, holder);
		c = fgetc(fp_i);
		holder[0] = c;
		strcat(final_string, holder);
		// skip space
		c = fgetc(fp_i);
		c = fgetc(fp_i);
		printf("%c\n", c);
		printf("%s\n", final_string);
		//get num
		char num[4];
		  while(c != '\n' && c != '\r'){
		    
		    
		  	printf("%c\n", c);
		 	
		 	if(c == ','){
		 		holder[0] = '0';
		 		strcat(final_string, holder);
		 		digit = 0;
		   		c = fgetc(fp_i);
		 	 	sprintf(hex,"%x", atoi(num));
		 	 	char num[4];
		 	 	strcat(final_string, hex);
		   	}
		  	num[digit] = c;
		  	digit++;
		  	c = fgetc(fp_i);	
		 	//

		  }
		  sprintf(hex,"%x\n", atoi(num));
		  holder[0] = '0';
		  strcat(final_string, holder);
		  strcat(final_string, hex);
		  printf("%s\n", final_string);
        
	}

	return 0;
}