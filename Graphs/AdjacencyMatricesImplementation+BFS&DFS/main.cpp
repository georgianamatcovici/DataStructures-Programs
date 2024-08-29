#include <iostream>
#define MAX 1001
#include <stack>

using namespace std;


//int n, m, a[101][101];

struct Stiva
{int tab[MAX];
int varf;
};

Stiva stivaVida()
{Stiva S;
S.varf=-1;
return S;

}

bool esteVida(Stiva S)
{
if(S.varf==-1)
    return true;
return false;
}

void push (Stiva &S, int e)
{
if(S.varf==MAX-1)
{cout<<"eroare-spatiu insuficient";
return ;
}
else{
S.varf++;
S.tab[S.varf]=e;
}
}

void pop(Stiva &S)
{if(esteVida(S))
{cout<<"eroare";
return;
}
else{
S.varf--;
}
}

int top(Stiva &S)
{if(esteVida(S))
{cout<<"eroare";
}
else return S.tab[S.varf];
}



struct Coada
{int tab[MAX-1];
int prim, ultim;
};

Coada coadaVida()
{Coada C;
C.prim=C.ultim=-1;
return C;
}

bool esteVida(Coada C)
{if(C.prim>C.ultim)
return true;
return false;
}

void insereaza(Coada &C, int e)
{if((C.ultim+1)%MAX==C.prim)
{cout<<"eroare";
return ;
}
if(C.prim==-1)
{C.prim=C.ultim=0;
C.tab[C.ultim]=e;
}
else
{C.ultim=(C.ultim+1)%MAX;
C.tab[C.ultim]=e;
}
}

void elimina(Coada &C)
{if(esteVida(C))
{cout<<"eroare";
return;
}
C.prim=(C.prim+1)%MAX;

}

int citeste(Coada &C)
{if(esteVida(C))
{cout<<"eroare";

}
return C.tab[C.prim];
}






struct Digraf
{int n, m, a[101][101];
};

Digraf digrafVid()
{Digraf D;
D.m=D.n=0;
return D;
}
bool esteDigrafVid(Digraf D)
{if(D.n==0 && D.m==0) return true;
return false;
}
void insereazaVarf(Digraf &D)
{D.n++;
for(int i=0; i<=D.n; i++)
    D.a[i][D.n]=D.a[D.n][i]=0;
}

void insereazaArc(Digraf &D, int i, int j)
{D.a[i][j]=1;
D.m++;
}

void eliminaArc(Digraf &D, int i, int j)
{D.a[i][j]=0;
D.m--;
}

void eliminaVarf(Digraf &D, int k)
{int i, j;
for(i=0; i<=D.n; i++)
    for(j=0; j<=D.n; j++)
{if(i>k) D.a[i-1][j]=D.a[i][j];
if(j>k) D.a[i][j-1]=D.a[i][j];

}
D.n--;
}

void listaDeAdiacentaExterioara(Digraf D, int i)
{int j;
for(j=0; j<=D.n; j++)
    if(D.a[i][j]) cout<<j<<' ';
cout<<endl;
}

void listaDeAdiacentaInterioara(Digraf D, int i)
{int j;
for(j=0; j<=D.n; j++)
    if(D.a[j][i]) cout<<j<<' ';
cout<<endl;
}

void listaVarfurilorAccesibile(Digraf D, int p)
{int i, j, k, b[101][101];

for(i=0; i<D.n; i++)
for(j=0; j<D.n; j++)
    if(i==j) b[i][j]=1;
else b[i][j]=D.a[i][j];

for(k=0; k<D.n; k++)
{for(i=0; i<D.n; i++)
if(b[i][k]==1)
{for(j=0; j<D.n; j++)
if(b[k][j]==1) b[i][j]=1;
}
}
for(i=0; i<D.n; i++)
    if(b[p][i]) cout<<i<<' ';
cout<<endl;
}

void DFS(Digraf D, int i0)
{Stiva SB;
    //stack<int> SB;
int i, j, gasit, viz[101];

for(j=0; j<=D.n; j++)
    viz[j]=0;
SB=stivaVida();
push(SB, i0);
//SB.push(i0);
//cout<<i0<<' ';
while(!esteVida(SB))
{
i=top(SB);
if(viz[i]==0){cout<<i<<' ';
viz[i]=1;}
pop(SB);
for(j=D.n; j>=0; j--)
{if(D.a[i][j]&& viz[j]==0)
{push(SB,j);
//cout<<j<<' ';
}
}


}
}

void BFS(Digraf D, int i0)
{int viz[101], i, j;
Coada SB;
for(i=0; i<=D.n; i++)
{viz[i]=0;
}
SB=coadaVida();
cout<<i0<<' ';
insereaza(SB, i0);
viz[i0]=1;
while(!esteVida(SB))
{i=citeste(SB);
for(j=0; j<=D.n; j++)
{if(D.a[i][j]==1 && viz[j]==0){
cout<<j<<' '; insereaza(SB, j); viz[j]=1;
}
}
elimina(SB);
}

}


int main()
{
Digraf g;
g=digrafVid();
/*insereazaVarf(g);
insereazaVarf(g);
insereazaVarf(g);
insereazaVarf(g);
insereazaVarf(g);
insereazaVarf(g);
insereazaVarf(g);
insereazaVarf(g);
insereazaArc(g, 0, 1);
insereazaArc(g, 0, 7);
insereazaArc(g, 0, 3);
insereazaArc(g, 1, 3);
insereazaArc(g, 2, 5);
insereazaArc(g, 3, 5);
insereazaArc(g, 4, 6);
insereazaArc(g, 5, 8);
insereazaArc(g, 7, 2);
insereazaArc(g, 7, 1);
insereazaArc(g, 8, 2);
insereazaArc(g, 8, 6);
//listaVarfurilorAccesibile(g, 3);
*/
int n1, m, x1, i, x, y;
cin>>n1>>m>>x1;
for(i=1; i<=n1; i++)
    insereazaVarf(g);
    //cout<<g.n;
for(i=1; i<=m; i++)
{cin>>x>>y;
insereazaArc(g, x, y);
insereazaArc(g, y, x);
}

DFS(g, x1);

/*for(int i=0; i<=g.n; i++)
{cout<<i<<": ";
listaDeAdiacentaExterioara(g, i);
}*/

    return 0;
}
