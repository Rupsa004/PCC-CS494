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

double knap(Item arr[],int n,int capacity){
    sort(arr,n);
    double profit=0.0;

    for(int i=0;i<n;i++){
        if(arr[i].weight<=capacity){
            profit+=arr[i].profit;
            capacity-=arr[i].weight;
    }
    else{
        profit+=arr[i].profit*((double)capacity/arr[i].weight);
        break;
        }
    }
    return profit;

}

int main() {
    int n, m;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight: ";
    cin >> m;

    Item arr[n];
    cout << "Enter profit and weight of each item:\n";
    for(int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> arr[i].profit >> arr[i].weight;
    }

    double maxProfit = knap(arr, n, m);
    cout << "Maximum profit can be obtained: " << maxProfit << endl;

    return 0;
}