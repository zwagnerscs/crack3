#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "md5.h"

const int PASS_LEN=50;
const int HASH_LEN=33; 


struct entry 
{
    char password[PASS_LEN];
    char hash[HASH_LEN];
};

int qcomp (const void *a, const void *b){
    struct entry * ea = (struct entry *)a;
    struct entry * eb = (struct entry *)b;
    return strcmp((*ea).hash, (*eb).hash);
}

int bcomp (const void *a, const void *b) {
    char * hash = (char *)a;
    struct entry * elem = (struct entry *)b;
    return strcmp(hash, (*elem).hash);
}


off_t file_length (char *filename) {
    struct stat info;
    if (stat(filename, &info) == -1) return -1;
    return info.st_size;
}

struct entry *read_dictionary(char *filename, int *size)
{
    FILE *c = fopen(filename, "r");
    if (!c) {
        exit(1);
    }
    int length = file_length(filename);
    printf("characters: %d\n", length);
    
    char * contents = malloc(length);
    fread(contents, 1, length, c);
    fclose(c);
    
    *size = 0;
    for ( int i = 0; i < length; i++) {
        if (contents[i] == '\n'){
            contents[i] = '\0';
            *size = *size + 1;
        }
    }
    printf("passwords: %d\n", *size);
    
    int count = 0;
    struct entry * entries = malloc (*size * sizeof(struct entry));
    strcpy(entries[0].password, contents);
    char * hash = md5(entries[count].password, strlen(entries[count].password));
    strcpy (entries[count].hash, hash);
    free(hash);
    count = 1;
    
    for (int i = 1; i < length - 1; i++) {
        if (*(contents + i) == '\0') {
            strcpy(entries[count].password, contents + i + 1);
            hash = md5(entries[count].password, strlen(entries[count].password));
            strcpy (entries[count].hash, hash);
            free(hash);
            count = count + 1;
        }
    }
    
    printf("hashes: %d\n", count);
    
    free (contents);
    
    return entries;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }
    int dlen;
    struct entry *dict = read_dictionary(argv[2], &dlen);
    
    qsort(dict, dlen, sizeof(struct entry), qcomp);

    FILE * hashes = fopen(argv[1], "r");
    if (!hashes) {
        exit(1);
    }

    for (int i = 0; i < dlen; i++) {
        //printf ("Password: %s | Hash: %s\n", dict[i].password, dict[i].hash);
    }
    char hash[HASH_LEN];
    int temp = 0;
    while (fgets(hash, HASH_LEN + 1, hashes) != NULL) {
        hash[32] = '\0';
        //printf ("%d: %s\n", temp, hash);
        struct entry * found = bsearch (hash, dict, dlen, sizeof(struct entry), bcomp);
        if (found == NULL) continue;
        printf ("Hash: %s | Password: %s\n", (*found).hash, (*found).password);
        temp++;
    }
    printf ("Found %d passwords.\n", temp);
    fclose(hashes);
    free(dict);
}
