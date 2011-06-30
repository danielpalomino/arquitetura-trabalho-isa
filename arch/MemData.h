#include "systemc.h"

SC_MODULE(MemData){

	//memoria
	sc_signal<sc_uint<8> > mem[1024];


	SC_CTOR(MemData) {
	}
};

