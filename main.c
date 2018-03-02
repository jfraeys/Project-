/****************************************************/
/* File: main.c                                     */
/* Main program for the SGML Scanner                */
/* Joel Klemens - 0895223                           */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "gStack.h"

/* allocate global variables */
int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

int main( int argc, char * argv[])
{ 
  TokenType ttype;
  source = stdin;
  listing = stdout; 

  //we need to init the stack
  Stack * theStack;
  theStack = initializeStack(); 

  //flag for when we are in non-relevant tags
  int inIrrelevant = 0; 
  int tagDepth = 0; 
  int irrelevantDepth = 0; 
  char * rTags[] = {"DOC","TEXT","DATE","DOCNO","HEADLINE","LENGTH","P"}; 

  //Go through all of the tokens that are being created, we dont want everything though
  //we need to get rid of all the non-relevant tags and associated tokens
  //the only tags we want are <Doc>,<Text>,<Date>,<DocNo>,<Headline> and <Length> almost forgot <P>
  while((ttype=getToken())!= ENDFILE){
  		//check the token type for open tags
  		if(ttype == OPEN){
  			tagDepth++; 
  			
  			//if it is an open tag then we need to check to see if it is relevant
  			//To do this we must first remove the tag brackets
  			int i = 0;
  			char * temp;
  			temp = malloc(sizeof(char)* strlen(tokenString));
  			for(i = 0; i < (strlen(tokenString)-2); i++){
  				temp[i] = toupper(tokenString[i+1]); 
  			}
  			temp[i] = '\0'; 
  			//now we have the tag on its own, check it against the tags we need
  			//unless we are already in an irrelevant section
  			
  			if(inIrrelevant == 0){
	  			for(i = 0; i < 7; i++){
	  				if(strcmp(temp, rTags[i]) == 0){
	  					//this is a relevant tag
	  					inIrrelevant = 0;
	  					irrelevantDepth = 0; 
	  					break; 
	  				}else{
	  					inIrrelevant = 1;
	  					irrelevantDepth = tagDepth; 
	  				}
	  			}
	  		}
  			//we now have to push the tag to the stack 
  			push(theStack, temp);
  			free(temp);
  		}
  		//check the type for closing tags
  		if(ttype == CLOSE){ 
  			//if there is a close tag then we need to check it against the top of the stack
  			char * temp; 
  			int i = 0;
  			temp = malloc(sizeof(char)* strlen(tokenString));
  			for(i = 0; i < (strlen(tokenString)-3); i++){
	  			temp[i] = toupper(tokenString[i+2]); 
	  		}
	  		temp[i] = '\0';

	  		//check to see if this matches the top of the stack
	  		if(strcmp(temp, getTop(theStack)) == 0){
	  			//its a match 
	  			//if we are in irrelevant then we check the irrelevant depth to see 
	  			//if we are now out of the irrelevant part
	  			pop(theStack); 
	  			if(inIrrelevant == 1){
	  				if(tagDepth == irrelevantDepth){
	  					inIrrelevant = 0;
	  					irrelevantDepth = 0; 
	  					continue;
	  				}
	  			}
	  		}else{
	  			//it is not a match and this mean an error
	  			fprintf(stderr, "Error: Mismatched Close tag on line: %d - </%s>, tag was never opened.\n", lineno, temp);
	  			continue;
	  		}
	  		tagDepth--;
        free(temp); 
  		}

  		//we are only going to print the tokens that are relevant
  		if(inIrrelevant == 0){
  			if(theStack->head != NULL){
          if(ttype == OPEN){
            int i = 0;
            char * temp;
            temp = malloc(sizeof(char)* strlen(tokenString));
            for(i = 0; i < (strlen(tokenString)-2); i++){
              temp[i] = toupper(tokenString[i+1]); 
            }
            temp[i] = '\0'; 
            printToken(ttype, temp);
            free(temp);
          }else if(ttype == CLOSE){
            char * temp; 
            int i = 0;
            temp = malloc(sizeof(char)* strlen(tokenString));
            for(i = 0; i < (strlen(tokenString)-3); i++){
              temp[i] = toupper(tokenString[i+2]); 
            }
            temp[i] = '\0';
            printToken(ttype, temp);
            free(temp);
          }else{
            printToken(ttype, tokenString);
          }
  			}
  		}
  	}

  	//Reporting all of the tags left over in the stack if any
  	if(theStack != NULL){
		while(theStack->head != NULL){
			fprintf(stderr, "Error: Mismatched Open tag <%s>, tag was never closed.\n", getTop(theStack));
			pop(theStack);
		}
	}

    //delete the stack before ending 
    deleteStack(theStack); 
  return 0;
}

