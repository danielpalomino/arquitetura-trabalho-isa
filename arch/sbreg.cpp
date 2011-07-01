#include "sbreg.h"

void sbreg::write() {
	if( w_en.read() == '1' ) {
		bank[15].write(bank[14].read());
		bank[14].write(bank[13].read());
		bank[13].write(bank[12].read());
		bank[12].write(bank[11].read());
		bank[11].write(bank[10].read());
		bank[10].write(bank[9].read());
		bank[9].write(bank[8].read());
		bank[8].write(bank[7].read());
		bank[7].write(bank[6].read());
		bank[6].write(bank[5].read());
		bank[5].write(bank[4].read());
		bank[4].write(bank[3].read());
		bank[3].write(bank[2].read());
		bank[2].write(bank[1].read());
		bank[1].write(bank[0].read());
		bank[0].write(data_in.read());
	}
}

void sbreg::read() {
	data_out.write(bank[address.read()]);
}

