# Minitalk

## Project Structure
```
.
├── Makefile
├── all_libft
│   ├── Makefile
│   ├── include
│   │   ├── ft_printf.h
│   │   ├── get_next_line_bonus.h
│   │   └── libft.h
│   └── src
│       ├── ft_printf
│       │   ├── ft_print_char.c
│       │   ├── ft_print_hex.c
│       │   ├── ft_print_integer.c
│       │   ├── ft_print_pointer.c
│       │   ├── ft_print_string.c
│       │   ├── ft_print_unsigned.c
│       │   └── ft_printf.c
│       ├── gnl
│       │   ├── get_next_line_bonus.c
│       │   └── get_next_line_utils_bonus.c
│       └── libft
│           ├── bool_atoi.c
│           ├── error_handler.c
│           ├── ft_atoi.c
│           ├── ft_bzero.c
│           ├── ft_calloc.c
│           ├── ft_isalnum.c
│           ├── ft_isalpha.c
│           ├── ft_isascii.c
│           ├── ft_isdigit.c
│           ├── ft_isprint.c
│           ├── ft_isspace.c
│           ├── ft_itoa.c
│           ├── ft_lstadd_back.c
│           ├── ft_lstadd_front.c
│           ├── ft_lstclear.c
│           ├── ft_lstdelone.c
│           ├── ft_lstiter.c
│           ├── ft_lstlast.c
│           ├── ft_lstmap.c
│           ├── ft_lstnew.c
│           ├── ft_lstsize.c
│           ├── ft_memchr.c
│           ├── ft_memcmp.c
│           ├── ft_memcpy.c
│           ├── ft_memmove.c
│           ├── ft_memset.c
│           ├── ft_putchar_fd.c
│           ├── ft_putendl_fd.c
│           ├── ft_putnbr_fd.c
│           ├── ft_putstr_fd.c
│           ├── ft_split.c
│           ├── ft_strchr.c
│           ├── ft_strdup.c
│           ├── ft_striteri.c
│           ├── ft_strjoin.c
│           ├── ft_strlcat.c
│           ├── ft_strlcpy.c
│           ├── ft_strlen.c
│           ├── ft_strmapi.c
│           ├── ft_strncmp.c
│           ├── ft_strnstr.c
│           ├── ft_strrchr.c
│           ├── ft_strtrim.c
│           ├── ft_substr.c
│           ├── ft_tolower.c
│           └── ft_toupper.c
├── include
│   ├── minitalk.h
│   └── minitalk_bonus.h
└── src
    ├── client.c
    ├── client_bonus.c
    ├── server.c
    └── server_bonus.c

8 directories, 66 files
```

## Build and Clean Commands
### Build
- Build all: `make`
- Build with bonus: `make bonus`

### Clean
- Remove intermediate files: `make clean`
- Complete cleanup: `make fclean`

### Rebuild
- Rebuild everything: `make re`

---

## Key Concepts and Commands

### Commands
- **`kill`**: Sends a signal to a specified process.
- **`error_handler`**: Handles errors and displays messages within the program.
- **`usleep`**: Pauses program execution for a specified time in microseconds.
- **`getpid`**: Retrieves the process ID (PID) of the current process.
- **`sigemptyset`**: Initializes a signal mask (signal set) to be empty.
- **`sigaddset`**: Adds a specific signal to the signal mask.
- **`sigaction`**: Sets up a handler for specific signals.
- **`pause`**: Suspends the program until a signal is received.

### Terminology
- **PID**: A unique identifier assigned to each process by the operating system.
- **Signal**: A mechanism used in UNIX/Linux environments for inter-process communication or to notify a process about an event. Signals act as software interrupts.
- **System Call**: An interface through which user programs request services from the operating system kernel. Examples include file operations, process management, and network communication.
- **Signal Mask**: A mechanism to temporarily block specific signals from being delivered to a process.

---

## Notes
### Signals
Signals are a form of software interrupt in UNIX/Linux used for process communication or system notifications. For example, a signal can notify a process that a child process has terminated or that an error occurred.

### System Calls
System calls provide an interface for user-level programs to request OS kernel services, such as accessing files, managing processes, or performing I/O operations.

### Signal Mask
Signal masks are used to block specific signals temporarily, ensuring critical sections of code execute without interruptions.

---

## Questions
### Client Code
```c
if ((c & (1 << bit)) != 0):
```
- Question: What is the purpose of this condition in checking the bits of a character?

### Server Code
```c
c |= (1 << bit);
```
- Question: How does this line reconstruct the character from received signal bits?

---

Feel free to contribute to or ask questions about the project!

