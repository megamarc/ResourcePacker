sourcelist = list
passphrase = my_AES128_passphrase

# cross-platform compatibility
ifeq ($(OS),Windows_NT)
	RM = del /Q bin\respack.exe lib\librespack.a test\test.exe
else
	RM = rm bin/respack.exe lib/librespack.a test/test.exe
endif

all: bin/respack test/test

bin/respack: lib/librespack.a
	gcc respack/respack.c lib/librespack.a -I"include" -o bin/respack.exe -s

lib/librespack.a:
	gcc src/*.c -I"include" -c -s
	ar rcs lib/librespack.a *.o

test/test: lib/librespack.a
	gcc test/test.c lib/librespack.a -I"include" -o test/test.exe -s
	
# without encryption
	cd test && "../bin/respack.exe" $(sourcelist).txt
	cd test && test.exe $(sourcelist).dat
	
# with encryption
	cd test && "../bin/respack.exe" $(sourcelist).txt $(passphrase)
	cd test && test.exe $(sourcelist).dat $(passphrase)
	
clean:
	$(RM)
	