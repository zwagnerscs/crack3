#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN=50;        // Maximum any password can be
const int HASH_LEN=33;        // Length of MD5 hash strings

struct entry 
{
    // FILL THIS IN
};

// Given a hash and a plaintext guess, return 1 if
// the hash of the guess matches the given hash.
// That is, return 1 if the guess is correct.
int tryguess(char *hash, char *guess)
{
    // Hash the guess using MD5

    // Compare the two hashes

    // Free any malloc'd memory

    return 0;
}


// TODO
// Read in the dictionary file and return the data structure.
// Each entry should contain both the hash and the dictionary
// word.
struct entry **read_dictionary(char *filename, int *size)
{
    *size = 0;
    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the dictionary file into an array of entry structures
    struct entry **dict = read_dictionary(NULL, NULL);
    
    // TODO: Sort the hashed dictionary using qsort.
    // You will need to provide a comparison function.
    qsort(dict, 0, 0, NULL);

    // TODO
    // For each hash, search for it in the dictionary using
    // binary search.
    // If you find it, get the corresponding plaintext dictionary
    // entry. Print both the hash and word out.
    // Need only one loop. (Yay!)
}
