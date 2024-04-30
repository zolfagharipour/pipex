# Pipex

The "Pipex" project is designed to simulate the behavior of shell command pipelines using redirections. Your program will take file names and commands as arguments and execute them in a pipeline manner, similarly to shell command pipelines.

## Warning for 42 Students

This repository is intended as a reference and educational tool. **42 students are strongly advised not to copy this code without fully understanding its functionality.** Plagiarism in any form is against 42's principles and could lead to serious academic consequences. Use this repository responsibly to learn and better understand how to implement similar functionalities on your own.

## Project Overview

`./pipex` is executed with the following format:

+++
./pipex file1 cmd1 cmd2 file2
+++

It takes four arguments:
- `file1` and `file2` are file names.
- `cmd1` and `cmd2` are shell commands with their parameters.

The behavior of `pipex` should mimic the following shell command:
+++
< file1 cmd1 | cmd2 > file2
+++

### Examples

+++
./pipex infile "ls -l" "wc -l" outfile
# This should behave like: < infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
# This should behave like: < infile grep a1 | wc -w > outfile
+++

## Requirements

- A Makefile that compiles the source files without relinking.
- Thorough error handling. The program must not terminate unexpectedly due to errors like segmentation faults, bus errors, double frees, etc.
- No memory leaks are allowed.
- Errors should be handled similarly to shell commands (e.g., `< file1 cmd1 | cmd2 > file2`).

## Compilation

+++
git clone https://github.com/yourusername/pipex.git
cd pipex
make
+++

## Usage

Standard operation:
+++
./pipex file1 "command1" "command2" file2
+++

### Bonus Features

1. **Handling Multiple Pipes:**
   - Command format: `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
   - Example:
     ```
     ./pipex infile "grep a1" "sort" "uniq -c" "wc -l" outfile
     # Behaves like: < infile grep a1 | sort | uniq -c | wc -l > outfile
     ```

2. **Support for Here Document:**
   - Command format when the first parameter is "here_doc":
     ```
     ./pipex here_doc LIMITER cmd cmd1 file
     +++
   - Example:
     ```
     ./pipex here_doc END "grep a1" "wc -w" outfile
     # Behaves like: grep a1 << END | wc -w >> outfile
     ```

## Error Handling

The program displays appropriate error messages and exits under error conditions like missing files, invalid commands, or permissions issues.
