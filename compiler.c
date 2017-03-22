#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


/*
for (char *p=*(argv+i); *p; p++){
		//Process args here
		printf("%c\n",*p);
		

		
		}
*/


int sub(int x, int y){ return x-y;}
int add(int x, int y){ return x+y;}


int main(int argc, char *argv[]){
	
	printf("\t.global compute\n\n");
	printf("compute:\n");
	int64_t av;
	for (short i = 1; i < argc; i++){

	    int arglen = strlen(argv[i]);
	    if (arglen > 1){
		//Check invalid numbers or numbers with characters in them
		short ex=0;
		if ((argv[i][0])=='-'){
			for (short j = 1; j<arglen;j++){
					if(!isdigit(argv[i][j])){
				    		ex = 1;
					  }
			  	}
		
			} else {
			for (short j = 0; j<arglen;j++){
					if(!isdigit(argv[i][j])){
				    		ex = 1;
					  }
			  	}
			    
			//Close else of if isdigit and -
			}
		
		(ex) ? fprintf(stderr, "Error: Only single characters x, y, and z permitted. \n"):
				 sscanf(argv[i],"%d",&av);
		
		//Close If arlen
		    } else {
		
		//printf("Now check if its a digit, operator, or variable.\n");

		if ((strcmp(argv[i],"+")==0)||(strcmp(argv[i],"-")==0)||(strcmp(argv[i],"t")==0)||
			(strcmp(argv[i],"x")==0)||(strcmp(argv[i],"y")==0)||(strcmp(argv[i],"z")==0 || (strcmp(argv[i],"n")==0))
		    ){
			av = *(argv[i]);}
			
		else if (isdigit(*argv[i])){
			sscanf(argv[i],"%d",&av);}
		else{
		fprintf(stderr,"Error Invalid input");}
		
		
		//Close Else Arlen
		}
		
		//printf("AV---%d\n",av);
		switch(av){
		    case (120):
			printf("\tpushq\t%%rdi\n");
			break;
		    case (121):
			printf("\tpushq\t%%rsi\n");
			break;
		    case(122):
			printf("\tpushq\t%%rdx\n");
			break;
		    case(116):
			printf("\tpopq\t%%r10\n");
			printf("\tpopq\t%%r11\n");
			printf("\timulq\t%%r10, %%r11\n");
			printf("\tpushq\t%%r11\n");
			break;
		    case(43):
			printf("\tpopq\t%%r10\n");
			printf("\tpopq\t%%r11\n");			
			printf("\taddq\t%%r10, %%r11\n");
			printf("\tpushq\t%%r11\n");
			break;
		    case(45):
			printf("\tpopq\t%%r10\n");
			printf("\tpopq\t%%r11\n");			
			printf("\tsubq\t%%r10, %%r11\n");
			printf("\tpushq\t%%r11\n");
			break;
		    case(110):
			printf("\tpopq\t%%r10\n");
			printf("\tpopq\t%%r11\n");			
			printf("\tsubq\t%%r10, %%r11\n");
			printf("\tpushq\t%%r11\n");
			break;
		    default:
			printf("\tpushq\t$%d\n",av);
			break;
		    


		}
	//Close For loop
	     }
	printf("\tpopq\t%%rax\n");
	printf("\tretq\n");
		






		
	sub(5,2);
	add(5,2);	
		

	return 0;
}


