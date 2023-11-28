#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <libconfig.h++>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Commands.hpp"
#include "Environment.hpp"
#include "Task.hpp"

std::vector<std::string> Tokens;

std::vector<std::string> getUserInput() {
  std::string userInput;
  std::cout << "> ";
  std::getline(std::cin, userInput);
  if (userInput == "") {
    userInput = "null";
    // Needs fixing
  }

  std::stringstream ss(userInput);
  std::istream_iterator<std::string> begin(ss);
  std::istream_iterator<std::string> end;
  std::vector<std::string> tokens(begin, end);

  return tokens;
}

struct outputTemplate {
  void printLine() {
    std::cout << "+";
    for (int i = 0; i < 32; i++) {
      std::cout << "-";
    }
    std::cout << "+\n";
  }

  void printHeader() {
    int actualSize = 32;

    std::cout << "|";
    for (int i = 0; i < actualSize - 5; i++) {
      std::cout << " ";
      if (i == (actualSize - 5) / 2) {
        std::cout << "LABEL";
      }
    }
    std::cout << "|\n";
  }

  void printTask(std::vector<std::array<std::string, 4>> taskVector) {
    int actualSize = 32;
    std::cout << "|"
              << " ID "
              << "|"
              << " Name "
              << "|"
              << " Date "
              << "|"
              << " Description "
              << "|\n";

    for (int i = 0; i < taskVector.size(); i++) {
      printLine();
      for (int j = 0; j < taskVector[i].size(); j++) {
        std::cout << "| ";
        if (j == 0 && taskVector[i][j].size() == 1) {
          std::cout << " ";
        }
        if (j == 1 && taskVector[i][j].size() < 4) {
          for (int k = 0; k < 4 - taskVector[i][j].size(); k++) {
            std::cout << " ";
          }
        }
        if (j == 2 && taskVector[i][j].size() < 4) {
          for (int k = 0; k < 4 - taskVector[i][j].size(); k++) {
            std::cout << " ";
          }
        }
        if (j == 3 && taskVector[i][j].size() < 11) {
          for (int k = 0; k < (11 - taskVector[i][j].size()); k++) {
            std::cout << " ";
          }
        }
        std::cout << taskVector[i][j] << " ";
      }
      std::cout << '|';
      std::cout << '\n';
    }
    std::cout << "+";
    for (int i = 0; i < actualSize; i++) {
      std::cout << "-";
    }
    std::cout << "+\n";
  }
};
void printTemplate(std::vector<std::array<std::string, 4>> taskVector) {
  outputTemplate _template;
  _template.printLine();
  _template.printHeader();
  _template.printLine();
  _template.printTask(taskVector);
}

std::string getCurrentExecutablePath() {
#ifdef _WIN32
#include <direct.h>
#include <limits.h>

#include <iostream>
  char buff[PATH_MAX];
  _getcwd(buff, PATH_MAX);
  std::string current_working_dir(buff);
  return current_working_dir;
#endif

#ifdef linux
#include <filesystem>
  return std::filesystem::current_path();
#endif
}

void setUserSettings() {
  if (std::filesystem::exists(getCurrentExecutablePath() + "/doc/config.cfg") &&
      Tokens.empty()) {
    return;
  }
  std::ofstream userEnvFile(getCurrentExecutablePath() + "/doc/config.cfg");
  std::array<std::string, 2> envSettingsArray;

  if (userEnvFile.is_open()) {
    std::cout << "Your executable path for reference: "
              << getCurrentExecutablePath() << '\n'
              << "\nPlease answer to set your environment up:\n"
              << "Set Task Path:\n> ";
    std::cin >> envSettingsArray[0];
    std::cout << "Set Date Format:\n> ";
    std::cin >> envSettingsArray[1];

    userEnvFile << "executable_path = \"" << getCurrentExecutablePath()
                << "\"\n"
                << "task_path = \"" << envSettingsArray[0] << "\"\n"
                << "date_format = \"" << envSettingsArray[1] << "\"\n";
    userEnvFile.close();
    return;
  }

  std::cout << "\n Error trying to create or open config file.\n"
            << "There is a big chance its caused by the path.\n"
            << "Verify if the \"doc\" directory exists in \n"
            << "the project build.\n"
            << "Run \"set\" command or run the application again\n"
            << "to try rebuilding the config file\n\n";
  return;
}

