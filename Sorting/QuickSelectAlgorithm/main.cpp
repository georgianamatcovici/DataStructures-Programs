#include <iostream>
#include <algorithm>

using namespace std;

int a[101], n, k;

int pivot(int p, int q)
{int i, j, k;
i=p+1;
j=q;
while(i<=j)
{if(a[i]<=a[p])
i++;
if(a[j]>=a[p])
    j--;
if(i<j && a[i]>a[p] && a[j]<a[p])
{
swap(a[i], a[j]);
i++;
j--;
}
}
k=i-1;
swap(a[p], a[k]);
return k;
}

int QuickSelect(int p, int q, int poz)
{
if(p<q)
{int k=pivot(p, q);
if(poz==k-p+1) return a[k];
else if(poz<k-p+1) QuickSelect(p, k-1, poz);
else QuickSelect(k+1, q, poz-(k-p+1));
}
}

int main()
{int i;
cin>>n>>k;
for(i=0; i<n; i++)
    cin>>a[i];
cout<<QuickSelect(0, n, k);

    return 0;
}
