#include<iostream>
#include<stdio.h>
#define MAX 100
using namespace std;

int cost[MAX][MAX];
int n;

void readGraph(){
    FILE *fp;
    fp = fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"file doesn't exist";
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp, "%d" , &cost[i][j]);
        }
    }
    fclose(fp);
}

void showGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",cost[i][j]);
        }
        cout<<endl;
    }
}

int key[MAX];
int parent[MAX];
int mstSet[MAX];

int min_vertex(){
    int index=-1;
    int min=9999;
    for(int i=0;i<n;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}

void Prims(int start){
    for(int i=0;i<n;i++){
        key[i]=9999;
        mstSet[i]=0;
    }
    key[start]=0;
    for(int i=0;i<n;i++){
        int u=min_vertex();
        mstSet[u]=1;
        for(int v=0;v<n;v++){
            if(cost[u][v]!=0 && mstSet[v]==0 && key[v]>cost[u][v]){
                key[v]=cost[u][v];
                parent[v]=u;
            }
        }
    }
}

void displayMST(){
    int cost=0;
    for(int i=0; i<n; i++){
       if(parent[i]!=-1){
        printf("%c -> %c : %d\n", parent[i] + 'A', i + 'A', ::cost[parent[i]][i]);
        cost +=key[i];
        } 
    }
       cout << "Total cost of MST: " << cost << endl;
}

    int main(){
        readGraph();
        showGraph();
        Prims(0);
        displayMST();
        return 0;
    }
    
