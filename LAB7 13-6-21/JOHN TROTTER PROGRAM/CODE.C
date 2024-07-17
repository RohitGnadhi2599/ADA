#include <stdio.h>
#include <stdbool.h>
#define MAX_N 10
#define LEFT 0
#define RIGHT 1

typedef struct
{
    int value;
    int direction;
} Element;
void printPermutations(int n);
void generatePermutations(Element permutation[], int n);
int findLargestMobile(Element permutation[], int n);
int main()
{
    int n;
    printf("Enter the number of elements (max %d): ", MAX_N);
    scanf("%d", &n);

    if (n > MAX_N || n <= 0)
    {
        printf("Invalid input size. Please enter a valid number between 1 and %d.\n", MAX_N);
        return 1;
    }
    printf("Permutations of %d elements:\n", n);
    printPermutations(n);
    return 0;
}
void printPermutations(int n)
{
    Element permutation[MAX_N];
    for (int i = 0; i < n; i++)
    {
        permutation[i].value = i + 1;
        permutation[i].direction = LEFT;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", permutation[i].value);
    }
    printf("\n");
    generatePermutations(permutation, n);
}
void generatePermutations(Element permutation[], int n)
{
    while (true)
    {
        int mobileIdx = findLargestMobile(permutation, n);
        if (mobileIdx == -1)
        {
            break;
        }
        int swapIdx = mobileIdx + (permutation[mobileIdx].direction == LEFT ? -1 : 1);
        Element temp = permutation[mobileIdx];
        permutation[mobileIdx] = permutation[swapIdx];
        permutation[swapIdx] = temp;
        for (int i = 0; i < n; i++)
        {
            if (permutation[i].value > permutation[swapIdx].value)
            {
                permutation[i].direction = (permutation[i].direction == LEFT) ? RIGHT : LEFT;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", permutation[i].value);
        }
        printf("\n");   }    }
int findLargestMobile(Element permutation[], int n)
{
    int mobileIdx = -1;
    int maxMobileValue = -1;
    for (int i = 0; i < n; i++)
    {
        int direction = permutation[i].direction;
        int adjacentIdx = i + (direction == LEFT ? -1 : 1);
        if (adjacentIdx >= 0 && adjacentIdx < n &&
            permutation[i].value > permutation[adjacentIdx].value &&
            permutation[i].value > maxMobileValue)
        {
            mobileIdx = i;
            maxMobileValue = permutation[i].value;
        }   }
    return mobileIdx;
}
