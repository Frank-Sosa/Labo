// Francisco Sosa
// 00357518
//Labo 4, eje4
#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

class ListaSimple{
	private:
		nodo *pInicio;
		
	public:
		
		ListaSimple(void);
		void insertarInicioLista(int);
		void mostrarLista(int,int);
};

ListaSimple::ListaSimple(void){
	cout<<"Inicializando el objeto"<<endl;
	pInicio = NULL;
}
void ListaSimple::insertarInicioLista(int dato){
	nodo *nuevo;
			
	nuevo = new nodo;
	nuevo->dato = dato;
	nuevo->sig = pInicio;
	pInicio = nuevo;
}
	

void ListaSimple::mostrarLista(int p, int i){
	nodo *s = pInicio;

	while(s!=NULL){
		if(s->dato%2==0){
			p+=s->dato;
		}else{
			i+=s->dato;
		}
		s=s->sig;
	}
	cout<<"\nLa suma total de los numeros pares de la lista es: "<<p<<endl;
	cout<<"La suma total de los numeros impares de la lista es: "<<i<<endl;
}

int main (void){
	
	ListaSimple miLista;
	char resp;
	int dato;
	int datoBuscar;
	int sumapar=0;
	int sumaimpar=0;
	
	cout<<"Desea digitar un dato (s/n)? ";
	cin>>resp;
	while(resp=='s'){
		cout<<"Digite el dato: ";
		cin>>dato;
		miLista.insertarInicioLista(dato);
		cout<<"Desea introducir un dato (s/n)? ";
		cin>>resp;
	}
	
	miLista.mostrarLista(sumapar,sumaimpar);
	
	return 0;	
}
