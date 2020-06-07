#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include "DirectoryHandler.h"

void DirectoryHandler::find_folders(const char *path){
  struct dirent *entry = nullptr;
  DIR *dir = nullptr;

  dir = opendir(path);

  if(dir != nullptr) {
    while((entry = readdir(dir))){
      _directories.push_back(entry->d_name);
    }
  }

  closedir(dir);
}

void DirectoryHandler::list_dirs() const{
  for (const std::string dirname : _directories){
    std::cout << dirname << std::endl;
  }
}

