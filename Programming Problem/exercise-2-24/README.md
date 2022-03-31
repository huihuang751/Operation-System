# Operation System
## Programming Problems 2.24
In Sec.2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the *Windows or POSIX API*.
- Be sure to include all necessary error checking, including ensuring that the source file exists.
- Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls.
## Workflow
![](https://i.imgur.com/5hrlGJK.png)
1. First print: Copying from source file (test.txt) to detination file (copy_test.txt).
2. Check if source file exist.
    i. If not exist, then program close.
    ii. If exist, then program keep going.
3. Check if detination file exist.
    i. If not exist, then create destination file.
    ii. If exist, then program keep going.
4. Copying the content from source file to detination file.
5. Finish program.
## Result
### Execution
First, destination file (copy_test.txt) does not exist, so the program automatically create it.
![](https://i.imgur.com/UHekcV9.png)
## dtruss
Here are the dtruss results.
![](https://i.imgur.com/Cm8jNtX.png)
![](https://i.imgur.com/QPEy624.png)
Further using -e to show the content
![](https://i.imgur.com/pPg8Ggp.jpg)
![](https://i.imgur.com/GFyHvVu.jpg)





