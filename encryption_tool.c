#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool valid(char *key);
char crypt(char c, char *key);
char decrypt(char c, char *key);

int main(int argc, char *argv[])
{
    // check if there are errors with cml arguments
    if (argc != 4)
    {
        printf("Usage: ./enryption_tool [flag] INFILE.txt KEY.txt\n");
        return 1;
    }
    if (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0) 
    {
        printf("Invalid flag. Use either -e (encrypt) or -d (decrypt)\n");
        return 1;
    }
    // try to open file
    FILE *infile = fopen(argv[2], "r");
    if (infile == NULL)
    {
        printf("Couldn't open %s\n", argv[2]);
        return 2;
    }
    // store the text
    char *buffer = NULL;
    int length = 0;

    // get the length of the file
    fseek(infile, 0, SEEK_END);
    length = ftell(infile);
    rewind(infile);

    buffer = malloc(length + 1);
    if (buffer == NULL)
    {
        printf("Couldn't afford memory for buffer\n");
        return 3;
    }
    fread(buffer, 1, length, infile);
    buffer[length] = '\0';

    // encrypt it / decrypt it
    // open the key.txt
    FILE *key_file = fopen(argv[3], "r");
    if (key_file == NULL)
    {
        printf("Could't open the key file: %s\n", argv[3]);
        return 2;
    }
    // store the key
    char *key = NULL;
    long key_length = 0;

    // get the length of the file
    fseek(key_file, 0, SEEK_END);
    key_length = ftell(key_file);
    rewind(key_file);

    key = malloc(key_length + 1);
    if (key == NULL)
    {
        printf("Couldn't afford memory for key\n");
        return 3;
    }
    fread(key, 1, key_length, key_file);
    key[key_length] = '\0';
    // check for errors if the key is valid
    if (!valid(key))
    {
        printf("Key is not valid, length should be 26 and no repeating characters\n");
        return 4;
    }
    // subtitute each character
    // loop over each character
    for (int i = 0; i < length; i++)
    {
        // check if its alpha, lower of upper case
        if (isalpha(buffer[i]))
            if (strcmp(argv[1], "-e") == 0)
                buffer[i] = crypt(buffer[i], key);
            else
                buffer[i] = decrypt(buffer[i], key);
    }

    // close file
    fclose(infile);

    // open the file in write mode
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        printf("Couldn't open %s\n", argv[2]);
        return 2;
    }
    fwrite(buffer, 1, length, outfile);

    // close file
    fclose(outfile);
    fclose(key_file);

    // free memory
    free(buffer);
    free(key);

    printf("Should be succesful!\n");
    return 0;
}

bool valid(char *key)
{
    // get length
    int length = strlen(key);
    // check iflength is valid
    if (length != 26)
        return false;

    // check if its all alpha chars
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
            return false;
    }

    // check if there are no repeating characters
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
                return false;
        }
    }
    // return true by default
    return true;
}

char crypt(char c, char *key)
{
    // check for upper
    if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    // check for lower
    else
    {
        return tolower(key[c - 'a']);
    }
}

char decrypt(char c, char *key)
{
    int n = strlen(key);
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (tolower(c) == tolower(key[i]))
            idx = i;
    }
    // check for upper
    if (isupper(c))
    {
        // find location in the key array(string) and add 65
        return idx + 'A';
    }
    // check for lower
    else
    {
        // find location in the key array(string) and add 97
        return idx + 'a';
    }
}
// pseudo code

// check the cml arg, [v]
// open file in read mode [v]
// store the text [v]
// encrypt it / decrypt it
// open the key.txt
// check for errors
// subtitute each character
// check if its alpha, lower of upper case
// close the file
// open the file in write mode
// change the file
// close the file