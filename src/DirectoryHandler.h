#include <string>
#include <vector>

class DirectoryHandler{
  private:
    std::vector<std::string> folders;
    std::string root;

  public:
    void find_folders(int argv, char *path[]);
};
