#ifndef _DIRECTORY_HANDLER_H_
#define _DIRECTORY_HANDLER_H_

#include <string>
#include <vector>

struct File {
  std::string name;
  double size;
};

class DirectoryHandler{
  private:
    std::vector<File> _files;
    std::string _root;

  public:
    void find_folders(const int argc, const char *path);
    void list_dirs() const;
    std::string get_current_dir();
};

#endif