void help_command() {
  std::string line;
  std::ifstream helpText;
  std::ifstream cfg;
  helpText.open("./doc/helpCommand.txt");

  if (helpText.is_open()) {
    while (std::getline(helpText, line)) {
      std::cout << line << "\n";
    }
    helpText.close();
    return;
  }
  std::cout << "Unable to display all commands\n"
            << "Check if \"helpCommand.txt\" exists in the /doc directory\n";
  helpText.close();
  return;
}

void show_command() {
  if (Tokens.size() == 1) {
    // In the future I want to make it display possibilities
    std::cout << "Wrong use of command\n";
    return;
  }

  std::string line;
  std::string path = getTaskPathFromConfigFile();
  std::vector<std::array<std::string, 4>> taskVector;
  if (Tokens[1] == "all") {
    std::vector<Task> allTasks;
    std::array<std::string, 5> taskFields;
    libconfig::Config cfg;
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
      try {
        cfg.readFile(entry.path());
      } catch (const libconfig::FileIOException &fioex) {
        std::cout << "I/O error while reading file.\n";
        return;
      } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << '\n';
        return;
      }
      libconfig::Setting &root = cfg.getRoot();
      if (!root.exists("Tasks")) {
        std::cout << "No tasks in Label : " << entry.path() << '\n';
        return;
      }
      libconfig::Setting &tasks = root["Tasks"];

      try {
        std::array<std::string, 4> taskFieldArray;
        std::string ID = tasks[0].lookup("ID");
        std::string name = tasks[0].lookup("name");
        std::string dueDate = tasks[0].lookup("dueDate");
        std::string description = tasks[0].lookup("description");
        taskFieldArray = {ID, name, dueDate, description};
        taskVector.push_back(taskFieldArray);

      } catch (const libconfig::SettingNotFoundException &nfex) {
        std::cerr << "Didn't find Tasks\n";
        return;
      }
    }
    printTemplate(taskVector);
    return;
  }

  std::ifstream taskFile(path + Tokens[1] + ".cfg");
  if (taskFile.is_open()) {
    while (std::getline(taskFile, line)) {
      std::cout << line << "\n";
    }
    taskFile.close();
    return;
  }
  std::cout << "Wrong use of command\n";
  return;
}

void create_command() {
  std::array<std::string, 4> taskObjectsArray;
  std::array<std::string, 4> textArray = {
      "Label:\n> ",
      "Name:\n> ",
      "Date(DD:MM):\n> ",
      "Description:\n> ",
  };
  uint id = generateTaskID();

  if (id == 0) {  // This is just a way to get a invalid ID, check the
    return;       // generateTaskID function
  }
  for (int i = 0; i < 4; i++) {
    std::cout << "Enter the Task's " << textArray[i];
    std::cin >> taskObjectsArray[i];
  }
  Task task(taskObjectsArray[0], id, taskObjectsArray[1], taskObjectsArray[2],
            taskObjectsArray[3]);
}

void executeCommands() {
  setUserSettings();

  std::unordered_map<std::string, std::function<void()>> commandsMap{
      {"show", show_command},     {"help", help_command},   {"h", help_command},
      {"create", create_command}, {"set", setUserSettings},
  };

  while (true) {
    Tokens = getUserInput();
    if (commandsMap.find(Tokens[0]) != commandsMap.end()) {
      commandsMap[Tokens[0]]();
    }
    Tokens.clear();
  }
}
