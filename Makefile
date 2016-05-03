# -*- indent-tabs-mode:t; -*-

CC=clang
NUM_HASHES=100
ROCKYOU=rockyou.txt

all: hashpass crack

# This rule links hashpass.o and md5.o along with the
# libssl and libcrypto libraries to make the executable.
hashpass: hashpass.o md5.o
	clang hashpass.o md5.o -o hashpass -l ssl -l crypto

md5.o: md5.c md5.h
	clang -g -c md5.c -Wall

hashpass.o: hashpass.c md5.h
	clang -g -c hashpass.c -Wall

# TODO: Write a rule to compile binsearch.o out of binsearch.c
binsearch.o: binsearch.c binsearch.h


# TODO: Your crack program will need to use binary search, so
# add it to the dependecies and receipe below.
crack: crack.o md5.o
	clang crack.o md5.o -o crack -l ssl -l crypto

crack.o: crack.c md5.h
	clang -g -c crack.c -Wall

hashes: hashpass $(ROCKYOU)
	shuf -n $(NUM_HASHES) $(ROCKYOU) > passwords.txt
	./hashpass < passwords.txt > hashes.txt

# Fetch the rockyou.txt file that contains 3 million entries
rockyou.txt:
	wget http://cs.sierracollege.edu/cs46/rockyou.txt.gz
	gunzip rockyou.txt.gz

clean:
	rm -f *.o hashpass crack hashes.txt passwords.txt rockyou.txt

test: crack
	./crack hashes.txt $(ROCKYOU)
