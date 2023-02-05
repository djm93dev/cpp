#include <iostream>

// nested for loop
int nested_for_loop() 
{
  for (int i = 0; i < 5; i++) 
    {
    for (int j = 0; j < 5; j++) 
      {
      std::cout << i << " " << j << std::endl;
      }
    }
  return 0;
}

// nested while loop
int nested_while_loop() 
{
  int i = 0;
  while (i < 5) 
    {
    int j = 0;
    while (j < 5) 
      {
      std::cout << i << " " << j << std::endl;
      j++;
      }
    i++;
    }
  return 0;
}

// nested do while loop

int nested_do_while_loop() 
{
  int i = 0;
  do 
    {
    int j = 0;
    do 
      {
      std::cout << i << " " << j << std::endl;
      j++;
      } while (j < 5);
    i++;
    } while (i < 5);
  return 0;
}

int main() 
{
  nested_for_loop();
  nested_while_loop();
  nested_do_while_loop();
  return 0;
}