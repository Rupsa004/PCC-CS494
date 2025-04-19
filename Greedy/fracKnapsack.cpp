#include<iostream>
using namespace std;

struct Item{
    int profit;
    int weight;
};

void sort(Item arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            double i1=(double)arr[j].profit/arr[j].weight;
            double i2=(double)arr[j+1].profit/arr[j+1].weight;
                if(i1<i2){
                    Item temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
               }
            }
        }
    }
double fracKnapsack(Item arr[],int n,int M){
    sort(arr,n);
    double profit=0.0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<=M){
            profit+=arr[i].profit;
            M-=arr[i].weight;
        }
        else{
            profit+=arr[i].profit*((double)M/arr[i].weight);
            break;
        }
    }
    return profit;
}
int main(){
    int n,M;
    cout<<"enter no of items:";
    cin>>n;
    cout<<"enter max weight: ";
    cin>>M;
    Item arr[n];
    cout<<"enter profit and weight of each item: "<<endl;
    for(int i=0; i<n;i++){
        cout<<"item "<<i+1<<": ";
        cin>>arr[i].profit>>arr[i].weight;
    }
    double maxProfit = fracKnapsack(arr, n, M);
    cout << "Maximum profit can be obtained: " << maxProfit << endl;

    return 0;
}
/* 
int n=7;
int M=15;
Item arr[]={{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
cout<<"max value obtained: "<<fracKnapsack(arr,n,M);
return 0;
*/