#include <stdio.h>
#include <string.h>

float add();
float subtract();
float multiply();
float divide();
int square();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage:\n ./calculator (add/subtract/multiply/divide/square)\n");
        return 1;
    }
    if (strcmp(argv[1], "add") == 0)
    {
      printf("Result: %f\n", add());
    }
    else if (strcmp(argv[1], "subtract") == 0)
    {
      printf("Result: %f\n", subtract());
    }
    else if (strcmp(argv[1], "multiply") == 0)
    {
      printf("Result: %f\n", multiply());
    }
    else if (strcmp(argv[1], "divide") == 0)
    {
      printf("Result: %f\n", divide());
    }
    else if (strcmp(argv[1], "square") == 0)
    {
      printf("Result: %i\n", square());
    }
    else
    {
      printf("Wrong input\n");
      return 1;
    }
    return 0;
}

float add()
{
  int x, y;
  printf("x: ");
  scanf("%i", &x);
  printf("y: ");
  scanf("%i", &y);
  return (float)x + y;
}

float subtract()
{
  int x, y;
  printf("x: ");
  scanf("%i", &x);
  printf("y: ");
  scanf("%i", &y);
  return (float)x - y;
}

float multiply()
{
  int x, y;
  printf("x: ");
  scanf("%i", &x);
  printf("y: ");
  scanf("%i", &y);
  return (float)x * y;
}

float divide()
{
  int x, y;
  printf("x: ");
  scanf("%i", &x);
  printf("y: ");
  scanf("%i", &y);
  return (float)x / y;
}

int square()
{
  int x;
  printf("x: ");
  scanf("%i", &x);
  return x * x;
}

