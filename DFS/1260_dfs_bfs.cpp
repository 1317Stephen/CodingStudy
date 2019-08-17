#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=10001;
bool visited[MAX]={0};
vector<int>adj[MAX];
queue<int>Q;
void dfs(int startNode);
void bfs(int startNode);
int main()
{
    int i;
    int nNode, nEdge, startNode;
    cin>>nNode >>nEdge>> startNode;
    for(i=0; i<nEdge; i++)
    {
        int start, end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    for(i=0; i<nNode; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(startNode);
    memset(visited, 0, sizeof(visited));
    cout<<"\n";
    bfs(startNode);
    return 0;
}
void dfs(int startNode)
{
    visited[startNode]=true;
    cout<<startNode<<" ";
    for(auto neighbor: adj[startNode])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}
void bfs(int startNode)
{
    Q.push(startNode);
    visited[startNode]=true;
    while(!Q.empty())
    {
        int q=Q.front();
        Q.pop();
        cout<<q<<" ";
        for(auto neighbor: adj[q])
        {
            if(!visited[neighbor])
            {
                Q.push(neighbor);
                visited[neighbor]=true;
            }
        }

    }
}