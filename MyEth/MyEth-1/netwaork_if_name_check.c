#include <stdio.h>
#include <string.h>
#include <net/if.h>

int main()
{
  int index;
  char buf[128];
  char input[32];

  scanf("%s", input);
  printf("%s\n",input);
  index = if_nametoindex(input);
  if (index == 0) {
    perror("if_nametoindex");
    return 1;
  }

  printf("index : %d\n", index);

  memset(buf, 0, sizeof(buf));
  if (if_indextoname(index, buf) == NULL) {
    perror("if_indextoname");
    return 1;
  }

  printf("name : %s\n", buf);

  return 0;
}

