#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Commands.hpp"
#include "Environment.hpp"
#include "Task.hpp"

std::vector<std::string> getUserInput() {
  std::string userInput;
  std::cout << "> ";
  std::getline(std::cin, userInput);
  if (userInput == "") {
    userInput = "null";
  }

  std::stringstream ss(userInput);
  std::istream_iterator<std::string> begin(ss);
  std::istream_iterator<std::string> end;
  std::vector<std::string> tokens(begin, end);

  return tokens;
}
void taskOutputTemplate(std::vector<Task> taskVector) {}

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

void setUserSettings(CommandParams tokens) {
  if (std::filesystem::exists(getCurrentExecutablePath() + "/doc/config.cfg") &&
      tokens.tokens.empty()) {
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

void help_command(CommandParams) {
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

void show_command(CommandParams tokens) {
  if (tokens.tokens.size() == 1) {
    std::cout << "Wrong use of command\n";
    return;
  }

  std::string line;
  std::string path = getTaskPathFromConfigFile();
  if (tokens.tokens[1] == "all") {
    std::vector<Task> allTasks;
    std::array<std::string, 5> taskFields;
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
      std::ifstream taskFile(entry.path());
      while (std::getline(taskFile, line)) {
        std::cout << line << "\n";
      }
      taskFile.close();
    }
    return;
  }

  std::ifstream taskFile(path + tokens.tokens[1] + ".cfg");
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

void create_command(CommandParams) {
  std::array<std::string, 4> taskObjectsArray;
  std::array<std::string, 4> textArray = {
      "Label:\n> ",
      "Name:\n> ",
      "Date(DD:MM):\n> ",
      "Description:\n> ",
  };
  uint id = generateTaskID();

  if (id == 2147483647) {  // This is just a way to get a invalid ID, check the
    return;                // generateTaskID function
  }
  for (int i = 0; i < 4; i++) {
    std::cout << "Enter the Task's " << textArray[i];
    std::cin >> taskObjectsArray[i];
  }
  Task task(taskObjectsArray[0], id, taskObjectsArray[1], taskObjectsArray[2],
            taskObjectsArray[3]);
}

void executeCommands() {
  CommandParams commandParams;
  setUserSettings(commandParams);

  std::unordered_map<std::string, std::function<void(const CommandParams)>>
      commandsMap{
          {"show", show_command},   {"help", help_command},
          {"h", help_command},      {"create", create_command},
          {"set", setUserSettings},
      };

  while (true) {
    commandParams.tokens = getUserInput();
    if (commandsMap.find(commandParams.tokens[0]) != commandsMap.end()) {
      commandsMap[commandParams.tokens[0]](commandParams);
      commandParams.tokens = {""};
    }
  }
}
