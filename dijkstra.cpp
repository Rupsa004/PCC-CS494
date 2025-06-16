#include<iostream>
#define MAX 100
using namespace std;

int cost [MAX][MAX];
int n;

void readGraph(){
    FILE *fp;
    fp= fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"file does not exit";
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&cost[i][j]);
        }
    }
    fclose(fp); 
}

void showGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",cost[i][j]);
        }
        printf("\n");
    }
}

int parent[MAX];
int key[MAX];
int mstset[MAX];

int min_ver(){
    int min=9999;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mstset[i]==0 && key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}

void Dijkstra(int start){
    for(int i=0;i<n;i++){
        key[i]=9999;
        parent[i]=-1;
        mstset[i]=0;
    }
    key[start]=0;
    for(int i=0;i<n;i++){
        int u=min_ver();
        mstset[u]=1;
        for(int v=0;v<n;v++)
            if(cost[u][v]!=0 && mstset[v]==0 && cost[u][v]<key[v]){
                key[v]=cost[u][v];
                parent[v]=u;
            }
        }
    }
void printpath(int src, int dest){
    if(src==dest){
        cout<<src<<" ";
        return;
    }
    printpath(src,parent[dest]);
    cout<<dest<<" ";
}
void pathcost(int src){
    for(int i=0;i<n;i++){
        if(i!=src){
            cout<<"path from "<<src<<" to "<<i<<": ";
            printpath(src,i);
            cout<<endl;
        }
    }
}

int main(){
    readGraph();
    showGraph();
    int src=0;
    Dijkstra(src);
    pathcost(src);
    return 0;
}