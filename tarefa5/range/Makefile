
MODULE=run.x

WORK=.
SYSTEMC_LIB=$(firstword $(wildcard $(SYSTEMC)/lib*))
SCV_LIB=$(firstword $(wildcard $(SCV)/lib*))
.PHONY: all clean 

all:
	@echo "+++++++++++++++++++++++++++++++++"
	@echo "Compiling a SystemC example"
	$(CXX) -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I$(SCV)/include -I/include\
            -c $(WORK)/adder.cpp
	$(CXX) -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I$(SCV)/include -I/include\
            -c $(WORK)/stimuli.cpp
	$(CXX) -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I$(SCV)/include -I/include\
            -c $(WORK)/display.cpp
	$(CXX) -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I$(SCV)/include -I/include\
            -c $(WORK)/main.cpp
	$(CXX) -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I$(SCV)/include -I/include\
            -L$(WORK)/ -L$(SYSTEMC_LIB) -L$(SCV_LIB)\
            -o $(WORK)/$(MODULE) \
            $(WORK)/adder.o $(WORK)/stimuli.o $(WORK)/display.o $(WORK)/main.o\
            -lsystemc -lscv -lm   2>&1 | c++filt
	@echo "+++ Executing +++++++++++++++++++"
	$(WORK)/$(MODULE)

clean:
	rm -fr *.o *.x *.deps dependencies.mk *~

