#include <iostream>

using namespace std;

struct nod
{int elt;
nod *succ;
};

struct LLin
{nod *prim;
nod*ultim;
}L;


LLin listaVida()
{LLin L;
L.prim=L.ultim=NULL;
return L;
}

void insereaza(LLin &L, int k, int e)
{
if(k<0 || (k!=0 && L.prim==NULL))
    {cout<<"eroare-poz incorecta";
   }

nod *q;
q=new nod;
q->elt=e;
if(k==0 || L.prim==NULL)
{
q->succ=L.prim;
L.prim=q;
if(L.ultim==NULL)
    L.ultim=q;
}
else{
int j=0;
nod *p;
p=L.prim;
while(j<k-1&&p!=L.ultim)
{p=p->succ;
j++;
}

if(j<k-1)
{cout<<"eroare-pozitie incorecta";
return;
}

q->succ=p->succ;
p->succ=q;
if(p==L.ultim)
    L.ultim=q;


}
}

void elimina(LLin &L, int k)
{
if(k<0 || L.prim==NULL )
{cout<<"eroare-poz incorecta";
return;
}

if(k==0)
{nod *q;
q=L.prim;
L.prim=L.prim->succ;
delete q;
}
else{
int i=0;
nod *p=L.prim;
while(i<k-1 && p!=L.ultim)
{i++;
p=p->succ;
}

if(p==L.ultim || i<k-1)
{cout<<"eroare-poz incorecta";
return ;
}
nod *q;
q=p;
p->succ=p->succ->succ;
delete q;

}

}

void parcurge (LLin L)
{nod *p;
if(L.prim==NULL)
{cout<<"eroare";
return ;
}
p=L.prim;
while(p!=NULL)
{cout<<p->elt<<' ';
p=p->succ;
}
}

int castigator(LLin L, int n, int p0, int m)
{nod *p, *q;
int cnt, poz;
p=L.prim;
int k;
k=0;
while(k<p0)
{p=p->succ;
k=k+1;
}
//cout<<p->elt<<endl;
cnt=0;
while(cnt<n-1){
poz=1;
while(poz<m-1)
{p=p->succ;
poz++;
}
q=p->succ;
//cout<<p->succ->elt<<' ';
p->succ=p->succ->succ;
delete q;
p=p->succ;
cnt++;
}
return p->elt;
}

int alklea(LLin L, int k)
{nod *p;
int cnt=0;
p=L.prim;
if(k<0 || L.prim==NULL)
{cout<<"eroare";
}
else{
while(cnt<k && p!=L.ultim)
{p=p->succ;
cnt++;
}
if(cnt<k)
{cout<<"eroare";
}
else return p->elt;
}
}

void elimTotE(LLin &L, int e)
{nod *p, *q;
p=L.prim;
while(p->elt==e && p!=L.ultim)
{q=p;
//cout<<p->elt<<' ';
p=p->succ;
L.prim=p;
delete q;
}
if(L.prim==NULL) L.ultim=NULL;
if(p==L.ultim)
{if(p->elt==e)
{q=p;
L.prim=L.ultim=NULL;
delete q;
}
}
else{
while(p->succ!=L.ultim)
{if(p->succ->elt==e)
{q=p->succ;
p->succ=p->succ->succ;
delete q;
}
else p=p->succ;
}

if(p->succ->elt==e)
{q=p->succ;
p->succ=NULL;
L.ultim=p;
delete q;
}
}
}

int poz(LLin L, int e)
{int k=0;
nod *p=L.prim;
while(p!=NULL)
{if(p->elt==e) return k;
k++;
p=p->succ;
}
return -1;

}

int lung(LLin L)
{int cnt=0;
if(L.prim==NULL)
    return 0;
nod *p=L.prim;
cnt=0;
while(p!=NULL)
{p=p->succ;
cnt++;
}
return cnt;
}





int main()
{LLin l;
l=listaVida();
insereaza(l, 0, 4);
insereaza(l, 1, 4);
insereaza(l, 2, 6);
insereaza(l, 3, 4);
//insereaza(l, 4, 3);
//elimTotE(l, 4);
/*cout<<alklea(l, 3)<<' ';
cout<<alklea(l, 4)<<' ';
cout<<alklea(l, 5)<<' ';
*/
//l.ultim->succ=l.prim;
//cout<<castigator(l, 5,  2, 3);
/*elimina(l, 7);
elimina(l, 4);
elimina(l, 0);
elimina(l, 2);*/
//cout<<poz(l, 3);
//cout<<lung(l);

    return 0;
}
