//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int i = l;
         int left[m-l+2];
         int right[r-m+1];
         left[m-l+1] = INT_MAX;
         right[r-m] = INT_MAX;
         
         for (int j=l; j<=m; j++) {
             left[j-l] = arr[j];
         }
         
         for(int j=m+1; j<=r; j++) {
             right[j - m - 1] = arr[j];
         }
         int pl = 0;
         int pr = 0;
         while(i<=r) {
            if (left[pl] <= right[pr]) {
                arr[i] = left[pl];
                pl++;
            } else {
                arr[i] = right[pr];
                pr++;
            }
            i++;
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l>=r) {
            return;
        }
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends