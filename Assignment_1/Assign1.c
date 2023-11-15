/*
Author: Justin Jin
Date: 5/30/2002
Description: This program will translate a english text file into morse code, or a morse code file into english, depending on the given parameters in the console.
Usage: <exe> <input file> <-mc|-e> <output file>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
  if(argc < 4 || (strcmp(argv[2],"-mc")!=0 && strcmp(argv[2],"-e")!=0)){
    printf("Error -- Usage: <exe> <input file> <-mc|-e> <output file> \n");
    return 1;
  }

  FILE* inFile;
  FILE* outFile;
  const char* englishToMorse(char);
  char morseToEnglish(const char*);

  inFile = fopen(argv[1], "r");
  outFile = fopen(argv[3],"w");  
  
  if(inFile == NULL || outFile == NULL)
    {
      perror("FAILED TO OPEN FILE: ");
      return 1;
    }
  else
    {
      printf("File Opened\n");
    }
  
  if(strcmp(argv[2],"-mc")==0)
    {
      char buffer[256];
      while(!feof(inFile))
	{
	  fgets(buffer,255,inFile);
	  buffer[strcspn(buffer,"\r\n")]=0;
	  int i=0;
	  for(i=0; buffer[i] != 0; i++)
	    {
		fprintf(outFile,"|");
		fprintf(outFile,"%s",englishToMorse(buffer[i]));
	    }
	  fprintf(outFile,"\n");
	}
    }
  
  if(strcmp(argv[2],"-e")==0)
    {
      char buffer[1800];
      while(!feof(inFile))
	{
	  fgets(buffer,1800,inFile);
	  buffer[strcspn(buffer,"\r\n")]=0;
	  
	  char* token  = strtok(buffer,"|");
	  while(token != NULL)
	    {
	      fprintf(outFile,"%c",morseToEnglish(token));
	      token = strtok(NULL,"|");
	    }
          fprintf(outFile,"\n");
	}      
    }
	    
  printf("File Completed.\n");

  fclose(inFile);
  fclose(outFile);
  return 0;
}

char morseToEnglish(const char* str){
  char ch;
  if(strcmp(str,"/")==0)
    {
    ch = ' ';
    }
  else if(strcmp(str,"XXXX")==0)
    {
      ch = '#';
    }
  else if(strcmp(str,"*-")==0)
    {
      ch = 'a';
    }
  else if(strcmp(str,"-***")==0)
    {
      ch = 'b';
    }
  else if(strcmp(str,"-*-*")==0)
    {
      ch = 'c';
    }
  else if(strcmp(str,"-**")==0)
    {
      ch = 'd';
    }
  else if(strcmp(str,"*")==0)
    {
      ch = 'e';
    }
  else if(strcmp(str,"**-*")==0)
    {
      ch = 'f';
    }
  else if(strcmp(str,"--*")==0)
    {
      ch = 'g';
    }
  else if(strcmp(str,"****")==0)
    {
      ch = 'h';
    }
  else if(strcmp(str,"**")==0)
    {
      ch = 'i';
    }
  else if(strcmp(str,"*---")==0)
    {
      ch = 'j';
    }
  else if(strcmp(str,"-*-")==0)
    {
      ch = 'k';
    }
  else if(strcmp(str,"*-**")==0)
    {
      ch = 'l';
    }
  else if(strcmp(str,"--")==0)
    {
      ch = 'm';
    }
  else if(strcmp(str,"-*")==0)
    {
      ch = 'n';
    }
  else if(strcmp(str,"---")==0)
    {
      ch = 'o';
    }
  else if(strcmp(str,"*--*")==0)
    {
      ch = 'p';
    }
  else if(strcmp(str,"--*-")==0)
    {
      ch = 'q';
    }
  else if(strcmp(str,"*-*")==0)
    {
      ch = 'r';
    }
  else if(strcmp(str,"***")==0)
    {
      ch = 's';
    }
  else if(strcmp(str,"-")==0)
    {
      ch = 't';
    }
  else if(strcmp(str,"**-")==0)
    {
      ch = 'u';
    }
  else if(strcmp(str,"***-")==0)
    {
      ch = 'v';
    }
  else if(strcmp(str,"*--")==0)
    {
      ch = 'w';
    }
  else if(strcmp(str,"-**-")==0)
    {
      ch = 'x';
    }
  else if(strcmp(str,"-*--")==0)
    {
      ch = 'y';
    }
  else if(strcmp(str,"--**")==0)
    {
      ch = 'z';
    }
  else
    {
      ch = '?';
    }
  
  return ch;
}

const char* englishToMorse(char ch){
  char* str;
  switch(ch)
     {
     case ' ':
       str = "/";
       break;
       
     case 'a':
     case 'A':
       str = "*-";
       break;
       
     case 'b':
     case 'B':
       str = "-***";
       break;

     case 'c':
     case 'C':
       str = "-*-*";
       break;

     case 'd':
     case 'D':
       str = "-**";
       break;
	      
     case 'e':
     case 'E':
       str = "*";
       break;

     case 'f':
     case 'F':
       str = "**-*";
       break;

     case 'g':
     case 'G':
       str = "--*";
       break;

     case 'h':
     case 'H':
       str = "****";
       break;

     case 'i':
     case 'I':
       str = "**";
       break;

     case 'j':
     case 'J':
       str = "*---";

     case 'k':
     case 'K':
       str = "-*-";
       break;

     case 'l':
     case 'L':
       str = "*-**";
       break;

     case 'm':
     case 'M':
       str = "--";
       break;

     case 'n':
     case 'N':
       str = "-*";
       break;
	      
     case 'o':
     case 'O':
       str = "---";
       break;

     case 'p':
     case 'P':
       str = "*--*";
       break;
	      
     case 'q':
     case 'Q':
       str = "--*-";
       break;
	      
     case 'r':
     case 'R':
       str = "*-*";
       break;

     case 's':
     case 'S':
       str = "***";
       break;

     case 't':
     case 'T':
       str = "-";
       break;

     case 'u':
     case 'U':
       str = "**-";
       break;

     case 'v':
     case 'V':
       str = "***-";
       break;

     case 'w':
     case 'W':
       str = "*--";
       break;

     case 'x':
     case 'X':
       str = "-**-";
       break;

     case 'y':
     case 'Y':
       str = "-*--";
       break;

     case 'z':
     case 'Z':
       str = "--**";
       break;
       
     default:
       str = "XXXX";
       break;
     }

   return str;
}
