
PROGNAME := main
INCDIR := include
SRCDIR := src
LIBDIR := lib
OUTDIR := build
TARGET := $(OUTDIR)/$(PROGNAME)
SRCS := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/$(LIBDIR)/*.cpp)
OBJS := $(addprefix $(OUTDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
$(warning $(OBJS))

CC = gcc
# GCC compiling & linking flags
CFLAGS  = -std=c++20 -Wall
CFLAGS += -I$(INCDIR)
#CFLAGS += -v # verbose g++ log
CFLAGS += -lm # link math library
CFLAGS += -O2

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS)
	g++ $(CFLAGS) -o $@ $^

$(OUTDIR)/%.o:%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OUTDIR)