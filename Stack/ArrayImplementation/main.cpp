#include <iostream>
#define MAX 1001

using namespace std;

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

int main()
{Stiva s;
s=stivaVida();
push(s, 0);
push(s, 8);
push(s, 9);
pop(s);
cout<<top(s);

    return 0;
}
