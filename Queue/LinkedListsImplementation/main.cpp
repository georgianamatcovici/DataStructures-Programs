#include <iostream>

using namespace std;

struct nod
{int elt;
nod *succ;
};

struct Coada
{nod *prim;
nod *ultim;
};

Coada coadaVida()
{Coada C;
C.prim=C.ultim=NULL;
return C;
}

bool esteVida(Coada C)
{if(C.prim==NULL)
return true;
return false;
}

void insereaza(Coada &C, int e)
{nod *q;
q=new nod;
q->elt=e;
q->succ=NULL;
if(C.prim==NULL)
{
C.prim=C.ultim=q;
}
else{
C.ultim->succ=q;
C.ultim=q;
}
}

void elimina(Coada C)
{if(esteVida(C))
{cout<<"eroare";
return ;
}
nod *q=C.prim;
C.prim=C.prim->succ;
delete q;
}

int citeste(Coada C)
{if(esteVida(C))
{cout<<"eroare";
}
else return C.prim->elt;
}


int main()
{Coada c;
c=coadaVida();
insereaza(c, 9);
insereaza(c, 8);
insereaza(c, 3);
insereaza(c, 10);
elimina(c);
elimina(c);
elimina(c);
cout<<citeste(c);
    return 0;
}
