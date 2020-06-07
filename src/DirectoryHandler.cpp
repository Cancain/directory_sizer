#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include "DirectoryHandler.h"
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <math.h>

std::string DirectoryHandler::get_current_dir(){
  char buff[FILENAME_MAX];

  getcwd(buff, FILENAME_MAX);
  std::string current_working_dir(buff);
  return current_working_dir;
}

void DirectoryHandler::find_folders(const int argc, const char *path){
  struct stat file_stats;
  struct dirent *entry {nullptr};
  DIR *dir {nullptr};
  std::string cwd = get_current_dir();
  dir = opendir(argc > 1 ? path : cwd.c_str());

  if(dir != nullptr) {
    while((entry = readdir(dir))){
      File newFile;
      if(!stat(entry->d_name, &file_stats)){
            newFile.size = (double)file_stats.st_size;
        }
      newFile.name = entry->d_name;
      _files.push_back(newFile);
    }
  }

  closedir(dir);
}

void DirectoryHandler::list_dirs() const{
  for (const File file : _files){

    std::cout << file.name << " : " << file.size << std::endl;
  }
}

