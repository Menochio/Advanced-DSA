#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int start,int mid,int end){
    // 0 1 2
    int leftIndex = mid-start+1;
    int rightIndex = end-mid;
    cout<<leftIndex<<" "<<rightIndex<<endl;
    int leftArray[mid-start+1]; // 2
    int rightArray[end-mid]; // 1
    for(int i=0;i<leftIndex;i++){
        leftArray[i]=a[start+i];
    }
    for(int j=0;j<rightIndex;j++){
        rightArray[j]=a[mid+1+j];
    }
    

    int i=0,j=0,k=start;
    while(i<leftIndex && j<rightIndex){
        if(leftArray[i]<rightArray[j]){
            a[k]=leftArray[i];
            i++;
        }
        else{
            a[k]=rightArray[j];
            j++;
        }
        k++;
    }
    while(i<leftIndex){
        a[k]=leftArray[i];
        k++;
        i++;
    }
    while(j<rightIndex){
        a[k]=rightArray[j];
        j++;
        k++;
    }
    
}
void mergeSort(int a[],int start,int end){
    if(start>=end)return;
   
    int mid = start+(end-start)/2;
     cout<<start<<" "<<mid<<" "<<end<<endl;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a,start,mid,end);

}

int main()
{
    int a[]={6,5,4,3,2,1};
    int len = sizeof(a)/sizeof(int);
    mergeSort(a,0,len);
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}