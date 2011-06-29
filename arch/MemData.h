#include "systemc.h"

SC_MODULE(MemData){

	//memoria
	sc_signal<sc_int<32> > mem[1024];


	SC_CTOR(MemData) {
	}
};

