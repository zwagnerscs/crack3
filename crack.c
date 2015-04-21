#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"
#include "bintree.h"

const int PASS_LEN=50;        // Maximum any password can be
const int HASH_LEN=33;        // Length of MD5 hash strings

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
// Read in the hash file and return the array of strings.
// Use the technique we showed in class to expand the
// array as you go.
char **read_hashes(char *filename)
{
    return NULL;
}


// TODO
// Read in the dictionary file and return the tree.
// Each node should contain both the hash and the
// plaintext word.
node *read_dict(char *filename)
{
    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hash file into an array of strings
    char **hashes = read_hashes(fill this in);

    // TODO: Read the dictionary file into a binary tree
    node *dict = read_dict(fill this in);

    // TODO
    // For each hash, search for it in the binary tree.
    // If you find it, get the corresponding plaintext dictionary
    // entry. Print both the hash and word out.
    // Need only one loop. (Yay!)
}
