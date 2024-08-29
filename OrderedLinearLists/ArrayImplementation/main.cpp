#include <iostream>
#define MAX 1001


using namespace std;


struct LLinOrd{
int tab[MAX-1];
int ultim;
}L;


LLinOrd listaVida()
{LLinOrd L;
L.ultim=-1;
return L;
}

void insereaza(LLinOrd &L, int e)
{if(L.ultim>=MAX-1) /// lista e deja plina
{cout<<"eroare-spatiu insuficient";
return ;
}
//L.ultim++;
int i=L.ultim;
while(i>=0 && e<L.tab[i])
{L.tab[i+1]=L.tab[i];
i--;
}
L.tab[i+1]=e;
L.ultim++;
}

void elimina(LLinOrd &L, int e)
{int i, j, k;
j=-1;
for(i=1; i<=L.ultim && j==-1; i++)
    if(L.tab[i]==e) j=i;
if(j==-1)
{cout<<"eroare";
return ;
}
for(k=j; k<L.ultim; k++)
    L.tab[k]=L.tab[k+1];
L.ultim--;
}

void parcurge(LLinOrd L)
{int i;
for(i=0; i<=L.ultim; i++)
    cout<<L.tab[i]<<' ';
cout<<endl;
}

int alklea(LLinOrd L, int k)
{
if(k<0 || k>L.ultim){
cout<<"eroare-poz incorecta";
}
else return L.tab[k];
}

int poz(LLinOrd L, int e)
{int st, dr, mij;
st=0; dr=L.ultim;
while(st<=dr)
{mij=(st+dr)/2;
if(L.tab[mij]==e) return mij;
else if(e<L.tab[mij]) dr=mij-1;
else st=mij+1;
}
return -1;
}

void elimTotE(LLinOrd &L, int val)
{
for(int i=0; i<=L.ultim; i++)
    if(L.tab[i]==val) {elimina(L, i);
    i--;}
}

int lung(LLinOrd L)
{return L.ultim+1;
}

int main()
{
LLinOrd l;
l=listaVida();
insereaza(l, 2);
insereaza(l, 1);
insereaza(l, 9);
insereaza(l, 10);
insereaza(l, 5);
insereaza(l, 7);
insereaza(l, 15);
parcurge(l);
//elimina(l, 15);
//parcurge(l);
cout<<poz(l, 10);

    return 0;
}
