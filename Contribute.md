# Contribution

Everyone who wants to contribute is free to do it, pull requests are accepted as long as the following requirements are met.

----

### Commit messages

- Stick to [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/) specifications. 

- Don't use capitalization in the Summary, leave out the period and write it in this form: <br>
`<type>: <description>` | i.e. `new: add bubblesort`

- Use imperative mood.

- Limit the Summary at 50 characters and write the Body in paragraphs wrapped at 72 characters.

- Useful links: <br>
[How to write a commit message](https://cbea.ms/git-commit/) <br>
[Commit messages, TheOdinProject](https://www.theodinproject.com/lessons/foundations-commit-messages)


### Code style

- Ensure modular structure, each algorithm resides in its own file; helper code, such as data structures or utilities, should be placed in dedicated files and included via header files.

- Indent code using 4 spaces.

- Wrap lines at 85 characters.

- Place pointers' asterisk (*) next to the name of the variable, not the type: <br>`<type> *<varname>` | i.e. `int *p`

- Use spaces around operators. <br>
Add spaces in control structures after the keyword. <br>
Divide logical sections with a blank line within functions. <br>
Separate function definitions and global declarations with 2 blank lines.

- Simplify single-line statements when readability is mantained.

- Start comments with a space and capitalize the first word; don't end them with a period.

- Follow already existing code's style to preserve consistency and uniformity.

<br>

Example:
```
#include <stdio.h>

int sum(int x, int y) {
    return x + y;
}


int main(void) {
    int a = 2;
    int b = 4;
    int c;

    c = sum(a, b);

    if (c < 5) {
        printf("C is less than 5.\n");
    } else {
        printf("C is greater than or equal to 5.\n");
    }

    return 0;
}
```
