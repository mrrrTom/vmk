main: main.c task std_bin_tree.h
	@gcc -I ./ main.c
	@echo ---------------------------task----------------------------------
	@cat task
	@echo --------------------------output---------------------------------
	./a.out
	@echo ""

debug: main.c std_bin_tree.h
	gcc -I ./ -g main.c
	gdb ./a.out
