#include <bits/stdc++.h>                                                        
using namespace std;                                                            
const int N = 1e3+5;                                                            
bitset<N> smoki[N];                                                             
bitset<N> odw[N];
bitset<N> zaz[N];
int n, m, tury[N][N];                                                           
vector<pair<int, int>> kordy[N][N];                                             
bool is_valid(pair<int, int> x) {                                               
  return 0 < x.first && x.first <= n && 0 < x.second && x.second <= m && !smoki[x.first][x.second]&&!odw[x.first][x.second];                                    
}                                                                               
int main(){                                                                     
    int sx1, sx2, sy1, sy2;                                                     
    cin>>n>>m;                                                                  
    cin>>sx2>>sx1>>sy2>>sy1;                                                    
    for(int i=1;i<=n;i++)                                                       
    {                                                                           
         for(int j=1;j<=m;j++)                                                  
         {                                                                      
             char pom;                                                          
             cin>>pom;                                                          
             if(pom=='S') smoki[i][j] = true;                                   
             else smoki[i][j] = false;                                          
         }                                                                      
     }                                                                          
    int t;                                                                      
    cin>>t;                                                                     
    while(t--)                                                                  
    {                                                                           
        int x1, x2, y1, y2;                                                     
        cin>>x2>>x1>>y2>>y1;
        zaz[x1][x2] = true;
        kordy[x1][x2].push_back(make_pair(y1, y2));                             
    }                                                                           
    bool stoping = false;                                                       
    queue<pair<int,int>> order;                                                 
    order.push(make_pair(sx1, sx2));                                            
    while(!order.empty()&&!stoping)                                             
    {                                                 
        auto x = order.front();                                                 
        order.pop();
        for (auto v : kordy[x.first][x.second])                                 
        {                                                                       
            if(is_valid(v))                                                     
            {                                                                   
            tury[v.first][v.second] = tury[x.first][x.second] + 1;              
            order.push(v);                                                      
            odw[v.first][v.second] = true;                                      
            }                                                                   
        }                                                                       
    if(!zaz[x.first][x.second]) for (auto v : {make_pair(x.first, x.second - 1), make_pair(x.first-1,x.second),make_pair(x.first,x.second+1),make_pair(x.first+1,x.second)})            
        {                                                                       
            if(is_valid(v))                                                     
            {                                                                   
            tury[v.first][v.second] = tury[x.first][x.second] + 1;              
            order.push(v);                                                      
            odw[v.first][v.second] = true;                                      
            }                                                                   
        }                                                                       
    }                                                                           
    if(odw[sy1][sy2]==false)                                                    
    {                                                                           
        cout<<-1;                                                               
        return 0;                                                               
    }                                                                           
    cout<<tury[sy1][sy2];                                                       
    return 0;                                                                   
}
