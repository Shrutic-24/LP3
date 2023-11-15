//Write a program for analysis of quick sort by using deterministic and randomized variant.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int h){
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void QuickSort(int arr[],int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        QuickSort(arr,l,p-1);
        QuickSort(arr,p+1,h);
    }
}


int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elemts: "<<endl;
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    //random
    QuickSort(arr,0,n-1);
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}