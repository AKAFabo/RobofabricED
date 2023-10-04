#include <cstdlib>
#include <iostream>

using namespace std;


struct Pedido{
	int id;
	int priority;
	
	Pedido (int _id, int _p){
		id = _id;
		priority = _p;
	}
};


struct Nodo {
       int dato; 
       Pedido * pedido;  
       Nodo* siguiente;

       Nodo(int d) 
       {
                dato = d; 
                siguiente = NULL; 
       }
    
       Nodo(Pedido * p) 
       {
                dato = p->id; 
                siguiente = NULL; 
                pedido = p;
       }
      void imprimir();
       
};

struct Cola {

       Nodo * frente; 
       
       Cola()
       {
            frente = NULL;
       }
       
       void encolar (int dato);
       Nodo* desencolar (void);
       Nodo* verFrente(void);
       bool vacia(void);
       void imprimir(void);

       void encolarPedido (Pedido * p){
       		if (vacia())
		        frente = new Nodo (p);
		    else 
		    {

		            Nodo* actual = frente;
	
		            while (actual->siguiente != NULL)
		                          actual = actual->siguiente; 
		              
		            Nodo* nuevo = new Nodo (p);
		            actual->siguiente = nuevo;
		    }
	   }
};

struct ColaPrioridad {

       Cola * colaRegular;
       Cola * colaEspecial;
       
       ColaPrioridad()
       {
            colaRegular = new Cola();
            colaEspecial = new Cola();
       }
       

       void encolar (Pedido * p){
       		if (p->priority == 1)
       			colaRegular->encolarPedido(p);
       		else
       			colaEspecial->encolarPedido(p);
	   }
       Nodo* desencolar (){
       		if (!colaEspecial->vacia())
       			return colaEspecial->desencolar();
       		else
       			return colaRegular->desencolar();
	   }
	   
	   void imprimir(){
	   	cout <<"Cola prioridad: " << endl;
	   	colaEspecial->imprimir();
	   	cout << endl << endl << "Cola: ";
	   	colaRegular->imprimir();
	   }
};



