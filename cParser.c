#include <stdio.h>

int main()
{
  float perTick;
  int hours;
  int answer = 3600;
  float delay = 1;
  int stat;
  
  printf("Amount gained per tick: ");
  scanf("%f", &perTick);
  
  printf("\nHours afk: ");
  scanf("%d", &hours);
  
  printf("\n1-ps\n2-bt\n3-fs\n");
  scanf("%d", &stat);
  
  switch (stat)
  {
    case 1:
      delay = 1.5;
      break;
    case 2:
      delay = 1.25;
      break;
    default:
      delay = 1;
  }
  
  answer = answer * delay * perTick * hours;
  
  printf("\nYou will get %d", answer);
  printf(" over your afk session of %d", hours);
  printf(" hours.\n");
  return 0;
}
