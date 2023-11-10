#include <array>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Commands.hpp"
#include "Task.hpp"

std::vector<std::string> getUserInput() {
  std::vector<std::string> userInput;
  std::string input;
  std::cout << "> ";

  std::getline(std::cin, input);
  std::stringstream ss(input);
  std::string word;

  getline(ss, word, ' ');
  userInput.push_back(word);

  return userInput;
}

void helpCommand(std::vector<std::string> userInput) {
  std::string line;
  std::ifstream helpText;
  helpText.open("./Tasks/helpCommand.txt");

  if (helpText.is_open()) {
    while (std::getline(helpText, line)) {
      std::cout << line << "\n";
    }
    helpText.close();
    return;
  }
  std::cout << "Unable to display all commands\n";
  std::cout << "Check if \"helpCommand.txt\" exists\n";
  return;
}

void showCommand(std::vector<std::string> userInput) {
  if (userInput.size() < 1) {
    std::cout << "Please especify file path\n";
    return;
  }
  std::string path = "./Tasks/";
  std::string fileName = userInput[1];
  std::ifstream taskFile(path.c_str() + fileName);
  std::string line;

  if (userInput[1] == "all") {
    // get all inputs;
    std::cout << "all\n";
    return;
  }
  if (taskFile.is_open()) {
    while (std::getline(taskFile, line)) {
      std::cout << line << "\n";
    }
  }
  taskFile.close();
  return;
}

void addToCommand(std::vector<std::string> userInput) {
  std::array<std::string, 4> taskObjectsArray;
  std::array<std::string, 4> textArray = {
      "Label:\n> ", "Name:\n> ", "Date(DD:MM):\n> ", "Description:\n> "};

  for (int i = 0; i < 4; i++) {
    std::cout << "Enter the Task's " << textArray[i];
    std::cin >> taskObjectsArray[i];
  }
  Task task(taskObjectsArray[0], taskObjectsArray[1], taskObjectsArray[2],
            taskObjectsArray[3]);
  getUserInput();
  return;
}

void executeCommands() {
  std::vector<std::string> userInput;
  std::unordered_map<std::string,
                     std::function<void(const std::vector<std::string>)>>
      functionMap{
          {"show", showCommand},
          {"help", helpCommand},
          {"add", addToCommand},
      };

  while (true) {
    userInput = getUserInput();
    if (functionMap.find(userInput[0]) != functionMap.end()) {
      functionMap[userInput[0]](userInput);
    } else if (userInput[0] == "exit") {  // This works as the "exit" command
      break;
    } else {
      std::cout << "No command found.\n";
    }
  }
}
