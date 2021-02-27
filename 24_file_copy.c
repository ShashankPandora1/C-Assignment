/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-Take two fle names through command line
                  Do error checking.
                  ◦ Check command line args
                  ◦ Check fle open status
                  Open frst fle in read mode
                  Open second fle in write mode
                  Copy frst fle contents into second fle.
Output		    :-./copy_file
*/
#include<stdio.h>
#include<stdlib.h>
//function prototype
void file_copy(FILE *fp1, FILE *fp2);

int main(int argc, char **argv)
{

    //file pointer
    FILE *fp1;  //pointer to file 1
    FILE *fp2; //pointer to file 2
    /* argument count should be 3
       1st--> arg is ./a.out
       2nd--> arg is file 1
       3rd--> arg is file 2
    */

    //error check for argument passed
    if(argc != 3)
    {
        printf("\nCheck number of argument passed\n");
        return -1;
    }
    else
    {
        /*
           open first file in read mode only
           passing file through comand line
           argv[1] points to file 1
        */
        fp1 = fopen(argv[1], "r");
        //error check fopen is success or not for file1.txt
        if (fp1 == NULL)
        {
            perror("error in open file1");
            return -1;
        }
        //error check if fopen is success or not for file2.txt
        fp2 = fopen(argv[2], "w");
        if (fp2 == NULL)
        {
            perror("error in open file2");
           // fclose(fp1);
            return -1;
        }
        /*read character from file1.txt till EOF is recieved
          and copy it to file2.txt */
    }
    file_copy(fp1, fp2);
    fclose(fp1);
    fclose(fp2);

    return 0;
}

void file_copy(FILE *fp1, FILE *fp2)
{
    //looping to read character by character till NULL is recieved 
    char ch[2000];
    while (fgets(ch, sizeof(ch), fp1) != NULL)
    {
        fputs(ch,fp2); //putting in file 2
    }
}
