#include <stdio.h>
#include <iostream>
#include "DirectoryHandler.h"

int main(int argc, char *argv[]){
  std::cout << argc << std::endl;
  DirectoryHandler dirHandler;

  dirHandler.find_folders(argc, argv);
  return 0;
}
