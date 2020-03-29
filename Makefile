CXX = g++

INCDIR = include
OBJDIR = obj
SRCDIR = src
BLDDIR = build

CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INCDIR) -g
LIBS = 

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

TARGET = $(BLDDIR)/main
TARGETSRC = main.cpp

all: $(TARGET)

cleanall: clean $(TARGET)

$(TARGET): $(TARGETSRC) $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< $(LIBS) -o $@ 

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
