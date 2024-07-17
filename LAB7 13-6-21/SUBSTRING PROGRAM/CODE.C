#include <stdio.h>
#include <string.h>

void substringMatch(char *str, char *sub) {
    int strLen = strlen(str);
    int subLen = strlen(sub);
    int found = 0;

    for (int i = 0; i <= strLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == subLen) {
            printf("Substring found at index %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Substring not found\n");
    }
}

int main() {
    char str[100], sub[100];

    printf("Enter the main string: ");
    gets(str);  // Using gets() for simplicity, but it's better to use fgets() in practice.
    printf("Enter the substring to search for: ");
    gets(sub);

    substringMatch(str, sub);

    return 0;
}
