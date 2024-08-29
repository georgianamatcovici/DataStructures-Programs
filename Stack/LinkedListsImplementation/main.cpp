#include <iostream>

using namespace std;

struct nod
{int elt;
nod *succ;
};

struct Stiva
{nod *varf;
};

Stiva stivaVida()
{Stiva S;
S.varf=NULL;
return S;
}

bool esteVida(Stiva S)
{if(S.varf==NULL)
return true;
return false;
}

void push(Stiva &S, int e)
{nod *q;
q=new nod;
q->elt=e;
q->succ=S.varf;
S.varf=q;
}

void pop(Stiva &S)
{if(esteVida(S))
{cout<<"eroare";
return;
}
nod *q;
q=S.varf;
S.varf=S.varf->succ;
delete q;
}

int top(Stiva &S)
{if(esteVida(S))
{cout<<"eroare";

}
return S.varf->elt;
}

int main()
{Stiva s;
s=stivaVida();
push(s, 8);
push(s, 0);
push(s, 5);
push(s, 9);
pop(s);
pop(s);
cout<<top(s);


    return 0;
}
