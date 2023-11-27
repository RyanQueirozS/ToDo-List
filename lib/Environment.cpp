#include <iostream>
#include <libconfig.h++>
#include <string>

#include "Commands.hpp"
#include "Environment.hpp"

std::string getTaskPathFromConfigFile() {
  libconfig::Config cfg;
  try {
    cfg.readFile(getCurrentExecutablePath() + "/doc/config.cfg");
  } catch (const libconfig::FileIOException &fioex) {
    std::cout << "I/O error while reading file.\n";
    return "ERROR!";
  } catch (const libconfig::ParseException &pex) {
    std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << '\n';
    return "ERROR!";
  }
  try {
    std::string path = cfg.lookup("task_path");
    return path + '/';
  } catch (const libconfig::SettingNotFoundException &nfex) {
    std::cerr << "No 'Task Path' setting in configuration file.\n";
    return "ERROR!";
  }
}
