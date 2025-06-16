#include<iostream>
#include<climits>
using namespace std;

int n,p[100],cost[10][10],kvalue[10][10];

void initialize(){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i==j){
                cost[i][j]=0;
            }
            else{
                cost[i][j]=INT_MAX;
            }
        kvalue[i][j]=0;
            
        }
    }

}
void matchain(){
    initialize();
    for(int l=2;l<=n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            cost[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q=cost[i][k]+cost[k+1][j]+(p[i-1]*p[k]*p[j]);
                if (q<cost[i][j]){
                    cost[i][j]=q;
                    kvalue[i][j]=k;
                    }
                }
            }
        }
    }

void printCostmat(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%6d",cost[i][j]);
        }
        printf("\n");
    }
}
void printkvalue(){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%6d",kvalue[i][j]);
        }
        printf("\n");
    }
}

int main(){
    cout<<"enter no of matrix: "<<endl;
    cin>>n;
    cout<<"enter matrix orders: "<<endl;
    for(int i=0;i<=n;i++){
        scanf("%d",&p[i]);
    }
    matchain();
    cout<<"\ncost mat:\n"<<endl;
    printCostmat();
    cout<<"\n k val mat:\n"<<endl;
    printkvalue();
    cout<<endl;
    return 0;
}