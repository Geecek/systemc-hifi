#include "systemc.h"

SC_MODULE(sw) {
	sc_fifo_out<int> out;

	void read() {
		int val = 0;
		while (1)
		{
			wait(10, SC_NS);
			cin >> val;
			out.write(val);
		}
	}

	SC_CTOR(sw) {
		SC_THREAD(read);
	}
};