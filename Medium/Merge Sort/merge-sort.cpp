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
         int len1 = m-l+1;
         int len2 = r - m;
         
         int L[len1];
         int R[len2];
         
         for(int i =0; i<len1; i++){
             L[i] = arr[l+i];
         }
         
         for(int i =0; i<len2; i++){
             R[i] = arr[m+1+i];
         }
         int i = 0;
         int j = 0;
         int k = l;
         
         while(i<len1 && j<len2){
             if(L[i]<=R[j]){
                 arr[k] = L[i];
                 i++;
                 k++;
             }
             else{
                 arr[k] = R[j];
                 j++;
                 k++;
             }
         }
         
         while(i<len1){
             arr[k] = L[i];
             i++;
             k++;
         }
         while(j<len2){
             arr[k] = R[j];
             j++;
             k++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r){
            return;
        }
        int mid = l + (r - l)/2;
        mergeSort(arr, l , mid);
        mergeSort(arr, mid+1, r);
        
        return merge(arr, l, mid, r);
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