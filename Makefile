
PROGNAME := main
INCDIR := include
SRCDIR := src
LIBDIR := lib
OUTDIR := build
TARGET := $(OUTDIR)/$(PROGNAME)
SRCS := $(wildcard $(SRCDIR)/$(LIBDIR)/*.cpp)
OBJS := $(addprefix $(OUTDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
MAIN_SRCS := $(wildcard $(SRCDIR)/*.cpp)
MAIN_OBJS := $(addprefix $(OUTDIR)/,$(patsubst %.cpp,%.o,$(MAIN_SRCS)))

CC = gcc
# GCC compiling & linking flags
CFLAGS  = -std=c++20 -Wall
CFLAGS += -I$(INCDIR)
#CFLAGS += -v # verbose g++ log
CFLAGS += -lm # link math library
CFLAGS += -O2

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS) $(OUTDIR)/$(SRCDIR)/main.o
	g++ $(CFLAGS) -o $@ $^


namespace_lesson: $(OUTDIR)/namespace_lesson
$(OUTDIR)/namespace_lesson: $(OBJS) $(OUTDIR)/$(SRCDIR)/namespace_lesson.o
	g++ $(CFLAGS) -o $@ $^

$(OUTDIR)/%.o:%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OUTDIR)