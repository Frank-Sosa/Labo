/*Ejercicio17*/
#include <iostream>

using namespace std;

int main()
{
    int numero[10];
    int i=0;
    do{
        cout<<"Ingrese el valor"<<i+1<<":";cin>>numero[i];
        i++;
    }
    while(i<10);
    int a=0 , conta=0;
    do{
        cout<<endl;
        cout<<"El valor"<<a+1<<"es:"<<numero[a];
        conta=conta+numero[a];
        a++;
    }
    while(b<10);
    cout<<endl;
    cout<<"La Suma es: "<<conta<<endl
    cout<<"El Promedio es: "<<conta/10<<endl;

    return 0;
}
