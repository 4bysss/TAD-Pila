#include<iostream>
#include"carta.h"
#include"pilaDinamica.h"
#include<algorithm>

bool solitario(pilaD<tcarta>&mazO,pilaD<tcarta>&montoN);
int main(){
	tcarta baraja[40];
	bool victoria = false;
	int partidas=0;
	pilaD<tcarta> mazo,monton;
	for(int i=0,p=oro;p<=copas;p++){
		for(int f=as;f<=rey;f++,i++){
			baraja[i]= tcarta(Cpalo(p),Cfig(f));
		}
	}
	while(!victoria){
		std::random_shuffle(baraja,baraja+40);
		for(int i=0;i<40;i++){
			mazo.push(baraja[i]);
		}
		victoria=solitario(mazo,monton);
		partidas++;
		if(!mazo.vacia()){
			mazo.~pilaD();
		}
		if(!monton.vacia()){
			monton.~pilaD();
		}
		std::cout<<"a";
	}
	std::cout<<"Has ganado y solo te han hecho falta"<<partidas<<"puto inutil";
	return 0;
}

bool solitario(pilaD<tcarta>&mazO,pilaD<tcarta>&montoN){
	bool puesta1,puesta2;
	int cartasP=0;
	Cfig montones[]={vacio,vacio,vacio,vacio};	
	do{
		puesta1=puesta2=false;
		do{
			for(int i=0;i<2;i++){
				if(!mazO.vacia()){
					tcarta carta =mazO.tope();
					montoN.push(carta);
					mazO.pop();
				}
			}
			do{
				puesta2=false;
				if(!montoN.vacia()){
					tcarta topE=montoN.tope();
					Cfig figu=montones[topE.palo()];
					if(topE.figura()==Cfig(figu+1)){

						montoN.pop();
						cartasP++;
						puesta2=true;
						puesta1=true;
						montones[topE.palo()]=Cfig(figu+1);
					}
				}
			}while(puesta2);
		}while(!mazO.vacia());
		while(!montoN.vacia()){
			tcarta topE= montoN.tope();
			mazO.push(topE);
			montoN.pop();
		}
	}while(puesta1);
	std::cout<<"se han puesto"<<cartasP<<std::endl;
	return (mazO.vacia());
	
}
