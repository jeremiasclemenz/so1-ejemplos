#include <stdio.h>

/*
Compute the length of a string manually without using strlen() function.
*/
int main()
{
	char s[1000];
	unsigned i;

    printf("Enter a string: ");
    scanf("%s", s);

    for(i = 0; s[i] != '\0'; ++i);

    printf("Length of string: %d\n", i);
    
    return 0;
}
