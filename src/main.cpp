#include <stdio.h>
#include <iostream>
#include "DirectoryHandler.h"

int main(int argc, char *argv[]){
  DirectoryHandler dirHandler;
  std::string current_dir = dirHandler.get_current_dir();
  dirHandler.find_folders(argc > 1 ? argv[1] : current_dir.c_str());

  dirHandler.list_dirs();
  return 0;
}
