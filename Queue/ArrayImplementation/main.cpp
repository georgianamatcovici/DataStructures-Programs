#include <iostream>
#define MAX 1001

using namespace std;

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
{if(C.prim==-1)
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




int main()
{Coada C;
C=coadaVida();
insereaza(C, 8);
insereaza(C, 7);
insereaza(C, 4);
insereaza(C, 9);
elimina(C);
elimina(C);
insereaza(C, 7);
cout<<citeste(C);

    return 0;
}
