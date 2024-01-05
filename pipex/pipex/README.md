# pipex

C program to emulate a unix mechanism called pipe . The program uses fork() and pipe() features of C language to demonstrate multiple process creation and inter-process communication. The program also handles here_doc, input redirection and output redirection operators to read from standard input, to read from an input file descriptor and to write to an output file descriptor respectively.

![MS Paint _ Microsoft Paint Online](https://user-images.githubusercontent.com/66158938/201291242-4cfaf0b3-197a-46e5-824e-d0f7285c20ea.png)

<img width="562" alt="Screen Shot 2022-11-12 at 10 38 26 AM" src="https://user-images.githubusercontent.com/66158938/201461163-36e97c78-62bf-48c4-9ed3-d89e9546f6d1.png">


MANDATORY PART
--------------
The program will be executed as follows: 
./pipex file1 cmd1 cmd2 file2

It must take 4 arguments:
• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.

## Examples

$> ./pipex infile "ls -l" "wc -l" outfile

Should behave like: < infile ls -l | wc -l > outfile 

$> ./pipex infile "grep a1" "wc -w" outfile

Should behave like: < infile grep a1 | wc -w > outfile




BONUS PART
----------

Handle input/output redirection operators and here_doc

## Examples

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Should behave like: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

$> ./pipex here_doc LIMITER cmd cmd1 file

Should behave like: cmd << LIMITER | cmd1 >> file


<img width="63" alt="image" src="https://user-images.githubusercontent.com/66158938/200158152-036c79ef-eb80-4658-8aab-9d3519bc6540.png">

### References:
https://www.rozmichelle.com/pipes-forks-dups/
Code vault youtube channel: Unix processes in C


