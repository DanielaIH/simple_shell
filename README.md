# 0x16. C - Simple Shell
> This repository contains a simple command line interpreter based on Unix Shell.

## What is Unix Shell?
> A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language and is used by the operating system to control the execution of the system using shell scripts. Wikipedia.

> Shell is an environment in which we can run some commands, programs, and shell scripts.  Each operating system has a different shell with slightly (sometimes very) different functionalities and set of commands and functions.

## How does a Unix Shell work?
> The prompt, ($), which is called the command prompt, is issued by the shell. While the prompt is displayed, you can type a command.

> Shell reads your input after you press Enter. It determines the command you want executed by looking at the first word of your input. The first word refers to command or executable file, while the rest of words means the program arguments. Shell takes the input and separates the words (taking account the spaces and tabs like delimeters) into tokens. After executes the program, Shell shows again the prompt and wait for another input.

> If you want to know the detailed process behind Shell, you can visit our blog.

>[This is an external link to Medium blog] (https://medium.com/@4427/what-happens-when-you-type-ls-l-c-in-a-shell-c4d337dc451d)

## What is the purpose of this repository?
> This repository is mainly for learning about how a Shell works internally when we entered a command. It has a purely academic purpose, so we invite you to review this repository for a practical purpose.

## How this project works?
> Below is shown the general workflow for this project.

<img src="https://github.com/DanielaIH/simple_shell/blob/466a9865316e0a0feceaaa78dcf585539bf4194b/workflow.jpg" alt="My image"/>

| Activity  | Used function | Manual link |
| ------------- | ------------- | ------------- |
| Know is in an interactive way	| isatty	| (man 3 isatty) |
| Print the prompt	| write	| (man 2 write) |
| Read the line	| getline	| (man 3 getline) |
| Split the line (string) in tokens	 | strtok | (man 3 strtok) |
| Compare two strings | _strcmp (own fn based on strcmp) |
| Search a valid executable file	 | stat 	| (man 2 stat) |
| Create a new process to execute a secondary instruction | fork  | (man 2 fork) |
| Wait the child process end  | wait  | (man 2 wait) |
| Execute a program  | execv  | (man 2 execve) |
| Allocate memory  | malloc  | (man 3 malloc) |
| Free memory  | free  | (man 3 free) |
| Concatenate two strings | _strcat (own fn based on strcat) |	
| Copy a string	| _strcpy (own fn based on strcpy) |
| Exit from interactive program | exit  | (man 3 exit) |
| Print the error message | perror | (man 3 perror) |

## How can you report an error or solve a question?
> You can contact to authors sending a message through github accounts or an email to Daniela Ibarra <4427@holbertonschool.com> Sebastian Carvajal <sevajal@yahoo.com>
