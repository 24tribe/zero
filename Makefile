CFLAGS = -Wall -Wextra -Iminhook/include -g -Ilibpeconv/libpeconv/include
LDFLAGS = -luser32 -lMinHook -Llib -Llibpeconv/build/libpeconv -ladvapi32 -lntdll  -llibpeconv -lm

HOOKS_SRC = create_file_hook.c load_library_hook.c NtQueryDirectoryFileHook.c

all: hello mylib.dll loadlibrarytest.exe testprog.exe testhook.dll unprotectdll.dll

hello: hello.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

metadata_test.exe: metadata_test.c MetadataDump.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

mylib.dll: mylib.c $(HOOKS_SRC) utils.c RemapMem.c MetadataDump.c
	$(CC) -o $@ -shared $^ $(CFLAGS) $(LDFLAGS)

loadlibrarytest.exe: loadlibrarytest.c utils.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

testhook.dll: testhook.c
	$(CC) -o $@ -shared $^ $(CFLAGS) $(LDFLAGS)

testingdll.dll: testingdll.c
	$(CC) -o $@ -shared $^ $(CFLAGS) $(LDFLAGS)

unprotectdll.dll: unprotectdll.c
	$(CC) -o $@ -shared $^ $(CFLAGS) $(LDFLAGS)

testprog.exe: testprog.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

anothertest.exe: anothertest.c RemapMem.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

reconsdll.exe: reconsdll.cpp MetadataDump.o
	$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

MetadataDump.o: MetadataDump.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(LDFLAGS)

printsections.exe: printsections.c MetadataDump.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: all