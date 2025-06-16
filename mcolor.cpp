#include<iostream>
using namespace std;

bool isSafe(int graph[10][10],int n,int k,int color[10],int c){
    for(int i=0;i<n;i++){
        if(graph[k][i]==1 && color[i]==c){
            return false;
        }
    }
    return true;
}

void mcolor(int graph[10][10],int n,int k,int color[10],int m){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(graph,n,k,color,i)){
            color[k]=i;
            mcolor(graph,n,k+1,color,m);
            color[k]=0;
        }
    }
}
int main(){
    int graph[10][10],n,m,color[10];
    FILE *fp;
    fp=fopen("color.txt","r");
    if(fp==NULL){
        cout<<"error";
        return 0;
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the number of colors: ";
    cin>>m;
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    mcolor(graph,n,0,color,m);
    return 0;
}