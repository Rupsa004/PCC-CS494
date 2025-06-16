#include<iostream>
using namespace std;

struct Edges{
    int v1,v2,w;
};

int no_ver =6;
int no_edges=8;

Edges edge[]={ {0,1,4}, {0,2,3}, {1,2,1}, {1,3,2}, {1,4,3}, {2,3,4}, {3,4,2}, {3,5,6} };

int parent[6];
Edges tree[5];

int find(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        return parent[x]=find(parent[x]);
    }
}

void merge(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px!=py){
        parent[px]=py;
    }

}

void sort(){
    for(int i=0;i<no_edges;i++){
        int sort=1;
        for(int j=0;j<no_edges-i-1;j++){
            if(edge[j].w>edge[j+1].w){
                Edges temp=edge[j];
                edge[j]=edge[j+1];
                edge[j+1]=temp;
                sort=0;
            }
        }
        if(sort)
        break;
    }
}

void kruskal(){
    for(int i=0;i<no_ver;i++)
        parent[i]=i;
    sort();
    int count=0;
    int cost=0;
    for(int i=0;i<no_edges;i++){
        int x=edge[i].v1;
        int y=edge[i].v2;
        int w=edge[i].w;
        if(find(x)!=find(y)){
            merge(x,y);
            tree[count].v1=x;
            tree[count].v2=y;
            tree[count].w=w;
            cost+=w;
            count++;
        }
        if(count==no_ver-1)
            break;
        }

    cout<<"min edge: ";
    for(int i=0;i<count;i++){
        cout<<tree[i].v1<<"--"<<tree[i].v2<<"--"<<tree[i].w<<endl;
        cout<<"total cost: "<<cost<<endl;
    }
}
int main(){
    kruskal();
    return 0;
}