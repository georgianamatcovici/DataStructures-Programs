#include <iostream>

using namespace std;

struct nod
{int elt;
nod *succ;
};

struct LLinOrd
{nod *prim;
nod*ultim;
}L;

LLinOrd listaVida()
{LLinOrd L;
L.prim=L.ultim=NULL;
return L;
}

void insereaza(LLinOrd &L, int e)
{nod *q;
q=new nod;
q->elt=e;
q->succ=NULL;
if(L.prim==NULL)
{L.prim=L.ultim=q;
}
else{
if(e<L.prim->elt)
{q->succ=L.prim;
L.prim=q;
}
else{
nod *p;
p=L.prim;
while(p!=L.ultim && e>p->succ->elt)
{p=p->succ;
}
if(p==L.ultim)
{L.ultim->succ=q;
L.ultim=q;
}
else
{q->succ=p->succ;
p->succ=q;
}
}
}
}
void elimina(LLinOrd &L, int e)
{nod *q, *p;
while(L.prim->elt==e)
{q=L.prim;
L.prim=L.prim->succ;
delete q;
}
p=L.prim;
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
L.ultim=p;
p->succ=NULL;
delete q;
}

}

void parcurge(LLinOrd L)
{nod *p;
p=L.prim;
while(p!=NULL)
{cout<<p->elt<<' ';
p=p->succ;
}
cout<<endl;
}

int alklea(LLinOrd L, int k)
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

int poz(LLinOrd L, int e)
{int k=0;
nod *p=L.prim;
while(p!=NULL)
{if(p->elt==e) return k;
k++;
p=p->succ;
}
return -1;

}

int lung(LLinOrd L)
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
{LLinOrd l;
l=listaVida();
insereaza(l, 1);
insereaza(l, 1);
insereaza(l, 4);
insereaza(l, 5);
insereaza(l, 10);
insereaza(l, 10);
elimina(l, 10);
parcurge(l);


    return 0;
}
