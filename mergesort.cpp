#include<stdio.h>

void merge(int a[], int low, int high, int mid) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[10]; // Define an array to store merged result

    while(i <= mid && j <= high) {
        if(a[i] < a[j]) {
            b[k] = a[i];
            i++;
            k++;
        } else {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while(j <= high) {
        b[k] = a[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

int main() {
    int a[10], n, i;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
