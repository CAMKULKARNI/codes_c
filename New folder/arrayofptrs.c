#include <stdio.h>

int main(void) {
    
  // array of pointers
  char *cityPtr[4] = {
    "Chennai",
    "Kolkata",
    "Mumbai",
    "New Delhi"
  };
  
  // temporary variable
  int r, c;
  
  // print cities
  for (r = 0; r < 4; r++) {
    c = 0;//to access individual chars
    while(*(cityPtr[r] + c) != '\0') {
      printf("%s", *(cityPtr[r] + c));
      c++;
    }
    printf("\n");
  }
  
  return 0;
}
