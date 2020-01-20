#include "systemc.h"
#include "modul_sprzet.cpp"

SC_MODULE(procesor1) {

	sc_port<sc_fifo_in_if<int> > sw;
	sc_inout<sc_uint<16>> state;
	sc_out<sc_uint<16>> module_out;
	modul_sprzet module;
	int prevSW = 0;
	int swState = 0;

	void task1() {
		while (1) {
			swState = sw->read();

			if ((prevSW == 1 && (swState == 10 || swState == 11)) ||	// AM / FM
				(prevSW == 4 && (swState == 12 || swState == 13 || swState == 14 || swState == 15))) {	// Typ plyty
				prevSW = swState;
			} else if ((prevSW == 10 || prevSW == 11) && swState == 0) {
				prevSW = 1;
			} else if ((prevSW == 12 || prevSW == 13 || prevSW == 14 || prevSW == 15) && swState == 0) {
				prevSW = 4;
			} else if (swState != 0 && prevSW != 0 ) {
				cout << "ERROR" << endl;
			} else if (swState == 0 || swState > 7) {
				prevSW = 0;
				system("clear");
				cout << "Sprzet HIFI\n";
				cout << "1.Radio \n2.Kaseta \n3.Gramofon \n4.Plyta \n5.DVD Film \n6.AUX \n7.Ustawienia \n0.Cofnij \n" << endl;
			} else if (swState != 0 && prevSW == 0) {
				prevSW = swState;
			}
			state.write(prevSW);
			module_out.write(0);
		}
	}

	void task2() {
		if (state.read() == 1) {
			system("clear");
			cout << "Radio" << endl;
			cout << "10.AM \n11.FM \n0.Cofnij \n";
		} else if (state.read() == 10) {
			cout << "Radio: AM" << endl;
		} else if (state.read() == 11) {
			cout << "Radio: FM" << endl;
		}
	}

	void task3() {
		if (state.read() == 2) {
			module_out.write(2);
		}
	}

	void task5() {
		if (state.read() == 4) {
			system("clear");
			cout << "Plyta" << endl;
			cout << "12.CD Audio \n13.CD MP3 \n14.DVD Audio \n15.DVD MP3 \n0.Cofnij \n";
		} else if (state.read() == 12) {
			cout << "CD Audio" << endl;
		} else if (state.read() == 13) {
			cout << "CD MP3" << endl;
		} else if (state.read() == 14) {
			cout << "DVD Audio" << endl;
		} else if (state.read() == 15) {
			cout << "DVD MP3" << endl;
		}
	}

	void task6() {
		if (state.read() == 5) {
			cout << "DVD Film" << endl;
		}
	}

	void task7() {
		if (state.read() == 6) {
			cout << "AUX" << endl;
		}
	}

	void task8() {
		if (state.read() == 7) {
			cout << "Ustawianie poziomu glosnosci" << endl;
		}
	}

	SC_CTOR(procesor1) : module("modul_sprzet") {
		module.module_in(module_out);

		SC_THREAD(task1);
		SC_METHOD(task2);
		sensitive << state;
		SC_METHOD(task3);
		sensitive << state;
		SC_METHOD(task5);
		sensitive << state;
		SC_METHOD(task6);
		sensitive << state;
		SC_METHOD(task7);
		sensitive << state;
		SC_METHOD(task8);
		sensitive << state;
	}
};