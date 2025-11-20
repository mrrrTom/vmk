main: main.c task
	@gcc main.c -I ./
	@echo ---------------------------task----------------------------------
	@cat task
	@echo --------------------------output---------------------------------
	./a.out
	@echo ""
debug: main.c
	gcc main.c -g -I ./
	gdb ./a.out
