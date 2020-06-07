#include <stdio.h>
#include <iostream>
#include "DirectoryHandler.h"

int main(int argc, char *argv[]){
  DirectoryHandler dirHandler;

  char ROOT = '/';

  dirHandler.find_folders(argc > 1 ? argv[1] : &ROOT);

  dirHandler.list_dirs();
  return 0;
}
