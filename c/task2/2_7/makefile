main: main.c task calc.h two_l_list.h
	@gcc -I ./ main.c
	@echo ---------------------------task----------------------------------
	@cat task
	@echo --------------------------output---------------------------------
	./a.out
	@echo ""

debug: main.c calc.h two_l_list.h
	gcc -I ./ -g main.c
	gdb ./a.out
