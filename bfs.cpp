#include<iostream>
#include<queue>
using namespace std;
#define MAX 100

void bfs(int graph[MAX][MAX],int start,int ver, bool visited[MAX]){
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";

        for(int i=0;i<ver;i++){
            if(graph[current][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
    cout<<endl;
}

int main(){
    int graph[MAX][MAX]={0};
    int ver,edges;
    bool visited[MAX]={false};

    cout<<"enter no of ver: "<<endl;
    cin>>ver;

    cout<<"enter no of edges : "<<endl;
    cin>>edges;

    cout<<"enter each edge(u v): \n";
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int start;
    cout<<"starting ver: ";
    cin>>start;
    cout<<"bfs trav: ";
    bfs(graph,start,ver,visited);

    return 0;
}