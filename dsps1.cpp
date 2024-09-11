#include<iostream>
using namespace std;

void linear_search(int a[], int n)
 {
    int i, key, flag = 0;
    cout << "Linear search" << endl;
    cout << "Enter key element: ";
    cin >> key;
    for(i = 0; i < n; i++) 
    {
        if(key == a[i]) 
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
     {
        cout << "Key element " << key << " is found at position " << i << endl;
    } else 
    {
        cout << "Key element is not found" << endl;
    }
}

void binary_search(int a[], int n) 
{
    int low, high, mid, key, flag = 0;
    cout << "Binary search" << endl;
    low = 0;
    high = n - 1;
    cout << "Enter key element: ";
    cin >> key;
    while(low <= high)
     {
        mid = (low + high) / 2;
        if(a[mid] == key)
         {
            flag = 1;
            break;
        }
         else if(a[mid] < key) 
         {
            low = mid + 1;
        }
        else
         {
            high = mid - 1;
        }
    }
    if(flag == 1)
     {
        cout << "Key element " << key << " is found at position " << mid << endl;
    }
     else
      {
        cout << "Key element is not found" << endl;
    }
}

int main()
 {
    int i, n, ch, k;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    int a[n];  // Declare array after getting size
    
    cout << "Enter array elements: ";
    for(i = 0; i < n; i++)
     {
        cin >> a[i];
    }
    
    do
     {
        cout << "1. Linear search\n2. Binary search\nEnter your choice: ";
        cin >> ch;
        switch(ch) 
        {
            case 1:
                linear_search(a, n);
                break;
            case 2:
                // Ensure array is sorted for binary search
                // For simplicity, assuming array is sorted
                binary_search(a, n);
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
        cout << "Do you want to continue? Press 1 for yes, 0 for no: ";
        cin >> k;
    } while(k == 1);

    return 0;
}
