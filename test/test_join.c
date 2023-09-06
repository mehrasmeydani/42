#include <stdio.h>
#include <stdlib.h>

// Function prototypes
char *ft_strjoin(int size, char **strs, char *sep);

// Test function
void test_ft_strjoin(char **strs, char *sep, int size) {
    printf("Input strings:\n");
    for (int i = 0; i < size; i++) {
        printf("strs[%d]: \"%s\"\n", i, strs[i]);
    }
    printf("Separator: \"%s\"\n", sep);

    char *result = ft_strjoin(size, strs, sep);

    if (result != NULL) {
        printf("Concatenated string: \"%s\"\n", result);
        free(result); // Free the dynamically allocated memory
    } else {
        printf("Error: Memory allocation failed!\n");
    }

    printf("----------------------------\n");
}

int main() {
    // Test cases
    char *strs1[] = {"Hello", "world", "!", NULL};
    char sep1[] = " ";
    int size1 = 3;

    char *strs2[] = {"This", "is", "a", "test", NULL};
    char sep2[] = "-";
    int size2 = 4;

    char *strs3[] = {"Concatenate", "these", "strings", NULL};
    char sep3[] = "->";
    int size3 = 3;

    test_ft_strjoin(strs1, sep1, size1);
    test_ft_strjoin(strs2, sep2, size2);
    test_ft_strjoin(strs3, sep3, size3);

    return 0;
}
