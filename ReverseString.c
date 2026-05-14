#include <stdio.h>
#include <string.h>

void reverse_string(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main()
{
    char str[] = "Hello, World!";

    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    // Test with another string
    char str2[] = "One Piece";
    printf("\nOriginal string: %s\n", str2);
    reverse_string(str2);
    printf("Reversed string: %s\n", str2);

    return 0;
}