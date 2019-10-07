//Francisco Sosa 00357518
//Ejercicio 5
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
    void insAntes_1(int, int);
    void insertarInicioLista(int);
    void mostrarLista(void);
    void mostrarListaRec(void);
    void mostrarListaRec(nodo *);
    void mostrarListaRecD(void);
    void mostrarListaRecD(nodo *);
};
ListaSimple::ListaSimple(void) {
    pInicio = NULL;
}
void ListaSimple::mostrarLista(void) {
    nodo *s = pInicio;

    cout << "Los elementos de la lista son:" << endl;
    while (s != NULL) {
        cout << s->dato << " ";
        s = s->sig;
    }
}
void ListaSimple::insAntes_1(int dato, int datoRef) {
    nodo *nuevo, *p, *q;

    nuevo = new nodo;
    nuevo->dato = dato;

    p = pInicio;
    q = NULL;
    while (p != NULL && p->dato != datoRef) {
        q = p;
        p = p->sig;
    }
    if (q == NULL) {
        if (p == NULL) {
            cout << "Insertaste el primero" << endl;
            pInicio = nuevo;
            pInicio->sig = NULL;
        } else {
            cout << "Dato de referencia esta al principio" << endl;
            pInicio = nuevo;
            pInicio->sig = p;
        }
    } else {
        if (p == NULL) {
            cout << "Dato de referencia no encontrado" << endl;
            q->sig = nuevo;
            nuevo->sig = NULL;
        } else {
            cout << "Dato insertado a mitad de la lista" << endl;
            q->sig = nuevo;
            nuevo->sig = p;
        }
    }
}
void ListaSimple::mostrarListaRec(void) {
    mostrarListaRec(pInicio);
}

void ListaSimple::mostrarListaRec(nodo *s) {
    if (s != NULL) {
        mostrarListaRec(s->sig);
        cout << s->dato << " ";
    }
}

void ListaSimple::mostrarListaRecD(void) {
    mostrarListaRecD(pInicio);
}

void ListaSimple::mostrarListaRecD(nodo *s) {
    if (s != NULL) {
        cout << s->dato << " ";
        mostrarListaRecD(s->sig);
    }
}
int main(void)
{
    ListaSimple miLista;
    char resp;
    int dato, datoRef;
    
    cout << "Desea meter un dato (s/n)?";
    cin>> resp;
    while(resp == 's'){
        cout << "Digite el dato: ";
        cin >> dato;
        cout << "Antes de cual vas a insertarlo? ";
        cin >> datoRef;
        miLista.insAntes_1(dato, datoRef);
        cout << "Desea meter un dato (s/n)?";
        cin>> resp;
    }
     cout << "\nMostrar lista iterativo (sentido directo):" << endl;
    miLista.mostrarLista();
    cout << "\nMostrar lista recursivo (sentido inverso):" << endl;
    miLista.mostrarListaRec();
    cout << "\nMostrar lista recursivo (sentido directo):" << endl;
    miLista.mostrarListaRecD();
    
    return 0;
}
    
