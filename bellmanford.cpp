#include<iostream>
#include<stdlib.h>
#define INF 999

int n, graph[10][10],dist[100];

void readGraph(){
    FILE *fp;
    fp= fopen("ford.txt","r");
    if(fp==NULL){
        printf("file does not exist");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);
}

void showGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%6d", graph[i][j]);
        }
        printf("\n");
    }
}

int bellman(int start){
    for(int i=0;i<n;i++)
        dist[i]=INF;

    dist[start]=0;

    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]!=INF && dist[i]!=INF && dist[i]+graph[i][j]<dist[j]){
                    dist[j]=dist[i]+graph[i][j];                
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=INF && dist[i]!=INF && dist[i]+graph[i][j]<dist[j]){
                return 0;
            }
        }
    }
    return 1;

}

void printresult(){
    printf("\nshortest dist from source: \n");
    for(int i=0;i<n;i++){
        if(dist[i]==INF)
            printf("s to %c-> unreachable\n",'A'+i);
        else
            printf("S to %c -> %d\n", 'A'+i,dist[i]);
        }
    }

int main(){
    readGraph();
    showGraph();
    int result = bellman(0);
    if(result)
        printresult();
    else
        printf("contains negative cycle");
return 0; 
}