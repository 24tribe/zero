CFLAGS = -Wall -Wextra -Iinclude
# LDFLAGS = -luser32 -lMinHook -lyaha -Llib
LDFLAGS = -luser32 -lMinHook -Llib

all: hello mylib.dll

hello: hello.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

mylib.dll: mylib.c
	$(CC) -o $@ -shared $^ $(CFLAGS) $(LDFLAGS)

.PHONY: all