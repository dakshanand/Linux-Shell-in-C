README
_______________________________________________________
_______________________________________________________

FEATURES SUPPORTED
-------------------------------------------------------
The shell supports cd,pwd,echo and other built in commands.
Errors are handled properly using perror.
Echo command is not the same as in the bash shell.


HOW TO COMPILE
-------------------------------------------------------

to compile run the command:-   make

HOW TO RUN
-------------------------------------------------------
run the command:- ./main
FILES
-------------------------------------------------------
cd.c:- the function to execute cd command

echo.c:- the function to execute echo command
pwd.c:- the function to execute pwd command
split.c:- the function to parse the given string of commands properly
pinfo.c:- the function to execute pinfo command (bonus)
execute.c: executing all commands and distinguishing between builtin and system commands
loop.c:- the main loop
input.c: The function to read the input
launch.c: The function which calls execvp to launch system commands

