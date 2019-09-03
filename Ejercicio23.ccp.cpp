/*Ejercicio23*/
#include <iostream>
using namespace std;
struct Complejo {
   int real, imaginario;
};
   
int main() {
   Complejo n1, n2, sum;
   
   cout << "Ingrese valor de A y B  donde A + iB es el primer numero complejo\n";
   cin >> n1.real >> n1.imaginario;
     
   cout << "Ingrese valor de  A y B  donde A + iB es el segundo numero complejo\n";
   cin >> n2.real >> n2.imaginario;
     

   sum.real = n1.real + n2.real;
   sum.imaginario = n1.imaginario + n2.imaginario;
      
   if(sum.imaginario >= 0 )
      cout << sum.real << " + " << sum.imaginario<<"i";
   else
      cout << sum.real << " - " << sum.imaginario<<"i";
     
   return 0;
}