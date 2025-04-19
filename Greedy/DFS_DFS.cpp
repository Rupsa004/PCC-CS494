#include<iostream>
#include<queue>
using namespace std;
#define MAX 100

void BFS(int graph [MAX][MAX],int start,int vertices){
    bool visited[MAX]={false};
    queue<int>q;
    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int current=q.front();
        cout<<current<<" ";
        q.pop();

        for(int i=0;i<vertices;i++){
            if(graph[current][i]==1 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
    cout<<endl;
}

void DFS(int graph[MAX][MAX],int start,int vertices, bool visited[MAX]){
    visited[start]=true;
    cout<<start<<" ";

    for(int i=0;i<vertices;i++){
        if(graph[start][i]==1 && !visited[i]){
            DFS(graph,i,vertices,visited);
        }
    }
}

int main(){
    int graph[MAX][MAX]={0};
    int vertices,edges;
    bool visited[MAX] = {false};
    cout<<"enter no of vertices: ";
    cin>>vertices;
    cout<<"enter no of edges: ";
    cin>>edges;

    cout<<"enter edges in form of (u,v): "<<endl;
    for(int i=0;i<edges;i++){
        int u, v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int start;
    cout<<"enter starting vertex:";
    cin>>start;
    cout<<"BFS traversal: ";
    BFS(graph,start,vertices);
    
    for(int i = 0; i < MAX; i++) visited[i] = false;
    cout<<"DFS traversal: ";
    DFS(graph,start,vertices,visited);
    cout<<endl;

    return 0;

}