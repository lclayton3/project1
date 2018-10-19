#include <stdio.h>
#include <stdlib.h> //for error calling exit()
#include <string.h>
#include <ctype.h>
#include <math.h>

void write_file(FILE *o, char * final){
	printf("%s\n", "here");
	printf("%s\n", final);
}

void type_0(FILE *fp_i, FILE *fp_o){

	char c;
	char final_string[1024];
	c = fgetc(fp_i);
	while(!feof(fp_i)){
	int counter = 0;
	char holder[1];
	if(c == '1'){
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
		
	}

	else if(c == '0'){
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

        
	}
}
write_file(fp_o, final_string);

}
void type_1(FILE *fp_i, FILE *fp_o){
	char c;
	char final_string[1024];
	c = fgetc(fp_i);
	while(!feof(fp_i)){
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
	}

	else if(c == '1'){
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
        
	}
}
write_file(fp_o, final_string);
}
void type_2(FILE *fp_i, FILE *fp_o){
	

	char c;
	char final_string[1024];
	c = fgetc(fp_i);
	while(!feof(fp_i)){
		
	int counter = 0;
	char holder[1];
	if(c == '0'){
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
        
	}
}
write_file(fp_o, final_string);
}


void type_3(FILE *fp_i, FILE *fp_o){
	
	char c;
	char final_string[1024];
	c = fgetc(fp_i);
	while(!feof(fp_i)){

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
        
	}
}
write_file(fp_o, final_string);
}

void type_change(char type, char * output, char * target){

	FILE *fp_i = fopen( output, "r");
	FILE *fp_o = fopen(target, "w+");
	// checks to see if input file could open
	if(fp_i == NULL){
		printf("Cannot open input file");
	}
	// check to see if output file could be created/opened
	if(fp_o == NULL){
		printf("Cannot open and create output file");
	}
	if(type == '0'){
		type_0(fp_i,fp_o);
	}
	else if(type == '1'){
		type_1(fp_i,fp_o);
	}
	else if(type == '2'){
		type_2(fp_i,fp_o);
	}
	if(type == '3'){
		type_3(fp_i,fp_o);
	}

	

	return;
}