TARGET = main.out

HDRS = \
	   project/include

SRCS = \
	   project/src/numSolODE.cpp \
	   project/src/main.cpp \
	   project/src/equations.cpp

.PHONY: all clean

all: $(SRCS)
	$(CXX) -I $(HDRS) -o $(TARGET) $(CXXFLAGS) $(SRCS) 
	./$(TARGET)
	
clean:
	rm -rf $(TARGET)
