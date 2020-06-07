#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_

#include <stdio.h>
#include <dirent.h>
#include "DirectoryHandler.h"

void DirectoryHandler::find_folders(int argc, char *path[]){
  struct dirent *entry = nullptr;
  DIR *dir = nullptr;

  dir = opendir(argc > 1 ? path[1] : "/");

  if(dir != nullptr) {
    while((entry = readdir(dir))){
      printf("%s\n", entry->d_name);
    }
  }

  closedir(dir);
}

#endif
