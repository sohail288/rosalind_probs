DIRECTORIES=$(dir $(wildcard ./**/))
SRC_FILES := $(shell find . -name \*.cpp) 
OBJ_FILES := $(patsubst %.cpp, %.out, $(SRC_FILES))

all: $(OBJ_FILES)

%.out: %.cpp
	g++ $^ -o $@

.PHONY: create
create:
	mkdir $(Q)
	cp template $(Q)/$(Q).cpp
	@sed -i -e  s/Q/$(Q)/g $(Q)/$(Q).cpp
	@rm $(Q)/$(Q).cpp-e

.PHONY:show
show:
	@echo here are the sources: $(SRC_FILES)
	@echo here are the direcs: $(DIRECTORIES)

.PHONY: clean
clean:
	rm -rf $(OBJ_FILES)
