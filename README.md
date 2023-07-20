# Simple Shell Project

This is a simple shell project that:

	* Displays a prompt and waits for user to type a command. 
	* The command line will always end with a new line.
	* The prompt is displayed again each time a command has been executed.
	* Has simple command lines ie, no semi colons, no pipes, redirectins or any other advanced features.
	* Command lines are mase of one word, no arguments will be passsed to programs
	* if an executable cannot be found, an error message is pinted and prompt is displayed again
	* Hanles errors
	* Handles "End of file" condition (CTRl+D)
	

	* Handles command lines with arguments
	* Handles the PATH
	* Does not call fork if the command does not exist
	* Implements exit built in that exits the shell
	* Uses exit
	* IMplements env built-in that prints current environment
	
# All code is in C language
