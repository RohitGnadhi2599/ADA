#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && a[i] <= pivot)
            i++;
        while (i <= j && a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);
    return j;
}

void quicksort(int a[],int low,int high){
    int point;
    if(low<high){
            point=partition(a,low,high);
            quicksort(a,low,point-1);
            quicksort(a,point+1,high);

    }

}



void main(){
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while (1) {
        printf("\n 1:For manual entry of N value and array elements");
        printf("\n 2:To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n 3:To exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("Enter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                quicksort(a,0,n-1);
                end = clock();
                printf("\nSorted array is: ");
                for (i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;

            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        a[i] = n - i;
                    }
                    start = clock();
                    quicksort(a, 0, n - 1);
                     for (j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                    n = n + 1000;
                }
                break;

            case 3:
                exit(0);
        }
        getchar();
    }
}













