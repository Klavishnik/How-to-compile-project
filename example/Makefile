all: compile ubsan preproc assm link 

compile:
	gcc main.c -Wall -Wextra -Werror -ftrapv -o bin

ubsan:
	clang main.c -fsanitize=undefined -o ubsan.out

preproc:
	gcc main.c -E > prep.txt

assm:
	gcc main.c -S

link:
	gcc -c main.c

clean:
	rm bin main.s main.o ubsan.out prep.txt

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all       - compiles, performs undefined behavior sanitizer, preprocesses, assembles, and links the program"
	@echo "  compile   - compiles the program with -Wall -Wextra -Werror -ftrapv option"
	@echo "  ubsan     - performs undefined behavior sanitizer on the program"
	@echo "  preproc   - preprocesses the program and saves the output to prep.txt"
	@echo "  assm      - generates the assembly code for the program"
	@echo "  link      - compiles and generates object file for the program"
	@echo "  clean     - removes all generated files"	
