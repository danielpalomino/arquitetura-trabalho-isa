#include "adder.h"

void adder::compute() {
	s.write(a.read().to_uint() + b.read().to_uint());
}
