#include "systemc.h"

SC_MODULE(modul_sprzet) {

	sc_in<sc_uint<16>> module_in;

	void task3() {
		if (module_in.read() == 2) {
			cout << "Kaseta" << endl;
		}
	}

	SC_CTOR(modul_sprzet) {
		SC_METHOD(task3);
		sensitive << module_in;
	}
};