#include<iostream>
using namespace std;
#define MAX 100

void merge(int a[],int p,int q,int r){
    int C[MAX];
    int i=p, j=q+1,k=p;
    while(i<=q && j<=r){
        if(a[i]<=a[j]){
            C[k++] = a[i++];
        }
        else{
            C[k++] =a[j++];
        }
    }
    while(i<=q)
        C[k++]=a[i++];
    while(j<=r)
        C[k++]=a[j++];
    for(int i=p;i<=r;i++)
        a[i]=C[i];
    }
void mergeSort(int a[],int p,int r){
    if(p<r){
        int m=((p+r)/2);
        mergeSort(a,p,m);
        mergeSort(a,m+1,r);
        merge(a,p,m,r);

    }
}
int main(){
    int size;
    cout << "Enter Size of Array:";
    cin >> size;
    int a[size];
    cout << "Enter elements:";
    for (int i = 0; i < size; i++)
        cin >> a[i];
    mergeSort(a, 0, size - 1);
    cout << "Sorted Array:";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
