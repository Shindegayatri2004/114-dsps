#include<stdio.h>

void main() {
    int i, n, j, k, temp, a[10];
    int comp = 0, pass = 0;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for(i = 1; i < n; i++) 
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] > a[i])
            {
                temp = a[i];
                for(k = i; k > j; k--) 
                {
                    a[k] = a[k - 1];
                }
                a[j] = temp;
            }
            comp+=1;
        }
        pass+=1;
    }
    
    printf("Sorted array:");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    printf("No of comparisons in insertion sort: %d\n", comp);
    printf("No of passes in insertion sort: %d\n", pass);
}
