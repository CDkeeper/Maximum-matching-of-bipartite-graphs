#include<iostream>
#include<cstring>
using namespace std;
int n1,n2,m;
int u,v;
const int N=505,M=1e5+5;
int h[N],e[M],ne[M],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int match[N];
bool st[N];
bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(match[j]==0||find(match[j])){
            match[j]=x;
            return true;
            }   
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n1,&n2,&m);
    memset(h,-1,sizeof h);
    while(m--){
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    int ans=0;
    for(int i=1;i<=n1;i++){
        memset(st,0,sizeof st);
        if(find(i)) ans++;
    }
    printf("%d",ans);
    return 0;
}
