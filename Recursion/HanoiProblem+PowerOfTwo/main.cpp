#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("hanoi.in");
ofstream fout("hanoi.out");

int putere (int n)
{if(n==0) return 1;
else{
if(n%2==0) return putere(n/2)*putere(n/2);
else return putere(n/2)*putere(n/2)*2;
}

}
void h(int n, char a, char b, char c)
{if(n==1) {fout<<a<<"->"<<c<<endl;}
else
{h(n-1, a, c, b);
fout<<a<<"->"<<c<<endl;
h(n-1, b, a, c);
}
}

int main()
{int n;
fin>>n;
fout<<putere(n)-1<<endl;
h(n, 'A', 'B', 'C');



    return 0;
}
