nasm -g -f elf32 -P ./bin/macro.inc -P ./bin/a.inc -o ./bin/a.o ./bin/a.asm
gcc -m32 -fno-stack-protector -c -o bin/tio.o bin/tio.c
ar -crv bin/libtio.a bin/tio.o
rm bin/tio.o
ld -g -m elf_i386 ./bin/a.o  -L ./bin/ -ltio -o a.out # -dynamic-linker /lib/ld-linux.so.2 -lc -o a.out
