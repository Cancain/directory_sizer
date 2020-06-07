#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include "DirectoryHandler.h"
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <math.h>
#include <string.h>

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

std::string DirectoryHandler::human_readable_size(double bytes) const{
  std::string affix {};
  double size {};

  if(bytes < 1000) {
    size = bytes;
    affix = "bytes";
  }

  if(bytes > 1000){
    size = bytes / 1000;
    affix = "kb";
  }

  if(bytes > 10000){
    size = bytes / pow(1000, 2);

  }

  return std::to_string(size) + " " + affix;
}

void DirectoryHandler::list_dirs() const{
  for (const File file : _files){
    std::string size = human_readable_size(file.size);

    std::cout << file.name << " : " << size << std::endl;
  }
}

