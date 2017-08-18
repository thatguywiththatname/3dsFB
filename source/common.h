#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>  // Basic functions
#include <stdlib.h> // malloc and free
#include <string.h> // String manipulation
#include <3ds.h>    // Main 3ds lib (libctru)
#include <dirent.h> // For opendir() and readdir()
#include <unistd.h> // rmdir()
#include "colours.h" // Console colours

#define MAX_DIR_NAME_SIZE 261
#define MAX_FILES_ON_SCREEN 26
#define MAX_PATH_SIZE 511

extern char current_path[511]; // Contains current path
extern int selected;           // Selected file index
extern int scroll;             // Used to offset what is printed from the file array, to allow "scrolling"

extern char **file_arr;        // A pointer to an array which is full of pointers which will point to strings (only way to create a dynamic/resizable array)
extern bool *isfile_arr;       // Same as file_arr, will be used "alongside" file_arr to check whether something is a file or directory
extern int size_of_file_array; // Size of file name array

extern PrintConsole topScreen; // One PrintConsole for each screen
extern PrintConsole instructionscreen;
extern PrintConsole debugscreen;

extern bool quit_for_err; // Closes the main loop if an error happens

// Struct to hold clipboard things in
typedef struct CB {
   char path[511];
   char filename[MAX_DIR_NAME_SIZE];
   int filesize;
} CB;

// For file_arr
typedef struct file_entry {
  char name[MAX_DIR_NAME_SIZE];
  bool isfile;
} file_entry;

#endif