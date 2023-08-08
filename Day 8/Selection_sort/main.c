#include <stdio.h>
#include <stdlib.h>

int selection(int arr[],int n){
    int pos=0;
    for(int i=0;i<n-1;i++){
         int mini=arr[i];

    for(int j=i+1;j<n;j++){
        if(mini>arr[j]){
            mini=arr[j];
            pos=j;
        }


    if(pos!=i){
        int temp=arr[pos];
        arr[pos]=arr[j];
        arr[j]=temp;
    }
    }
    }


}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
int main()
{
    int arr={34,3,56,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    selection(arr,n)
    printf("Sorted array is:");
    printarr(arr,n);
    return 0;

}
