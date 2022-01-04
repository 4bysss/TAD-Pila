#ifndef _PILADIN_
#define _PILADIN_
#include<cassert>
template <typename TIPO> class pilaD {
	public:
		pilaD();
		pilaD(const pilaD<TIPO>& P);
		pilaD<TIPO>& operator=(const pilaD<TIPO>&p);
		bool vacia()const;
		const TIPO& tope()const;
		void pop();
		void push(TIPO& x);
		~pilaD();
	private:
		struct nodo{
			TIPO elemento;
			nodo* siguiente;
			nodo(const TIPO &x, nodo* p=nullptr):elemento(x),siguiente(p){};
		};
		nodo* tope_;
		void copiar(pilaD<TIPO>& copy);
};
//El unico metodo privado
template<typename TIPO>
void pilaD<TIPO>::copiar(pilaD<TIPO>&x){
	if(!x.vacia()){
		tope_=new nodo(x.tope());
		nodo *p = tope_;
		nodo* q = x.tope_->siguiente;
		while(p){	
			p->siguiente = new nodo(q->elemento);
			p=p->siguiente;
			q=q->siguiente;
		}
	}
}
//Metodos publicos


	//Constructor basico lol
template <typename TIPO>
inline pilaD<TIPO>::pilaD():tope_(nullptr){}

	//Contructor por copia
template <typename TIPO>
pilaD<TIPO>::pilaD(const pilaD<TIPO>&P):tope_(nullptr){
	copiar(P);
}
	//Operador =
template <typename TIPO>
pilaD<TIPO>& pilaD<TIPO>::operator =(const pilaD<TIPO>& x){
	if(this!=&x){
		this.~pilaD();
		copiar(x);
	}
	return *this;
}
	//Metodo vacio()
template <typename TIPO>
inline bool pilaD<TIPO>::vacia()const{
	return(tope_ == nullptr);
}
	//Metodo tope()
template <typename TIPO>
inline const TIPO& pilaD<TIPO>::tope()const{
	assert(!vacia());
	return(tope_->elemento);
}
	//Metodo pop() 
template <typename TIPO>
void pilaD<TIPO>::pop(){
	assert(!vacia());
	nodo*p=tope_;
	tope_=tope_->siguiente;
	delete p;
}
	//Metodo push()
template <typename TIPO>
void pilaD<TIPO>::push(TIPO&x){
	tope_=new nodo(x,tope_);
}
	//Metodo ~pilaD()
template <typename TIPO>
pilaD<TIPO>::~pilaD(){
	nodo*p;
	while(tope_){
		p=tope_->siguiente;
		delete tope_;
		tope_=p;
	}
}
#endif
