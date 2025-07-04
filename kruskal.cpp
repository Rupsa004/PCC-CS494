#include<iostream>
using namespace std;

struct Edge{
    int v1,v2,w;
};

int no_ver=6;
int no_edg=8;

Edge edges[]={ {0,1,4}, {0,2,3}, {1,2,1}, {1,3,2}, {1,4,3}, {2,3,4}, {3,4,2}, {3,5,6} };

int parent[6];
Edge tree[5]; //MST, v-1 edges

int find(int x){
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
    }

void merge(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px!=py){
        parent[px]=py;
    }
}

void sort(){
    for(int i=0;i<no_edg;i++){
        int sort=1;
        for(int j=0;j<no_edg-i-1;j++){
            if(edges[j].w>edges[j+1].w){
                Edge temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
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
    for(int i=0;i<no_edg;i++){
        int x=edges[i].v1;
        int y=edges[i].v2;
        int w=edges[i].w;
        if(find(x)!=find(y)){
            merge(x,y);
            tree[count].v1=x;
            tree[count].v2=y;
            tree[count].w=w;
            cost+=w;
            count++;
        }
        if (count==no_ver-1){
            break;
        }
    }

cout<<"min edges: "<<endl;
for(int i=0;i<count;i++){
    cout<<tree[i].v1<<"--"<<tree[i].v2<<"--"<<tree[i].w<<endl;
}
    cout<<"total cost: "<<cost<<endl;
}



int main(){
    kruskal();
    return 0;
}