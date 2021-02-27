/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-WAP to concatenate two fles
Output		    :-./my_cat
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{

    // File pointer
    FILE *fp1, *fp2, *fp3;

    if (argc == 1)
    {
        char ch[200];
        fgets(ch,200,stdin);
        fputs(ch, stdout);
    }
    else if (argc == 2)
    {
        char ch[200];
        //open 1st file in read mode
        fp1 = fopen(argv[1], "r");
       //error check if file is their or not 
        if (fp1 == NULL)
        {
            perror("\nError opening file 1");
            return -1;
        }
        while (fgets(ch, sizeof(ch), fp1))
                fputs(ch,stdout);
    }
        
    else if (argc == 3)
    {
        char ch[500];
        //open 1st file in read mode
        fp1 = fopen(argv[1], "r");
        if (fp1 == NULL)
        {
            perror("\nError opening file 1");
            return -1;
        }
        //open 2nd file in append mode
        fp2 = fopen(argv[2], "a+");
        //reading content of file 1 and putting in file 2
        while (fgets(ch, sizeof(ch), fp1))
            fputs(ch,fp2);
        rewind(fp2);
        while (fgets(ch,sizeof(ch), fp2))
            fputs(ch, stdout);
        //flush the buffer and close the file
        fclose(fp1);
        fclose(fp2);
    }

    else if (argc == 4)
    {
        char ch[500];
        //open 1st file in read mode
        fp1 = fopen(argv[1], "r");
        if (fp1 == NULL)
        {
            perror("\nError opening file 1");
            return -1;
        }

        //open 2nd file in read mode
        fp2 = fopen(argv[2], "r");
        if (fp2 == NULL)
        {
            perror("\nError opening file 2");
            //flush the buffer and close the file
            fclose(fp1); //if file1 is present but file 2 is not so wehave to close file 1
            return -1;
        }

        //open 3rd file in append mode
        fp3 = fopen(argv[3], "a");
        while ( fgets(ch, sizeof(ch), fp1) || fgets(ch,sizeof(ch), fp2) )
            fputs(ch, fp3);

        //flush the buffer and close the file
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    else
        printf("\nError invalid number of arguments\n");
    return 0;
}

