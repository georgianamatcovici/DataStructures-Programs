#include <iostream>
#define MAX 1001

using namespace std;

struct LLin{
int tab[MAX-1];
int ultim;
}L;

LLin listaVida()
{LLin L;
L.ultim=-1;
return L;
}

void insereaza(LLin &L, int k, int x)
{if(k<0 || k>L.ultim+1)
{cout<<"eroare-pozitie incorecta ";
return ;
}/// k este in afara listei
if(L.ultim>=MAX-1) /// lista e deja plina
{cout<<"eroare-spatiu insuficient";
return ;
}
else
{for(int i=L.ultim; i>=k; i--)
L.tab[i+1]=L.tab[i];
L.tab[k]=x;
L.ultim++;
}
/// mut toate elementele de e poz k cu o poz mai incolo

}

void elimina(LLin &L, int k)
{
if(k<0 || k>L.ultim)
{cout<<"eroare-poz incorecta";
return ;
}
else for(int i=k; i<L.ultim; i++)
    L.tab[i]=L.tab[i+1];
L.ultim--;

}

int alklea(LLin L, int k)
{
if(k<0 || k>L.ultim){
cout<<"eroare-poz incorecta";
}
else return L.tab[k];
}

void elimTotE(LLin &L, int val)
{
for(int i=0; i<=L.ultim; i++)
    if(L.tab[i]==val) {elimina(L, i);
    i--;}
}

void parcurge(LLin &L)
{int i;
for(i=0; i<=L.ultim; i++)
cout<<L.tab[i]<<' ';
cout<<endl;
}

int poz(LLin L, int val)
{int i;
for(i=0; i<=L.ultim; i++)
    if(L.tab[i]==val) return i;
return -1;
}

int lung(LLin L)
{return L.ultim+1;
}


int main()
{LLin L;
L=listaVida();
insereaza(L, 0, 1);
insereaza(L, 1, 1);
insereaza(L, 2, 1);
insereaza(L, 3, 1);
insereaza(L, 4, 1);
//elimTotE(L, 1);
parcurge(L);

    return 0;
}
