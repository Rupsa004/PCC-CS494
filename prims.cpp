#include<iostream>
#define MAX 100
using namespace std;

int cost[MAX][MAX];
int n;

void readGraph(){
    FILE*fp;
    fp= fopen("graph.txt","r");
    if(fp==NULL){
        cout<<"file does not exist"<<endl;
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for (int i=0;i<n;i++)
        for(int j=0;i<n;j++)
            fscanf(fp, "%d", &cost[i][j]);
    fclose(fp);
}

void showGraph(){
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            printf("%3d" , cost[i][j]);
            cout<<endl;
    }

int parent[MAX];
int key[MAX];
int MST[MAX];

int get_minVer(){
    int min= 9999, index=-1;

    for(int i=0;i<n;i++){
        if(MST[i]==0 && key[i]<min){
            min=key[i];
            index=i;

        }
    }
    return index;
}

void PrimsMST(int start){
    for(int i=0;i<n;i++){
        key[i]=9999;
        parent[i]=-1;
        MST[i]=0;
    }
    key[start]=0;

    for(int i=0; i<n;i++){
        int u= get_minVer();
        MST[u]=1;
        for(int v=0;v<n;v++){
            if(cost[u][v]!=0 && MST[v]==0 && cost[u][v]<key[v]){
                key[v]=cost[u][v];
                parent[v]=u;
            }
        }
   }
}


   void displayMST() {
    int totalCost = 0;
    cout << "\nMinimum Spanning Tree (MST):\n";
    for (int i = 1; i < n; i++) {
        printf("%c -> %c : %d\n", parent[i] + 'A', i + 'A', cost[parent[i]][i]);
        totalCost += cost[parent[i]][i];
    }
    cout << "Total cost of MST: " << totalCost << endl;
}


int main(){
    readGraph();
    showGraph();
    PrimsMST(0);
    displayMST();
    return 0;
}