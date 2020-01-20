#include "systemc.h"

SC_MODULE(procesor2) {

	sc_inout<sc_uint<16>> state;

	void task4() {
		if (state.read() == 3) {
			cout << "Gramofon" << endl;
		}
	}

	SC_CTOR(procesor2) {
		SC_METHOD(task4);
		sensitive << state;
	}
};