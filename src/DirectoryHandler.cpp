#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include "DirectoryHandler.h"
#include <unistd.h>
#include <limits.h>

std::string DirectoryHandler::get_current_dir(){
  char buff[FILENAME_MAX];

  getcwd(buff, FILENAME_MAX);
  std::string current_working_dir(buff);
  return current_working_dir;
}

void DirectoryHandler::find_folders(const int argc, const char *path){
  struct dirent *entry = nullptr;
  DIR *dir = nullptr;
  std::string cwd = get_current_dir();
  dir = opendir(argc > 1 ? path : cwd.c_str() );

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

