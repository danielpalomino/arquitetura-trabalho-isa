#include "breg.h"

void breg::write() {
	if( w_en.read() == '1' ) {
		bank[address_w.read()].write(data_w.read());
	}
}

void breg::read() {
	data_a.write(bank[address_a.read()]);
	data_b.write(bank[address_b.read()]);
}
