#include<iostream>
using namespace std;


int n, graph[10][10], d[10][10],p[10][10];

void readgraph(){
    FILE *fp;
    fp= fopen("flod.txt","r");
    if(fp==NULL){
        printf("file doesnot exist");
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

void showgraph(){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%6d", graph[i][j]);
        }
        printf("\n");
    }
}

void initialize(){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=graph[i][j];
            if(graph[i][j]==0||graph[i][j]==999){
                p[i][j]=-1;
            }
            else{
                p[i][j]=i;
            }   
        }
    }
}

void fly_war(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];                
                }
            }
        }
    }
}

void Dmatrix(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%6d",d[i][j]);
        }
        printf("\n");
    }
}

void Pmatrix(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%6d",p[i][j]);
        }
        printf("\n");
    }
}

void shortestPath(int i,int j){
    if(i==j){
        printf("%c",'A'+i);
    }
    else if(p[i][j]==-1){
        printf("no path");
    }
    else{
        shortestPath(i,p[i][j]);
        printf("%c",'A'+j);
    }
}
void printShortestpath(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)
                printf("path from %d to %d\n",i,j,d[i][j]);
                shortestPath(i,j);
                printf("\n");
        }
    }
}

int main(){
    int i, j;
    readgraph();
    showgraph();
    initialize();
    fly_war();
    printf("\ndistance matrix: \n");
    Dmatrix();
    printf("\nparentMatrix: \n");
    Pmatrix();
    printShortestpath();
    return 0;
}