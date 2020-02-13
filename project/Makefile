TARGET = main.out

HDRS = \
	   project/include

SRCS = \
	   project/src/secondary.cpp \
	   project/src/main.cpp \
	   project/src/equations.cpp \
	   project/src/exp_eur.cpp \

.PHONY: all clean

all: $(SRCS)
	$(CXX) -I $(HDRS) -o $(TARGET) $(CXXFLAGS) $(SRCS) 
	./$(TARGET)
	
clean:
	rm -rf $(TARGET)