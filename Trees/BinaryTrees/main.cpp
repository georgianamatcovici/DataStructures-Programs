#include <iostream>

using namespace std;

struct Node
{int value;
Node *Left;
Node *Right;
};

int cnt=0;
void creeaza_arbore(Node *&r, int n)
{//cout<<i<<' ';
cnt++;
if(cnt<=n)
{r=new Node;
r->value=cnt;
r->Left=NULL;
r->Right=NULL;
creeaza_arbore(r->Left, n);
creeaza_arbore(r->Right, n);
}
}

Node *arbore(int n)
{int i;
Node *rad=NULL;
i=1;
creeaza_arbore(rad, n);
return rad;

}

void RSD(Node *r)
{if(r!=NULL)
{cout<<r->value<<' ';
RSD(r->Left);
RSD(r->Right);
}

}



int main()
{Node *p;
int n;
cin>>n;
p=arbore(n);
//cout<<p->value;
RSD(p);

    return 0;
}
