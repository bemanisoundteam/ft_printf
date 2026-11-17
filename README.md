_This activity has been created as part of the 42 curriculum by ccabanne._

# Description
ft\_printf is a single-file pure C89 re-implementation of C Standard Library's printf.
It supports the following format specifiers :
- %c: Prints a single char
- %s: Prints a null terminated string
- %p: Prints a pointer in lowercase hexadecimal, prefixed by "0x"
- %d or %i: Prints an integer in decimal
- %u: Prints an unsigned integer in decimal
- %x: Prints an unsigned integer in lowercase hexadecimal
- %X: Prints an unsigned integer in uppercase hexadecimal
- %%: Prints a % char (similar to an escape character)

# Instructions
To compile this library, simply run `make`.
The Makefile supplies the following rules to cleanup or (re)compile :
- `all` (default rule): makes libftprintf.a
- `libftprintf.a`: compiles libft, then compiles each source file.
The resulting object files are then bundled into the libftprintf.a archive.
- `clean`: deletes each individual object file
- `fclean`: runs the `clean` rule then deletes libftprintf.a
- `re`: runs `fclean` then `all`

To use this library you can simply change your compile command to link to libftprintf.a  
Such as :
- `cc main.c libftprintf.a`
- `cc -L $LIBFTPRINTF_PATH main.c -lftprintf`

# Resources
This assignment was quite straightforward.
Format specifiers are defined as described above, and tested against glibc's printf on a Fedora 44 system.
No AI was used in this project.

The assignment requires detailing and justifying "the choosen algorithm and datastructure".  
No datastructure was used (except va\_list, which is an opaque structure),
and only a simple [iterative integer to string algorithm](libft/ft_uimtoa_base.c) is worth mentioning here.  
Whilst more advanced implementations make use of parsing algorithms, unions and/or jump tables.
This one only features reading a single character as a specifier,
then calling the appropriate function with the appropriate parameters.
