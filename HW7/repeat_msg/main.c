// repeattest.c:

#include <stdio.h>

extern repeat(unsigned int msg_id, unsigned int num_repetitions);

int main()
{
  repeat(0, 4);
  repeat(1, 6);
}
