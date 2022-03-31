//
//  main.c
//  EX_2-15
//
//  Created by 黃慧 on 2022/3/21.
//  Create a copy program to trace for OS homework1, exercise 2.15

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <unistd.h>

int main()
{
    FILE *fptr1, *fptr2, *file;
    char c;
    char src_file[20] = "test.txt";
    char des_file[20] = "copy_test.txt";
    
    printf("This program will copy the content of source file: %s to destination file: %s\n", src_file, des_file);
    
    // Check if source file exist
    fptr1 = fopen(src_file, "r");
    if (fptr1)
    {
        printf("Source file %s exist \n", src_file);
    }
    else
    {
        printf("Source file %s does not exist.\n", src_file);
        printf("Program close.\n");
        return 0;
    }
    
    // Check if destination file exist
    file = fopen(des_file, "r");
    if (file)
    {
        printf("Destination file %s exist\n", des_file);
    }
    else
    {
        printf("Destination file %s does not exist\n", des_file);
        printf("Automatically creating destination file %s\n", des_file);
    }
    fptr2 = fopen(des_file, "w");
    //  Open source file and copy the content to destination file
    printf("Openning source file: %s\n", src_file);
    printf("Writing content from %s to %s \n",src_file, des_file);
    
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    
    // Complete copying the content
    printf("Contents copied to %s\n", des_file);
  
    // Close files
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
