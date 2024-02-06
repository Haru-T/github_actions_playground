SHELL = /bin/sh

CFLAGS  += -Iinclude -std=c99

.PHONY: all
all: libquaternion.a

.PHONY: test
test: test-quaternion
	./test-quaternion

quaternion.o: src/quaternion.c include/quaternion.h
	$(CC) $(CFLAGS) -c $< -o $@

libquaternion.a: libquaternion.a(quaternion.o)
	$(AR) $(ARFLAGS) $@ $?

test-quaternion: test/quaternion.c libquaternion.a
	$(CC) $(CFLAGS) $^ -lm -o $@

.PHONY: clean
clean:
	$(RM) quaternion.o libquaternion.a test-quaternion
