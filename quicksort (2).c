#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

int arr[40000] , n= 40000;

int pivot(int lb, int ub){
    int start = lb , end = ub, pivot= arr[lb] , temp;
    while (start<end){
        while (arr[start]<=pivot)
            start++;
        while (arr[end]>pivot)
            end--;
        if(start<end){
            temp=arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        

    }
    temp=arr[end];
    arr[end]=arr[lb];
    arr[lb]=temp;
    return end;
}
void quicksort(int low , int high){
    if(low<high){
        int pi = pivot(low,high);
        quicksort(low,pi-1);
        quicksort(pi+1,high);
    }
}



int main() {
    clock_t t1,t2;
    int i;
    // j=1;
    //Worst case
    
    // for(i=n;i>=1;i--)
    // {
    //     arr[j]=i;
    //     j++;
    // }
    
    //best case
    for(i=1;i<=n;i++)
    {
        arr[i]=i; 
    }

    //Average case
    
    // for(i=1;i<=n;i++)
    // {
    //     num=rand();
    //     arr[i]=num; 
    // }
    
    t1 = clock();
    quicksort(0, n-1);  
    t2 = clock();
    int t3 = (t2 - t1);
    
    printf("Time taken to sort: %ld ",t3);
    return 0;

}