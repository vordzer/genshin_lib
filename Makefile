LIB_NAME=genshin_info

SRC_LIB := $(shell find src_lib/ -name \*.cpp)
OBJ_LIB := $(SRC_LIB:.cpp=.o)

src_lib/%.o: src_lib/%.cpp
	g++ -std=c++17 -c -fPIC -Isrc_lib/ -Isrc_lib/headers/ -o $@ $<

static_lib: $(OBJ_LIB)
	mkdir -p lib/
	ar rvs lib/lib$(LIB_NAME).a $<

dynamic_lib: $(OBJ_LIB)
	mkdir -p lib/
	g++ -shared -fPIC -Isrc_lib/ -Isrc_lib/headers/ -o lib/lib$(LIB_NAME).so $<

libs: static_lib dynamic_lib

test_static: static_lib main.cpp
	g++ -std=c++17 -fPIC -c -I./src_lib/headers/ -o main.o main.cpp -Llib/ -l$(LIB_NAME)
	g++ -std=c++17 -fPIC -o static_test main.o -Llib/ -l$(LIB_NAME)

clean:
	rm -rf *.o src_lib/*.o

distclean: clean
	rm -rf lib/lib$(LIB_NAME).*
	rm -rf static_test
