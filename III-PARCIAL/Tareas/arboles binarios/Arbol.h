#include "Nodo.h"
class Arbol
{
 private:
 Nodo* arbol = NULL;
 public:
 void setArbol(Nodo*);
 Nodo* getArbol();
 Nodo* crearNodo(int);
 void insertarNodo(Nodo*&, int);
 void mostrar(Nodo*, int);
 bool buscar(Nodo*, int);
 void preOrden(Nodo*);
 void inOrden(Nodo*);
 void postOrden(Nodo*);
 int altura(Nodo* );
 int nivel(Nodo*, int, int );
 int anchura(Nodo*);
};

void Arbol::setArbol(Nodo* _arbol){
 arbol = _arbol;
}
Nodo* Arbol::getArbol(){
 return arbol;
}
Nodo* Arbol::crearNodo(int dato){
 Nodo* nuevoNodo = new Nodo();
 nuevoNodo->setDato(dato);
 nuevoNodo->setDerecha(NULL);
 nuevoNodo->setIzquierda(NULL);
 return nuevoNodo;
}
void Arbol::insertarNodo(Nodo*& arbol, int dato){
 if(arbol == NULL){
 Nodo* nuevoNodo = crearNodo(dato);
 arbol = nuevoNodo;
 }
 else{
 int raiz = arbol->getDato();
 if(dato < raiz){
 insertarNodo(arbol->getIzquierda(), dato);
 }
 else{
 insertarNodo(arbol->getDerecha(), dato);
 }
 }
}
/*Comprobamos si el arbol esta vacio, si ese es el caso creamos un nuevo nodo e
igualamos el arbol al nuevo nodo. Si el arbol cuenta con alg�n dato entonces creamos una
variable llamanda raiz para obtener si valor y establecer si el nuevo element va a la derecha o a
la izquierda*/

void Arbol::mostrar(Nodo* arbol, int contador){
 if(arbol == NULL){
 return;
 }
 else{
 mostrar(arbol->getDerecha(), contador+1);
 for(int i = 0; i < contador; i++){
 cout << " ";
 }
 cout<<arbol->getDato() << endl;
 mostrar(arbol->getIzquierda(), contador +1);
 }
}
/*Comprobamos si el �rbol est� vac�o entonces retornamos el �rbol
vac�o, caso contrario aplicamos recursividad para ir mostrando los
datos del �rbol*/
bool Arbol::buscar(Nodo* arbol, int dato){
 if(arbol == NULL){
 return false;
 }
 else if(arbol->getDato() == dato){
 return true;
 }
 else if(dato < arbol->getDato()){
 buscar(arbol->getIzquierda(), dato);
 }
 else{
 buscar(arbol->getDerecha(), dato);
 }
}

/*Para buscar un elemento comprobamos si el arbol est� vac�o, caso contrario verificamos
el nodo a ver si es el dato buscado, si este es menor buscamos a la derecha y si es mayor lo
buscamos a la izquierda*/
void Arbol::preOrden(Nodo* arbol){
 if(arbol == NULL){
 return;
 }
 else{
 cout << arbol->getDato() << " ";
 preOrden(arbol->getIzquierda());
 preOrden(arbol->getDerecha());
 }
}
/*El recorrido en preorden es: raiz, izquierda, derecha*/
void Arbol::inOrden(Nodo* arbol){
 if(arbol == NULL){
 return;
 }
 else{
 inOrden(arbol->getIzquierda());
 cout << arbol->getDato() << " ";
 inOrden(arbol->getDerecha());
 }
}
/*El recorrido en inorden es: izquierda, raiz, derecha*/
void Arbol::postOrden(Nodo* arbol){
 if(arbol == NULL){
 return;
 }
 else{
 postOrden(arbol->getIzquierda());
 postOrden(arbol->getDerecha());
 cout << arbol->getDato() << " ";

 }
}

/* si el �rbol es vac�o su altura es 0; y
si el �rbol no es vac�o su altura es 1 m�s que el m�ximo de las alturas de sus hijos.*/
int Arbol::altura(Nodo* arbol)
{
    if (arbol->getIzquierda() == NULL && arbol->getDerecha() == NULL)
    {
        return 0;
    }
    int lheight = -1, rheight = -1;
        /* compute the height of each subtree */
    if (arbol->getIzquierda() != NULL) {
        lheight = altura(arbol->getIzquierda()); //Altura del sub-arbol izquierdo, si, existe
    }
    if (arbol->getDerecha() != NULL) {
        rheight = altura(arbol->getDerecha()); //Altura del sub-arbol Derecho, si, existe
    }
    //Elegimos al mayor y le sumamos 1
    if (lheight > rheight) {
        return lheight + 1;
    }
    else {
        return rheight + 1;
    }      
}

int Arbol::nivel(Nodo* arbol, int n, int nivel)
{
    if (arbol->getIzquierda() == NULL && arbol->getDerecha() == NULL)
    {
        return 0;
    }

    if (arbol- == n)
        return level;

    return getLevel(root->left, n, level + 1) |
        getLevel(root->right, n, level + 1);

    

}

