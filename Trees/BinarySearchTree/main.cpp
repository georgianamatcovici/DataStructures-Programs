#include <iostream>

using namespace std;

struct nod
{int val;
nod *stg, *drp, *pred;
};
int n, v[101];


void insArbBinCautare(nod *&t, int x)
{if(t==NULL)
{t=new nod;
t->val=x;
t->stg=NULL;
t->drp=NULL;
t->pred=NULL;
}
else{
nod *p=t;
nod *predp;
while(p!=NULL) ///daca il gasesc pe x, nu il mai inserez
{predp=p;
if(x<p->val) p=p->stg;
else if(x>p->val) p=p->drp;
else p=NULL;
}
if(predp->val !=x)
{nod *q=new nod;
q->val=x;
q->pred=predp;
q->stg=NULL;
q->drp=NULL;
if(x<predp->val)
predp->stg=q;
else predp->drp=q;

}
}
}

nod* poz(nod *t, int x)
{nod *p=t;
while(p!=NULL && p->val !=x)
{if(x<p->val) p=p->stg;
else p=p->drp;
}
return p;
}

nod *Predecesor(nod *t)
{if(t==NULL)
return NULL;
if(t->stg!=NULL)
{nod *p=t->stg;
while(p->drp!=NULL)
{
p=p->drp;
}
return p;
}
else
{nod *p=t->pred;
while(p!=NULL && p->stg==t)
{t=p;
p=p->pred;
}
return p;
}

}

nod *Succesor(nod *t)
{if(t==NULL)
return NULL;
if(t->drp!=NULL)
{nod *p;
p=t->drp;
while(p->stg!=NULL)
    p=p->stg;
return p;
}
else{
    nod *p;
p=t->pred;
while(p!=NULL && p->drp==t)
{t=p;
p=p->pred;
}
return p;
}
}

void elimCaz1sau2(nod *&t, nod*&predp, nod *&p)
{
if(p==t)
{if(t->stg!=NULL)
{nod *q=t;
t=t->stg;
p=t;
delete q;
}
else if(t->drp!=NULL)
{nod *q=t;
t=t->drp;
p=t;
delete q;
}
else{
t=NULL;
p=NULL;
}
}
else{
if(p->stg!=NULL)
{p->stg->pred=predp;
nod *q=p;
p->pred=NULL;
predp->stg=p->stg;
delete q;
}
else if(p->drp!=NULL){
p->drp->pred=predp;
nod *q=p;
p->pred=NULL;
predp->drp=p->drp;
delete q;

}
else{
nod *q=p;
p->pred=NULL;
if(predp->stg==p)
predp->stg=NULL;
else predp->drp=NULL;
delete q;

}
}
}

void elimArbBinCautare(nod *&t, int x)
{nod *p, *predp, *q, *predq;
if(t!=NULL)
{
p=t;
predp=NULL; ///e important predp<-NULL!!!
while(p!=NULL && p->val!=x)
{predp=p;
if(x<p->val) p=p->stg;
else p=p->drp;
}
if(p!=NULL)
{if(p->stg==NULL || p->drp==NULL)
{elimCaz1sau2(t, predp, p);
}
else{
predq=p;
q=p->stg;
while(q->drp!=NULL)
{predq=q;
q=q->drp;
}
p->val=q->val;
elimCaz1sau2(t, predq, q);

}
}

}
}


int valmin(nod *t)
{
while(t->stg!=NULL)
    t=t->stg;
return t->val;
}

void interval(nod *t, int a, int b)
{if(t==NULL) return;
if(t->val>=a && t->val<=b) cout<<t->val<<' ';
interval(t->stg, a, b);
interval(t->drp, a, b);
}

void inordine(nod *t)
{if(t==NULL)
return ;
inordine(t->stg);
cout<<t->val<<' ';
inordine(t->drp);
}

int EsteArboreBST(nod *t)
{if(t==NULL) return 0;
if(t->stg!=NULL)
    {if(t->stg->val>=t->val) return 0;
    EsteArboreBST(t->stg);
    }
if(t->drp!=NULL)
    {if(t->drp->val<=t->val) return 0;
    EsteArboreBST(t->drp);
    }
return 1;
}
int s=0;
void Adunare(nod *&t)
{if(t!=NULL)
{Adunare(t->drp);
t->val+=s;
s+=t->val;
}
}

int main()
{int i;
nod *t=NULL;
cin>>n;
for(i=1; i<=n; i++)
{cin>>v[i];
insArbBinCautare(t, v[i]);
//cout<<v[i]<<endl;
}
//cout<<EsteArboreBST(t);
//inordine(t);
//cout<<endl;
//nod *r=poz(t, 8);
//nod *p=Predecesor(r);
//nod *s=Succesor(r);
//cout<<p->val<<' '<<s->val;
//elimArbBinCautare(t, 8);
Adunare(t);
inordine(t);
    return 0;
}
