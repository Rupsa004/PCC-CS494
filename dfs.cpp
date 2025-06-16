#include<iostream>
using namespace std;
#define MAX 100

void dfs(int graph[MAX][MAX], int start, int ver, bool visited[MAX]){
    visited[start]=true;
    cout<<start<<" ";

    for(int i=0;i<ver;i++){
        if(graph[start][i]==1 && !visited[i]){
            dfs(graph,i,ver,visited);
        }
    }
}
int main(){
    int graph[MAX][MAX]={0};
    int ver,edges;
    bool visited[MAX]={false};

    cout<<"enter no of ver: \n"<<endl;
    cin>>ver;
    cout<<"no of edges: \n"<<endl;
    cin>>edges;

    cout<<"enter edges from (u,v): \n";
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    int start;
    cout<<"starting dfs: ";
    cin>>start;
    cout<<"dfs trav: ";
    dfs(graph,start,ver,visited);
    cout<<endl;
    return 0;

}