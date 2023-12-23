#include <iostream>

#include "../lib/Commands.hpp"

int main() {
    std::cout << "+------------------------------------+\n"
                 "|                                    |\n"
                 "| Welcome to Your To-Do task Manager |\n"
                 "|                                    |\n"
                 "+------------------------------------+\n"
                 "Type [h]elp for help and 'exit' to quit\n";

    ExecuteCommands();
    std::cout << "Exited" << std::endl;
}
