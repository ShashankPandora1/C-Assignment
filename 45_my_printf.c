/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-WAP to implement my_printf() function.
Input           :- Implement for:
                1. int
                2. char
                3. string
Output		    :-./my_printf
                Enter a number, char, string: 20, c, Hello
                Output: 20 c Hello
*/
#include<stdio.h>
#include<stdarg.h>
#include<stdio_ext.h>

//function prototype
int my_printf(const char *format, ...);

int main()
{
    char ch;
    do  //user prompt do while
    {
        __fpurge(stdin);
        int num, i;
        char c, str[25];
        fprintf(stdout, "Enter a number, char, string : ");
        scanf("%d %c %s", &num, &c, str);
        my_printf("Output : %d, %c, %s" , num, c, str);
        fprintf(stdout,"\n\nDo you want to continue again (y/n) ? : ");
        scanf("\n%c%*c", &ch);
    }
    while (ch == 'y'); //user prompt do while body ending
        return 0;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    va_start (ap , *format);
    int i, count = 0;
    char c, *str;
    while (*format != '\0')
    {
        count++;
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                    count += fprintf(stdout,"%d", va_arg(ap, int ));
                    count--;
                    break;
                case 'c':
                    putchar(va_arg(ap, int));
                    break;
                case 's':
                    str = va_arg(ap, char*);
                    while (count++, putchar(*str++) );
                    count -= 2;
                    break;
            }
            format++;
        }
        else
            putchar(*format++);
    }
    va_end(ap);
    return count;
}
