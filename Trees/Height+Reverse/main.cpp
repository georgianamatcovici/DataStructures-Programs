#include <iostream>
#include <algorithm>

using namespace std;

struct nod
{int info;
nod *st, *dr;
};
int y;
void creare(nod *&r, int val)
{if(val!=0)
{r=new nod;
r->info=val;
r->st=r->dr=NULL;
cin>>y;
creare(r->st, y);
cin>>y;
creare(r->dr, y);
}
}

void rsd(nod *rad)
{
if(rad!=NULL)
{
cout<<rad->info<<' ';
rsd(rad->st);
rsd(rad->dr);
}
}

int inaltime(nod *rad)
{if(rad==NULL)
return 0;
else return 1+max(inaltime(rad->st), inaltime(rad->dr));
}

int minim;
void adanc_min(nod *rad, int niv)
{
if(rad->st==NULL && rad->dr==NULL && niv<minim) minim=niv;
if(rad->st!=NULL) adanc_min(rad->st, niv+1);
if(rad->dr!=NULL) adanc_min(rad->dr, niv+1);
}

void oglindire(nod *&rad)
{
if(rad->st!=NULL && rad->dr !=NULL)
{oglindire(rad->st);
oglindire(rad->dr);
swap(rad->st->info, rad->dr->info);
}
else if(rad->st==NULL && rad->dr!=NULL) oglindire(rad->dr);
else if(rad->st!=NULL && rad->dr==NULL) oglindire(rad->st);
}

int main()
{int x;
cin>>x;
nod *rad;
creare(rad, x);
//cout<<rad->st->info;
//rsd(rad);
//cout<<endl;
//minim=1000000;
//adanc_min(rad, 1);
//cout<<minim;
oglindire(rad);
rsd(rad);

    return 0;
}
