cc = gcc
OBJCT = main.o songify.o artist.o album.o song.o
run: prog
	./songify
prog: $(OBJCT)
	$(cc) $(OBJCT) -o songify

main.o: main.c main.h struct.h
	gcc -c main.c

songify.o: songify.c songify.h struct.h
	gcc -c songify.c

artist.o: artist.c artist.h struct.h
	gcc -c artist.c

album.o: album.c album.h struct.h
	gcc -c album.c

song.o: song.c song.h struct.h
	gcc -c song.c

clean:
	del *.o 