all: bin/respack

bin/respack: lib/librespack.a
	gcc respack/respack.c lib/librespack.a -I"include" -o bin/respack

lib/librespack.a:
	gcc src/*.c -I"include" -c
	ar rcs lib/librespack.a *.o
