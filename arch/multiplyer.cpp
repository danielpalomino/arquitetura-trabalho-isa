#include "multiplyer.h"

void multiplyer::compute() {
	output.write(input0.read() * input1.read());
}

