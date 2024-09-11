#include <stdio.h>

#define SIZE 10 // Define the size of the price array

int price[SIZE]; // Array to store book prices
int i, j, temp;

// Function to print books with price less than 500
void arr1() 
{
    int tem[SIZE]; // Array to store prices less than 500
    int count = 0; // Counter for the number of books with price < 500
    
    printf("Books having price less than 500:\n");
    for (i = 0; i < SIZE; i++) 
    {
        if (price[i] < 500)
         {
            tem[count] = price[i];
            printf("%d ", tem[count]);
            count++;
        }
    }
    if (count == 0)
     {
        printf("None\n"); // Handle case where no prices are less than 500
    }
    printf("\n");
}

// Function to remove duplicate prices
void arr2() 
{
    int tempArray[SIZE]; // Array to store unique prices
    int uniqueCount = 0; // Counter for unique prices
    
    for (i = 0; i < SIZE; i++)
     {
        int isDuplicate = 0;
        for (j = 0; j < uniqueCount; j++)
         {
            if (price[i] == tempArray[j]) 
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate)
         {
            tempArray[uniqueCount] = price[i];
            uniqueCount++;
        }
    }
    
    printf("Unique prices:\n");
    for (i = 0; i < uniqueCount; i++)
     {
        printf("%d ", tempArray[i]);
    }
    if (uniqueCount == 0) 
    {
        printf("None\n"); // Handle case where no unique prices exist
    }
    printf("\n");
}

int main()
 {
    printf("Enter the price of 10 books:\n");
    for (i = 0; i < SIZE; i++)
     {
        scanf("%d", &price[i]);
    }

    // Sorting the array using Bubble Sort
    for (i = 0; i < SIZE - 1; i++)
     {
        for (j = 0; j < SIZE - 1 - i; j++)
         {
            if (price[j] > price[j + 1])
             {
                temp = price[j];
                price[j] = price[j + 1];
                price[j + 1] = temp;
            }
        }
    }

    // Print the sorted prices
    printf("Sorted prices:\n");
    for (i = 0; i < SIZE; i++) 
    {
        printf("%d ", price[i]);
    }
    printf("\n");

    // Call functions to handle specific tasks
    arr1();
    arr2();

    return 0;
}

