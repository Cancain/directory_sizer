#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include "DirectoryHandler.h"

void DirectoryHandler::find_folders(int argc, char *path[]){
  struct dirent *entry = nullptr;
  DIR *dir = nullptr;

  dir = opendir(argc > 1 ? path[1] : "/");

  if(dir != nullptr) {
    while((entry = readdir(dir))){
      _folders.push_back(entry->d_name);
    }
  }

  closedir(dir);
}

void DirectoryHandler::list_dirs() const{
  for (const std::string dirname : _folders){
    std::cout << dirname << std::endl;
  }
}

