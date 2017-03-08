#include "draw.h"

// Print all 'things' in the file name array
void print_all_values_in_filear(void) {
    consoleSelect(&debugscreen);

    int max_files_to_print;

    if (size_of_file_array < MAX_FILES_ON_SCREEN) { max_files_to_print = size_of_file_array; }
    else { max_files_to_print = MAX_FILES_ON_SCREEN; }

    consoleInit(GFX_TOP, &topScreen);
    consoleSelect(&topScreen);

    if (max_files_to_print > 0) {
        if (scroll > 0) { printf("/\\\n"); } // Print up arrow showing you can scroll up
        else { printf("\n"); }               // Keep all the files in the same place on screen

        int i;
        for (i=0; i<max_files_to_print; i++) {

            // If it is a dir
            if (!isfile_arr[i+scroll]) {
                // print as white text on black background
                if (i == selected) { printf("\n <dir>  | \x1b[47;30m%s\x1b[0m", file_arr[i+scroll]); }
                // Else, just print it without arrow
                else { printf("\n <dir>  | %s", file_arr[i+scroll]); }
            }

            else {
                if (i == selected) { printf("\n <file> | \x1b[47;30m%s\x1b[0m", file_arr[i+scroll]); }
                else { printf("\n <file> | %s", file_arr[i+scroll]); }
            }
        }
        // If there are files below on screen
        if ( (size_of_file_array > MAX_FILES_ON_SCREEN) && (scroll == 0) ) { printf("\n\n\\/ "); }
    }
    else { printf("\n\n\t\t\x1b[47;30m- Folder is empty -\x1b[0m"); }
}