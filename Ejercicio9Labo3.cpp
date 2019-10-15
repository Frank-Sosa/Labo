//Francisco Sosa
//00357518 
#include <iostream>
#include <string>

using namespace std;

struct nombre{
	string Nombre, Apellido, Carnet, Telefono, Correo;
	int edad;

	nombre* sgt;
};

void InsetDat(nombre** pInicio);
void Impmenu(void);
void ImpDat(nombre* lista, int cuenta);
void DeleteName(nombre** lista, string busq, int cuenta);

void actualizarDatos(nombre** lista, string busq, int cuenta);

int main(void) {
	int opcion=0;
	string busca="";
	nombre* pInicio = NULL;
	do{
		Impmenu(); cin >> opcion;

		switch (opcion) {
		case 1:
			InsetDat(&pInicio);
			break;
		case 2:
			cout<<"Ingrese el nombre que desea borrar: ";cin>>busca;
			cout<<endl;
			DeleteName(&pInicio, busca, 0);
			break;
		case 3:
		    cout<<"Ingrese el nombre de la persona a la cual desea actualizar sus datos: ";cin>>busca;
			cout<<endl;
			actualizarDatos(&pInicio, busca, 0);
			break;
		case 4:
			ImpDat(pInicio, 0);
			break;
		}


	} while (opcion != 0);

	return 0;
}
void InsetDat(nombre** pInicio){
	nombre* nuevo = new nombre;
	cout << "Ingrese su nombre: "; cin >> nuevo->Nombre;
	cout << "Ingrese su apellido: "; cin >> nuevo->Apellido;
	cout << "Ingrese su carnet: "; cin >> nuevo->Carnet;
	cout << "Ingrese su telefono: "; cin >> nuevo->Telefono;
	cout << "Ingrese su correo: "; cin >> nuevo->Correo;
	cout << "Ingrese su edad: "; cin >> nuevo->edad;
	nuevo->sgt = NULL;

	if (!*pInicio)
		* pInicio = nuevo;
	else {
		nombre* aux = *pInicio;

		while (aux->sgt)
			aux = aux->sgt;

		aux->sgt = nuevo;
	}
}

void Impmenu(void) {
	cout<<endl;
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Introducir datos (nombres y apellidos sin espacio, por favor) . . ." << endl;
	cout << "2. Eliminar datos de una persona por su nombre. . ." << endl;
	cout << "3. Actualizar datos de una persona por su nombre . . ." << endl;
	cout << "4. Mostrar Datos" << endl;
	cout << "0. Salir.....Su opcion: ";
}

void ImpDat(nombre* lista, int cuenta){
	if(!lista){
	    if(cuenta==0){
	    	cout<<endl;
	    	cout<<"Lista Vacia"<<endl;
		}
		return;
	}
	else{
		cout<<endl;
		cout << "Introduzca su Nombre: " << lista->Nombre <<endl;
		cout<< "Introduzca su Apellido: " << lista->Apellido<<endl;
		cout<< "Introduzca su numero de Carnet: " << lista->Carnet<<endl;
		cout<< "Introduzca su direccion de Correo electronico: " << lista->Correo<<endl;
		cout<< "Introduzca su numero de Telefono: " << lista->Telefono<<endl;
		cout<< "Introduzca su Edad: " << lista->edad<<endl;
		ImpDat(lista->sgt, cuenta+1);
	}
}
void actualizarDatos(nombre** lista, string busq, int cuenta) {
	if (*lista){
		if ((*(*lista)).Nombre == busq) {
			(*(*lista)).Apellido="";
			cout << "Ingrese un apellido: "; cin >> (*(*lista)).Apellido;
			cout << "Ingrese un carnet: "; cin >> (*(*lista)).Carnet;
			cout << "Ingrese un telefono: "; cin >> (*(*lista)).Telefono;
			cout << "Ingrese un correo: "; cin >> (*(*lista)).Correo;
			cout << "Ingrese edad: "; cin >> (*(*lista)).edad;
	
		}
		else {
			actualizarDatos(&(*(*lista)).sgt, busq, cuenta+1);
		}
	}else{
		if(cuenta==0)
		cout<<"Lista sin datos"<<endl;
	}
}

void DeleteName(nombre** lista, string busq, int cuenta) {
	if (*lista ) {
		if ((*(*lista)).Nombre == busq) {
			*lista = (*(*lista)).sgt;
			DeleteName(lista, busq, cuenta+1);
		}
		else {
			DeleteName(&(*(*lista)).sgt, busq, cuenta+1);
		}
	}else{
		if(cuenta==0)
		cout<<"Lista sin datos"<<endl;
	}
}