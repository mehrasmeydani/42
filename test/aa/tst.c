#include <stdio.h>
#include <bsd/string.h>


int main()
{
    const char *largestring = "Baz Bar Baz";
    const char *smallstring = "Barc";
    char *ptr;
    char *ptr1 = 0;
    ptr = strnstr(largestring, smallstring, 2);
    printf("%s", ptr);
    printf("%s\n%s", (char *)NULL, ptr1);

    return 0;
}
