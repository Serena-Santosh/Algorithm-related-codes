/* C implementation QuickSort */
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void swap(int*,int*);
void partiton(int[],int,int,int,int);
void quicksort(int[],int,int);
void printArray(int[],int);
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/* This function partitions a[] in three parts
 a) a[l..i] contains all elements smaller than pivot
 b) a[i+1..j-1] contains all occurrences of pivot
 c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r,int *pi,int *pj)
{
    int i,j;
    i = l-1, j = r;
    int p = l-1, q = r;
    int v = a[r];
    
    while (true)
    {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        while (a[++i] < v);
        
        // From right, find the first element smaller than or
        // equal to v
        while (v < a[--j])
            if (j == l)
                break;
        
        // If i and j cross, then we are done
        if (i >= j) break;
        
        // Swap, so that smaller goes on left greater goes on right
        swap(&a[i], &a[j]);
        
        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            swap(&a[p], &a[i]);
        }
        
        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            swap(&a[j],&a[q]);
        }
    }
    
    // Move pivot element to its correct index
    swap(&a[i], &a[r]);
    
    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    int k;
    for ( k = l; k < p; k++, j--)
        swap(&a[k], &a[j]);
    
    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (k = r-1; k > q; k--, i++)
        swap(&a[i], &a[k]);
    
    *pi = i;
    *pj = j;
}

// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
    if (r <= l) return;
    
    int i, j;
    
    // Note that i and j are passed as reference
    partition(a, l, r, &i, &j);
    
    // Recur
    quicksort(a, l, j);
    quicksort(a, i, r);
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    
}

// Driver program to test above functions
int main()
{
    int arr[10],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
