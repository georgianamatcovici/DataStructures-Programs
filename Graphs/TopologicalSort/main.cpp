#include <iostream>
#include <vector>

using namespace std;


int n, m, x, y, viz[100001], sol[100001], cnt;
 vector <int> lista[100001];

 void dfs(int k)
 {viz[k]=1;
 //cout<<k<<' ';
 for(int i=0; i<lista[k].size(); i++)
 {
    if(viz[lista[k][i]]==0) dfs(lista[k][i]);
 }
 cnt++; sol[cnt]=k;
 }

int main()
{int i, j;
cin>>n>>m;
for(i=1; i<=m; i++)
{cin>>x>>y;
lista[x].push_back(y);
}

for(i=1; i<=n; i++)
{if(viz[i]==0) dfs(i);
}

for(i=cnt; i>=1; i--)
    cout<<sol[i]<<' ';



    return 0;
}
