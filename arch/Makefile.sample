#Makefile Mips R2000 developed by Igor Loi
#v 1.0 2004/12/05 21:42 Diee Cagliari
# Thanks to Nicolai Ascanium from IMM

TARGET_ARCH = linux

CC     = g++
OPT    = -O3
DEBUG  = -g
OTHER  = -Wall -Wno-deprecated
CFLAGS = $(OPT) $(OTHER)
# CFLAGS = $(DEBUG) $(OTHER)
MODULE = processor

SRCS =  ula.cpp registrador.cpp breg.cpp data_memory.cpp inst_memory.cpp control_unit.cpp mux2.cpp shift2.cpp signext.cpp adder.cpp instdec.cpp and2.cpp main.cpp clockgen.cpp mux2_5b.cpp
	   
OBJS 	= $(SRCS:.cpp=.o)
DEPS	= $(SRCS:.cpp=.d)


%.o : %.cpp
	$(CC) $(INCDIR) $(LIBDIR) $(EXTRA) $(CFLAGS) -c -o $@ $<


$(MODULE): $(OBJS)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt


include ./Makefile.defs
