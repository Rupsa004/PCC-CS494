#include<iostream>
using namespace std;

void max_min(int arr[],int i,int j,int &max,int &min){
    if(i==j){
        max=min=arr[i];
    }
    else if(i==j-1){
        if(arr[i]<arr[j]){
            max=arr[j];
            min=arr[i];
        }
        else{
            max=arr[i];
            min=arr[j];
        }
    }
    else{
        int mid=(i+j)/2;
        int max1,min1;
        max_min(arr,i,mid,max,min);
        max_min(arr,mid+1,j,max1,min1);
        if(max<max1)
            max=max1;
        if(min1<min)
            min=min1;    
    }
}

int main(){
    int size;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    cout<<endl;

    int *a=new int[size];
    cout<<"enter elements "<<endl;
    for(int i=0;i<size;i++)
        cin>>a[i];
    cout<<endl;
    int max=a[0];
    int min=a[0];
    max_min(a,0,size-1,max,min);
    cout<<"max: "<<max<<endl;
    cout<<"min: "<<min<<endl;
    return 0;   
    
}


