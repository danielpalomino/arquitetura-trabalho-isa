#include "RegisterPC.h"

RegisterPC::compute() {
	pc_out.write(pc_in.read());
}

