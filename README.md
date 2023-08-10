# Simple Shell Projects
# A Project to replicate the Unix Shell system and operations. It is an ALX Project written entirely on C with Michael Omoniyi.

### Compilation
Compile with GCC and flags like: -Wextra -Werror -Wall -pedantic -std=gnu89
Shell should be compiled this way: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Testing
The shell should be tested this way in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

### Built-ins
###### exit[n] - Exit the shell, with optional exit status, n.
###### env - Print the environment
###### setenv[var][value] - Set an environment variable and value.
###### unsetenv[var] - Remove an environment variable.
###### cd [dir] - Change The directory.
###### help [built-in] - Documentation for built-in

### Contributors
(Michael Omoniyi)[https://@github.com/MichaelOmoniyi]
