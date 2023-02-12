static_lib: src_lib/g_lib.cpp
	g++ -std=c++17 -fPIC -c -I./src_lib/headers/ -o src_lib/g_lib.o src_lib/g_lib.cpp
	mkdir lib/
	ar rvs lib/libgenshin_info.a src_lib/g_lib.o

dynamic_lib: src_lib/g_lib.cpp
	g++ -std=c++17 -fPIC -c -I./src_lib/headers/ -o src_lib/g_lib.o src_lib/g_lib.cpp
	mkdir lib/
	g++ -shared -fPIC -o lib/libgenshin_info.so src_lib/g_lib.o

test_static: main.cpp
	g++ -std=c++17 -fPIC -c -I./src_lib/headers/ -o genshin_lib.o main.cpp -Llib/ -lgenshin_info
	g++ -std=c++17 -fPIC -o genshin_lib genshin_lib.o -Llib/ -lgenshin_info

clean:
	rm -rf *.o src_lib/*.o
