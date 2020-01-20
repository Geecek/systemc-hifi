#include "systemc.h"
#include "sw.cpp"
#include "fifo.cpp"
#include "procesor1.cpp"
#include "procesor2.cpp"

int sc_main(int argc, char* argv[]) {
	sc_signal<sc_uint<16>, SC_MANY_WRITERS> swState;
	sc_signal<sc_uint<16>, SC_MANY_WRITERS> modul_sprzet;
	fifo fifo("fifo");

	system("clear");
	cout << "Sprzet HIFI\n";
	cout << "1.Radio \n2.Kaseta \n3.Gramofon \n4.Plyta \n5.DVD Film \n6.AUX \n7.Ustawienia \n0.Cofnij \n" << endl;

	sw sw("sw");
	procesor1 p1("p1");
	procesor2 p2("p2");

	sw.out(fifo.avalon);
	p1.sw(fifo.avalon); 
	p1.state(swState); 
	p2.state(swState);

	p1.module_out(modul_sprzet);

	sc_start(); 

	return 0;
}