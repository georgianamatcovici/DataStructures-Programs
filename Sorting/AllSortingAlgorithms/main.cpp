#include <iostream>
#include <algorithm>

using namespace std;

int a[1001], n;

void BubbleSort()
{int ultim, i, n1;
ultim=n-1;
while(ultim>0)
{n1=ultim-1;
ultim=0;
for(i=0; i<=n1; i++)
if(a[i]>a[i+1]){swap(a[i], a[i+1]); ultim=i;}
}
}

void insertSort()
{int i, temp, j;
for(i=1; i<=n-1; i++)
{temp=a[i];
j=i-1;
while(j>=0 && temp<a[j])
{a[j+1]=a[j];
j--;
}
if(a[j+1]!=temp)
    a[j+1]=temp;
}
}

void naivSort()
{int i, j, imax;
for(i=n-1; i>=0; i--)
{imax=i;
for(j=i-1; j>=0; j--)
    if(a[j]>a[imax]) imax=j;
if(i!=imax) swap(a[imax], a[i]);
}
}

void insereazaAlTlea(int n, int t)
{int j, heap, k;
j=t;
heap=0;
while(2*j+1<n && !heap)
{k=2*j+1;
if(k+1<n && a[k+1]>a[k]) k++;
if(a[j]<a[k]){swap(a[j], a[k]);j=k;}
else heap=1;
}
}

void HeapSort()
{int i, r;
for(i=(n-1)/2; i>=0; i--)
    insereazaAlTlea(n, i);
r=n-1;
while(r>0)
{swap(a[0], a[r]);
insereazaAlTlea(r, 0);
r--;
}
}
void interclasare(int st, int mij, int dr)
{int i, j, k;
int c[101];
i=st;
j=mij+1;
k=0;
while(i<=mij && j<=dr)
{if(a[i]<=a[j])
{
c[++k]=a[i]; i++;
}
else {c[++k]=a[j]; j++;}
}
while(i<=mij)
{c[++k]=a[i];
i++;
}

while(j<=dr)
{c[++k]=a[j];
j++;
}
k=1;
for(int l=st; l<=dr; l++)
    a[l]=c[k++];
}

void MergeSort(int st, int dr)
{if(st==dr)
return;
else{
int mij=(st+dr)/2;
MergeSort(st, mij);
MergeSort(mij+1, dr);
interclasare(st, mij, dr);
}
}

int partitioneaza(int p, int q)
{int k, i, j, x;
x=a[p];
i=p+1;
j=q;
while(i<=j)
{if(a[i]<=x) i++;
if(a[j]>=x) j--;
if(i<j && a[i]>x && a[j]<x)
{swap(a[i], a[j]);
i++;
j--;
}
}
k=i-1;
swap(a[k], a[p]);
return k;

}

void QuickSort(int p, int q)
{if(p<q)
{int k=partitioneaza(p, q);
QuickSort(p, k-1);
QuickSort(k+1, q);
}
}

int main()
{int i;
cin>>n;
for(i=0; i<n; i++)
    cin>>a[i];
QuickSort(0, n-1);
for(i=0; i<n; i++)
    cout<<a[i]<<' ';
    return 0;
}
