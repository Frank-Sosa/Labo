// Ejercicio 2
#include <iostream>
#include <cmath>
using namespace std;

long double RaizEntero(int num, long double r);

int main(void){
 int entero=0, semilla=0;
 IngresarEntero:
 cout<<"Ingrese el valor del cual desea obtener la raiz cuadrada: ";
 cin>>entero;
 if(entero<0){
     goto IngresarEntero;
 }
 IngresarSemilla:
 cout<<"Ingrese el valor de la semilla: ";
 cin>>semilla;
 if(semilla<0){
     goto IngresarSemilla;
 }
 cout<<RaizEntero(entero, semilla);
 return 0;
 
}

long double RaizEntero(int num, long double r){
    long double r2 = (((num/r)+r)/2);
    if(abs(r-r2)<0.0001){
        return r2;
    }else{
        return RaizEntero(num, r2);
    }
}