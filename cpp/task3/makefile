main: main.cpp vmk_box.hpp vmk_stack.hpp task
	rm -f a.out
	g++ main.cpp -I ./
	./a.out

debug: main.cpp vmk_box.hpp vmk_stack.hpp task
	rm -f a.out
	g++ main.cpp -I ./ -g
	gdb ./a.out
