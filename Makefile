grupo: grupo.o test_grupo.o
		gcc -o grupo grupo.o test_grupo.o
grupo.o: grupo.c
		gcc -c grupo.c
test_grupo.o: test_grupo.c
		gcc -c test_grupo.c
clean:
		rm *.o