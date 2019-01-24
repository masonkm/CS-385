CXX      = g++ #the name of the compiler
CXX_FILE = $(wildcard *.cpp) #using a wildcard subshell to determine the name of the cpp file
TARGET   = $(patsubst %.cpp,%,$(CXX_FILE)) #the name for the output executable
CXXFLAGS = -g -std=c++11 -Wall -Werror -pedantic-errors -fmessage-length=0 
	#-g : to include debug information
	#-std : telling the compiler to use a specific release of the c++ specification. By default they use C++ 1997
	#-wall : is to warn you on everything you did wrong, lots of warnings and to be very specific
	#-werror : turns all warnings into errors
	#-pedantic-errors : be even more annoying to do about your compilation errors.
	#-fmessage-length : it sets the error line length to be zero. It makes it not word wrap, it forces it to fit the contents of the console
	#

all:
	$(CXX) $(CXXFLAGS) $(CXX_FILE) -o $(TARGET) #capital o for optimize, lowercase o for target
clean:
	rm -f $(TARGET) $(TARGET).exe
