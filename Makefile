
PROGNAME := main
INCDIR := include
SRCDIR := src
LIBDIR := lib
OUTDIR := build
OBJDIR := build
TARGET := $(OUTDIR)/$(PROGNAME)
SRCS := $(wildcard $(SRCDIR)/$(LIBDIR)/*.cpp)
OBJS := $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
MAIN_SRCS := $(wildcard $(SRCDIR)/*.cpp)
MAIN_OBJS := $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(MAIN_SRCS)))

CC = gcc
# GCC compiling & linking flags
CFLAGS  = -std=c++20 #-Wall
CFLAGS += -I$(INCDIR)
#CFLAGS += -v # verbose g++ log
CFLAGS += -lm # link math library
CFLAGS += -O2

.PRECIOUS : $(MAIN_OBJS) $(OBJS)

.PHONY: all clean main namespace_lesson class_lesson

all				: main
main		    : $(OUTDIR)/main
namespace_lesson: $(OUTDIR)/namespace_lesson
class_lesson	: $(OUTDIR)/class_lesson
string_lesson	: $(OUTDIR)/string_lesson

$(OUTDIR)/%: $(OBJS) $(OBJDIR)/$(SRCDIR)/%.o
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	g++ $(CFLAGS) -o $@ $^


$(OBJDIR)/%.o:%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OUTDIR)