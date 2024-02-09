SHELL = /bin/sh

CFLAGS  += -Iinclude -std=c99
LIBS    += -lm

.PHONY: all
all: quaternion2matrix

.PHONY: test
test: test-quaternion
	./test-quaternion

%.o: src/%.c include/quaternion.h
	$(CC) $(CFLAGS) -c $< -o $@

quaternion2matrix: quaternion2matrix.o quaternion.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@

test-quaternion: test/quaternion.c quaternion.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@

.PHONY: clean
clean:
	$(RM) quaternion.o quaternion2matrix.o quaternion2matrix test-quaternion
