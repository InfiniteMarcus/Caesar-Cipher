main: main.o caesarCipher.o
	gcc main.o caesarCipher.o -o caesar

brute: bruteForce.o caesarCipher.o
	gcc bruteForce.o caesarCipher.o -o brute

caesarCipher.o: caesarCipher.c caesarCipher.h
	gcc -c caesarCipher.c

main.o: main.c caesarCipher.h
	gcc -c main.c

bruteForce.o: bruteForce.c caesarCipher.h
	gcc -c bruteForce.c

clean:
	rm caesar brute *.o
