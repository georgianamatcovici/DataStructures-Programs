#include <fstream>
#define MAX 1001
using namespace std;

ifstream cin("BFS.in");
ofstream cout("BFS.out");
struct nod
{int varf;
nod *succ;
};
struct Digraf
{int n;
nod *lista_prim[101], *lista_ultim[101];
};

Digraf digrafVid()
{Digraf D;
D.lista_prim[0]=D.lista_ultim[0]=NULL;
D.n=0;
return D;
}

void insereazaVarf(Digraf &D)
{D.n++;
nod *q;
q=new nod;
q->varf=D.n;
q->succ=NULL;
D.lista_prim[D.n]=D.lista_ultim[D.n]=q;
}

void insereazaArc(Digraf &D, int i, int j)
{
nod *q;
q=new nod;
q->varf=j;
q->succ=NULL;
D.lista_ultim[i]->succ=q;
D.lista_ultim[i]=q;

}


void eliminaVarf(Digraf &D, int k)
{int i;
nod *p;
for(i=1; i<=D.n; i++)
{p=D.lista_prim[i];
if(p!=NULL)
{
while(p->succ!=NULL && p->succ->varf!=k)
    p=p->succ;
if(p->succ!=NULL)
{nod *q=p->succ;
if(p->succ->succ==NULL)
{p->succ=NULL;
D.lista_ultim[i]=p;
}
else p->succ=p->succ->succ;
delete q;
}
}
if(i>=k)
{D.lista_prim[i]=D.lista_prim[i+1];
D.lista_ultim[i]=D.lista_ultim[i+1];
}
}
D.n--;
}

void eliminaArc(Digraf &D, int i, int j)
{nod *p;
int k;
k=1;
//p=D.lista_prim[1];
while(D.lista_prim[k]->varf!=i) k++;
p=D.lista_prim[k];
while(p->succ!=NULL && p->succ->varf!=j)
    p=p->succ;
if(p->succ!=NULL)
{nod *q=p->succ;
if(p->succ->succ==NULL)
{p->succ=NULL;
D.lista_ultim[i]=p;
}
else p->succ=p->succ->succ;
delete q;
}
}


void listaDeAdiacentaExterioara(Digraf D, int i)
{nod *p;
p=D.lista_prim[i];
cout<<p->varf<<": ";
p=p->succ;
while(p!=NULL)
{cout<<p->varf<<' ';
p=p->succ;
}
cout<<endl;
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




void DFS(Digraf D, int i0)
{nod *p[101];
int viz[101], i, j;
for(i=0; i<=D.n; i++)
{viz[i]=0;
if(D.lista_prim[i]!=NULL)
    p[i]=D.lista_prim[i]->succ;
else p[i]=NULL;
}
Stiva SB;
SB=stivaVida();
push(SB, i0);
cout<<i0<<' ';
viz[i0]=1;
while(!esteVida(SB))
{i=top(SB);
if(p[i]==NULL)
    pop(SB);
else{
j=p[i]->varf;
p[i]=p[i]->succ;
if(!viz[j])
{push(SB, j);
viz[j]=1;
cout<<j<<' ';
}
}

}


}

void BFS(Digraf D, int i0)
{nod *p[101];
int viz[101], i, j;
for(i=0; i<=D.n; i++)
{viz[i]=0;
if(D.lista_prim[i]==NULL)
    p[i]=NULL;
else p[i]=D.lista_prim[i]->succ;
}
Coada SB;
SB=coadaVida();
insereaza(SB, i0);
viz[i0]=1;
cout<<i0<<' ';
while(!esteVida(SB))
{i=citeste(SB);
if(p[i]==NULL)
{elimina(SB);
}
else
{j=p[i]->varf;
p[i]=p[i]->succ;
if(!viz[j])
{insereaza(SB, j);
viz[j]=1;
cout<<j<<' ';
}
}
}


}







int main()
{
int n1, m, x1, i, x, y;
Digraf g;
g=digrafVid();
cin>>n1>>m>>x1;
for(i=1; i<=n1; i++)
    insereazaVarf(g);
    //cout<<g.n;
for(i=1; i<=m; i++)
{cin>>x>>y;
insereazaArc(g, x, y);
insereazaArc(g, y, x);
}

BFS(g, x1);
/*for(int i=1; i<=g.n; i++)
{//cout<<i<<":  ";
listaDeAdiacentaExterioara(g, i);
}*/

    return 0;
}
