#include <fcntl.h> //for open()
#include <unistd.h> //For close() and read()
#include <stdlib.h>


// create_matrix
int		**create_int_matrix(int rows, int cols);
char	**create_char_matrix(int rows, int cols);

// reading a file, returns long str
char *read_file(const char *filename);

// string manipulatoin
int my_strlen(const char *str);
