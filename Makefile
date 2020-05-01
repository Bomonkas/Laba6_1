TARGET = main.out

HDRS = \
	   include

SRCS = \
	   src/main.cpp \
	   src/ODE.cpp \
	   src/eulers.cpp

.PHONY: all clean

all: $(SRCS)
	@$(CXX) -I $(HDRS) -o $(TARGET) $(CXXFLAGS) $(SRCS) 
	@./$(TARGET)
	
clean:
	rm -rf $(TARGET)