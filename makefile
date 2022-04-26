cc = gcc
OBJCT = main.o songify.o artist.o album.o song.o
run: prog
	./songify
prog: $(OBJCT)
	$(cc) $(OBJCT) -o songify

main.o: main.c songify.h
	gcc -c main.c

songify.o: songify.c songify.h struct.h artist.h album.h songify.h
	gcc -c songify.c

artist.o: artist.c artist.h songify.h
	gcc -c artist.c

album.o: album.c album.h songify.h
	gcc -c album.c

song.o: song.c song.h songify.h
	gcc -c song.c

clean:
	rm -f *.o songify.exe