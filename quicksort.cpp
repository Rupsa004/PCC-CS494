#include<iostream>
using namespace std;

int hoverpart(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l-1;
    int j=h+1;
    while(i<j){
        do{
        i++;
        }
        while(arr[i]<pivot);
        do{
            j--;
        }
        while(arr[j]>pivot);
        if(i>j)
            return j;
        swap(arr[i],arr[j]);
    }
}

void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=hoverpart(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return;
}

int main(){
    int n;
    cout<<"no of enter element: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr,0,n-1);
    cout<<"show array: "<<endl;
    print(arr, n);
    return 0;
}