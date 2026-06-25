#include <stdlib.h>
#include <unistd.h>

// This function will allocate a bigamount of memory, that should fail
int main(void)
{
  char  *ptr;
  int   bytes_read;
  size_t size = 100 * 1024 * 1024;

  ptr = malloc(size);
  if (!ptr)
    write(2, "Malloc error\n", 13);
  write(1, "Enter your text\n", 16);
  bytes_read = read(0, ptr, size);
  write(1, "Your text:\n", 11);
  write(1, ptr, 10);
  return (0);
}
