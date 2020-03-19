TARGET = main.out

HDRS = \
	   project/include

SRCS = \
	   project/src/secondary.cpp \
	   project/src/main.cpp \
	   project/src/test_equations.cpp \
	   project/src/method_equations.cpp \
	   project/src/exp_eur.cpp \
	   project/src/prediction_and_correction.cpp \
	   project/src/rk.cpp \
	   project/src/imp_eur.cpp \
	   project/src/take_param.cpp \
	   project/src/slau.cpp

.PHONY: all clean

all: $(SRCS)
	$(CXX) -I $(HDRS) -o $(TARGET) $(CXXFLAGS) $(SRCS) 
	./$(TARGET)
	
clean:
	rm -rf $(TARGET)
