#ifndef _PILA_
#define _PILA_
class pila{
	public:
		typedef tcarta TDato;
		explicit pila(unsigned Tmax);
		pila(const pila&p);
		pila& operator=(const pila&p);
		bool vacia()const;//Para que sirve el const del final?
		bool llena()const;
		const TDato tope();
		void push(const TDato& x);
		void pop();
		~pila();
	private:
		TDato *elementos;
		unsigned TamM;
		unsigned NElem;
};

#endif


