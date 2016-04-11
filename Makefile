CFLAGS    = -g -Wall -std=c++11
GXX        = g++
DIRECTORIES:=$(dir $(wildcard ./**/))
EXCLUDE_DIRECTORIES=./src/ ./bin/ ./data/
DIRECTORIES:=$(filter-out $(EXCLUDE_DIRECTORIES), $(DIRECTORIES))
#SRC_FILES := $(patsubst %, %.cpp, $(DIRECTORIES))
SRC_FILES := $(shell find . -name \*.cpp ! -path ./src/\* ) 
SRC_FILES := $(filter-out long/long.cpp, $(SRC_FILES))
OBJ_FILES := $(patsubst %.cpp, %.out, $(SRC_FILES))
INCLUDE   := -Iinclude
AUX       := $(wildcard ./src/*.cpp)
AUX_OBJS  := $(patsubst ./src/%.cpp, ./bin/%.o, $(AUX))
SYMS      := $(wildcard ./**/*.dSYM)

## Python File For getting sample data
GET_DATA  = python get_sample_data.py

all: $(AUX_OBJS) $(OBJ_FILES)  

prob: 
	$(GXX) $(CFLAGS) $(INCLUDE) $(AUX_OBJS) $(P)/$(P).cpp -o $(P)/$(P).out

%.out: %.cpp 
	$(GXX) $(CFLAGS) $(INCLUDE) $(AUX_OBJS) $^ -o $@

bin/%.o: src/%.cpp
	$(GXX) $(CFLAGS) $(INCLUDE) $^ -c -o $@

.PHONY: create
create:
	mkdir $(Q)
	cp template $(Q)/$(Q).cpp
	@sed -i -e  s/Q/$(Q)/g $(Q)/$(Q).cpp
	@rm $(Q)/$(Q).cpp-e
	@echo obtaining sample data
	$(GET_DATA) $(Q)

.PHONY:show
show:
	@echo here are the sources: $(SRC_FILES)
	@echo here are the direcs: $(DIRECTORIES)
	@echo here are the aux objs $(AUX_OBJS)
	@echo here are the dsyms $(SYMS)

.PHONY: clean
clean:
	rm -rf $(OBJ_FILES)
	rm -rf $(SYMS)
