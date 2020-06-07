#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_

#include <string>
#include <vector>

class DirectoryHandler{
  private:
    std::vector<std::string> _directories;
    std::string _root;

  public:
    void find_folders(const char *path);
    void list_dirs() const;
};

#endif
