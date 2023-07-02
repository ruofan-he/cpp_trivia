#目標
#1. srcに複数のソースファイルを置く
#2. includeにそれらのヘッダーファイルを置く
#3. 分割コンパイルしつつも、それらがリンクされているようにする。
#4. 出力先のフォルダを別に指定する。
#ある関数がどのようにインクルードされているか確認する方法

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# GCC compiling & linking flags
CFLAGS  = -std=c++20 -Wall
CFLAGS += -I$(INC_DIR)
#CFLAGS += -v # verbose g++ log
CFLAGS += -lm # link math library

all: $(OBJ_DIR)/util1.o $(OBJ_DIR)/util2.o
	g++ src/main.cpp $(OBJ_DIR)/util1.o $(OBJ_DIR)/util2.o $(CFLAGS)

$(OBJ_DIR)/util1.o: $(SRC_DIR)/util1.cpp
	mkdir -p $(OBJ_DIR)
	g++ -c $^ -o $@ $(CFLAGS)

$(OBJ_DIR)/util2.o: $(SRC_DIR)/util2.cpp
	mkdir -p $(OBJ_DIR)
	g++ -c $^ -o $@ $(CFLAGS)
