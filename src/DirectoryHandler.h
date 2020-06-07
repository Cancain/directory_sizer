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
    std::string get_current_dir();
    std::vector<File> _files;
    std::string _root;
    std::string human_readable_size(double bytes) const;

  public:
    void find_folders(const int argc, const char *path);
    void list_dirs() const;
};

#endif
