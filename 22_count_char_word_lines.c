/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:-2 may 2020
Description	:-To execute and count no. of characters, words and lines entered through stdin buffer till EOF is received.
Input		:-User will enter character by character in stdin buffer to find the no. of characters, words and lines.
Output		:-./nocharacter_words_line
		  Enter a Paragraph 
		  Hello   world
		     how   you all     doing 
		  No. of Character :  39
		  No. of Words     :  6
		  No. of Lines	   :  2
*/

#include<stdio.h>
int main()
{
    char c;		//User prompt defination;
    do
    {
	char ch;
	int ch_count = 0, word_count = 0, line_count = 1, f1 = 0;
	while ((ch=getchar()) != EOF)   //loop will iterate till the EOF is recieved
	{
	    if (ch != '\n')
		++ch_count;          //character will be increment till \n not recieved
	    if (ch == '\n')
		++line_count;        //line will get increment when \n is recieved
	    if (ch == ' '|| ch == '\t')       //condition to check if space or tab is their
		f1 = 0;         //flag will be set to 0
	    else if (ch != ' ' || ch !='\t')     //if no space or tab is their
	    {
		if (f1 == 0)
		{
		    ++word_count;
		    f1 = 1;
		    if (ch == '\n')
		    {
			--word_count;   //decrement the word if space is their at the end
			f1 = 0;
		    }
		}
		else if (ch == '\n')
		    f1 = 0; 
	    }
	    else if (ch == '\n')
		f1 = 0;
	}
	printf("\n\nNo of Character : %d\nNo of Words : %d\nNo of Line : %d\n",ch_count,word_count,line_count);
	printf("\n\nDo you want to continue again? (y/n) ");
	scanf("\n%c%*c",&c);
    } while (c == 'y');		//User prompt do while body ending
    return 0;
} 

