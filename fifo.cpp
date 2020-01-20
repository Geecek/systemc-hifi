#include "systemc.h"

SC_MODULE(fifo) {

	sc_fifo<int> avalon;

	SC_CTOR(fifo) {
		sc_fifo<int> avalon(7);
	}
};
