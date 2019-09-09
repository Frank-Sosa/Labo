// Ejercicio 5C
#include <iostream>
using namespace std;

void torrehanoi(int num, char A, char B, char C)
{
    if(num == 1)
    {
        cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta "<<C<<endl;
    }
    else
    {
        torrehanoi(num-1,A,B,C);
        cout<<"Mueva el bloque "<<num<< " desde "<<A<<" hasta " <<C<<endl;
        torrehanoi(num-1,B,C,A);
    }
}

int main()
{
 int n;
 char A, B, C;
 
 cout<<"Los pilares son: A, B y C\n";
 cout<<"Numero de discos: ";
 cin>>n;
 torrehanoi(n,'A','B','C');
 
 return 0;
 
}

