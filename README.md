Simple Shell
---
In this project we write a simple unix command interpreter called **hsh** from scratch as part of the ALX Software Engineering program curriculum which took place in June 2022.

#File Descriptions
---
- [AUTHORS](https://github.com/rmm1001/simple_shell/blob/master/AUTHORS):	contains the names of the individuals who contributed to this repository.
- [command\_window.c](https://github.com/rmm1001/simple_shell/blob/master/command_window.c)	is responsible for displaying the command prompt for user to input a command.
- [directory\_navigation.c](https://github.com/rmm1001/simple_shell/blob/master/directory_navigation.c)	contains functions which are responsible for navigating from one directory to another.
- [executing.c](https://github.com/rmm1001/simple_shell/blob/master/executing.c)	contains the funtions which tokenizes strings and also handles the execution of input file.
- [history.c](https://github.com/rmm1001/simple_shell/blob/master/history.c)	records all the user input commands and store them in a file.
- [hsh\_environment.c](https://github.com/rmm1001/simple_shell/blob/master/hsh_environment.c)	handles the setting and the unseting of the hsh environment
- [logout\_of\_hsh.c](https://github.com/rmm1001/simple_shell/blob/master/logout_of_hsh.c)	has funtions that ignore spaces before commands, and handle the exiting of **hsh**.
- [man\_1\_simple\_shell](https://github.com/rmm1001/simple_shell/blob/master/man_1_simple_shell)	is the manual page of **hsh** on how it works.
- [parser.c](https://github.com/rmm1001/simple_shell/blob/master/parser.c)	has a function that parses the bultin programs.
- [path\_finder.c](https://github.com/rmm1001/simple_shell/blob/master/path_finder.c)	contains functions for getting the path of the command, the retrieval of the enviroment, and return the complete path of a command.
- [printing.c](https://github.com/rmm1001/simple_shell/blob/master/printing.c)	has function like `putchar()` and `puts()` which are useful in printing characters and strings.
- [re\_alloc.c](https://github.com/rmm1001/simple_shell/blob/master/re_alloc.c)	reallocates memory in the program.
- [reading.c](https://github.com/rmm1001/simple_shell/blob/master/reading.c)	reads characters in the **hsh** standard input.
- [README.md](https://github.com/rmm1001/simple_shell/blob/master/README.md)	is the file you are reading right now.
- [shell.h](https://github.com/rmm1001/simple_shell/blob/master/shell.h)	is the header file containing all the prototypes of the functions used in this project.
- [string\_manipulation.c](https://github.com/rmm1001/simple_shell/blob/master/string_manipulation.c)	contains all the functions which are used in this program for manipulating strings.

All these files are compiled using the command
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`


##hsh usage
To install **hsh** on your `UNIX system`:
1. Run the `git clone https://github.com/rmm1001/simple_shell.git` command.
2. Navigate into the repo with the command `cd simple_shell`.
3. Compile all the files with the afore mentiions command (`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`).
4. Run the command `./hsh` to use **hsh** in interactive mode.

Consulted Resourses
---
- [UNIX shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Everything you need to know to start coding your own shell](https://alx-intranet.hbtn.io/concepts/64)

Authors
---
1. [Katlego Machethe](https://github.com/KatlegoMachethe)
2. [Reshoketswe Mashabela](https://github.com/rmm1001)

