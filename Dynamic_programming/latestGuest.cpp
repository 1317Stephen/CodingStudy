/*
 * Google Kick Start 2019 Round D #1. X or What?
 * Author: YeEun Ko
 */
#include <iostream>
#include<list>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
//  consulate, (minute, guest)



bool desc(const pair<int,int> &a,const pair<int,int> &b) ;

int main()
{
    int i,j,k;
    int cases=0;
    int consulates, guest, min;
    int startC;
    char direction;

    cin>>cases;
    for(i=1; i<=cases; i++)
    {
        printf("Case #%d: ", i);
        cin>>consulates>>guest>>min;
        vector<vector<pair<int,int> > >visited(consulates+2 );
        int result[100002]={0};
        for(j=1; j<=guest; j++)
        {

            cin>>startC>>direction;
            
            for(k=1; k<=min+1; k++)
            {
                visited[startC].push_back(make_pair(k,j));
                
                if(direction=='C')startC++;
                else if(direction=='A')startC--;
                
                if(startC>consulates)startC=1;
                if(startC<=0)startC=consulates;
            }
            
        }
        
        for(j=1; j<=consulates;j++)
        {
            if(visited[j].size()==0)
            {
                continue;
            }
            sort(visited[j].begin(), visited[j].end(), desc);

            result[visited[j][0].second]++;

            int biggest=visited[j][0].first;
            int index=1;
            while(index<guest)
            {
                if(biggest==visited[j][index].first)
                {
                    result[visited[j][index].second]++;
                }
                else break;
                
                index++;
            }
        }
        for(j=1; j<=guest;j++)
        {
            cout<<result[j]<<" ";
        }
        printf("\n");
    }
    return 0;
}
bool desc(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.first > b.first); 
} 