#include <iostream>

#include "Commands.hpp"

int main() {
  std::cout << "+------------------------------------+\n"
               "|                                    |\n"
               "| Welcome to Your To-Do task Manager |\n"
               "|                                    |\n"
               "+------------------------------------+\n"
               "Type [h] for help\n";
  executeCommands();
}
