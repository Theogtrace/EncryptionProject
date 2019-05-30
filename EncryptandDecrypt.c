/*
 *  * Saad Arshad 00857432
 *   * CS 262 section 004
 *    * Project 1
 *     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BSIZE 100
#define KSIZE 20
#define CSIZE 44
#define MSIZE 250

const char CHARSET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,;!-'?";

int getPrintMenu(int , char[]);
void getSeed(char[], char[]);
void getKeyword(char[]);
void getEncrypt(char[], char[]);
void getDecrypt(char[], char[]);
int getPosition(const char *str, char);

int main()
{
	int x = 0;
	while(x != 6)
	{

		char Buffer[BSIZE];
		int choice;
		choice = getPrintMenu(choice, Buffer);
		char keyword[KSIZE];
		char charSet[CSIZE];
		int cSeed;
		int cKey;
		
		switch (choice)
		{
			case 1:
				getSeed(charSet, Buffer);
//				printf("scrambled charSet is %s\n", charSet);
				cSeed = 1;							
				break;
			case 2:
				getKeyword(keyword);
				printf("\nThe keyword you entered is %s\n", keyword);
				cKey = 1; 
				break;
			case 3:
				if(cKey == 1 && cSeed == 1)
				{
					getEncrypt(keyword, charSet);
				}
				else
				{
					printf("\nNo seed or keyword entered!\n ");
					choice = 9;	
				}
				break;
			case 4:
				if(cKey == 1 && cSeed == 1)
				{
					getDecrypt(keyword, charSet);
				}
				else
				{
					printf("\nNo seed or keyword entered!\n ");
					choice = 9;	
				}
				break;
			case 9:
				choice = getPrintMenu(choice, Buffer);
				break;
			case 5:
				printf("Closing Program.\n");
				x = 6;
				break;
			default:
				printf("Invalid input.\n");
				break;

		}//switch


	}//while

}

int getPrintMenu(int choice, char Buffer[]) 
{
	printf("\nEnter a random number seed 1 \n");
	printf("Enter the Keyword 2\n");
	printf("Enter a message to encrypt 3 \n");
	printf("Enter a message to decrypt 4 \n");
	printf("Quit Program 5\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%d", &choice);
	return choice;
	
}

void getKeyword(char keyword[])
{
	int i = 0;
	printf("\nEnter your keyword \n");
	fgets(keyword, KSIZE, stdin);
	keyword[strlen(keyword)-1] = '\0';
	while(keyword[i])
	{
		keyword[i] = toupper(keyword[i]);	
		i++;
	
	}
}

void getSeed(char charSet[], char Buffer[])
{
	int seed = 0;
	int valid = 0;
	int idx = 0;
	do
	{
		printf("\nEnter Seed \n");
		fgets(Buffer, BSIZE, stdin);
		sscanf(Buffer, "%d", &seed); 
		if(seed >= 0)
		{

			srandom(seed);
			strcpy(charSet, CHARSET);
//			printf("charset = %s\n", charSet); 	
			for (int i = strlen(charSet) - 1; i > 0; i--)
			{	
   				 char temp;
   				 idx = random()%(i+1);
   				 temp = charSet[idx];
   				 charSet[idx] = charSet[i];
	   			 charSet[i] = temp;
			}
			valid = 1;
		}
		else 
		{
			printf("invalid entry, please re enter input. \n");
		}

	}while(valid == 0);


} 



int getPosition(const char *str, char c)
{
  int retVal = -1;
  char *pos = strchr(str, c);

  if (pos != NULL)
  {
    retVal = pos - str;
  }

  return retVal;
}


void getEncrypt(char keyword[], char charSet[]) 
{
	
	int x = 0;
	int y = 0;
	int z = 0;
	int k = 0;

	char msg[MSIZE];
	char Newmsg[MSIZE];


	printf("Enter you message that you would like to encrypt \n");
	fgets(msg, MSIZE, stdin);
	msg[strlen(msg)-1] = '\0';

	while(msg[k])
	{
		msg[k] = toupper(msg[k]);
		k++;
	}

	printf("This is the MSG you entered %s\n" , msg);


	for(int i = 0; i < strlen(msg) ; i++)
	{
		x = getPosition(CHARSET, msg[i]);
		y = getPosition(CHARSET, keyword[i % strlen(keyword)]);
		z = (x + y) % strlen(charSet);		
		Newmsg[i] = charSet[z];
//		printf(" new msg %s\n", Newmsg);
	}

	printf("This is the new Encrypted msg = %s\n", Newmsg);

}


void getDecrypt(char keyword[], char charSet[])
{

	int x = 0;
	int y = 0;
	int z = 0;
	int j = 0;
	char msg[MSIZE];
	char Newmsg[MSIZE];


	printf("Enter you message that you would like to decrypt\n");
	fgets(msg, MSIZE, stdin);

	msg[strlen(msg)-1] = '\0';

	while(msg[j])
	{
		msg[j] = toupper(msg[j]);
		j++;
	}

	printf("This is the MSG you entered %s\n" , msg);

	for(int i =0; i < strlen(msg) ; i++)
	{
		x = getPosition(charSet, msg[i]);
		y = getPosition(CHARSET, keyword[i % strlen(keyword)]);
		z = (x - y);

		if(z < 0)
		{
			z = z + strlen(charSet);
		}		
		Newmsg[i] = CHARSET[z];
	}

	printf("This is the normal msg %s\n", Newmsg);
}






























