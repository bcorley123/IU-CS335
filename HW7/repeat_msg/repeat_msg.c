#include <stdio.h>

void repeat_msg(unsigned int msg_id, unsigned int num_repetitions)
{
  int i;
  char *message;

  for (i = 0; i < num_repetitions; i++) {
    if (msg_id == 0)
      message = "zero";
    else
      message = "one";
    puts(message);
  }
}
