#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    int L[n1], R[n2]; 
   
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 

    int i = 0;  
    int j = 0;  
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    for(int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout<<endl<<endl;
} 

void find_min_max(int arr[], int size, int x){
    int min = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] > x){
            if(min == -1 || arr[i] < arr[min]){
                min = i;
            }
        }
    } cout<<min<<endl<<endl;
}

void find_max_min(int arr[], int size, int x){
    int max = 0, min = 0;
    for(int i = 0; i < size; i++){
        if( arr[i] > max ){
            max  = arr[i];
            if( max < x )
                min = max;
        }
    } cout<<min<<endl<<endl;
}

int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int x;
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 

    printArray(arr, arr_size);
    cin>>x; 
    find_min_max(arr,arr_size,x);

    cin>>x;
    find_max_min(arr,arr_size,x);
    return 0; 
} 
