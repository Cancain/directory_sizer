#include <stdio.h>
#include <iostream>
#include "DirectoryHandler.h"

int main(int argc, char *argv[]){
  DirectoryHandler dirHandler;
  dirHandler.find_folders(argc, argv[1]);

  dirHandler.list_dirs();
  return 0;
}
