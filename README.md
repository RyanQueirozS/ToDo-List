# ToDoC - A simple, terminal, C++ based task manager

## About
**TODOC IS STILL IN DEVELOPMENT**

**IT SHOULD WORK, BUT DONT EXPECT FULL FUNCIONALITY OR TO NOT GET ERRORS**

\
ToDoC is a easy to use Todo-list that uses little to no resources, while
allowing for good usability and tasks tracking.

## Basic info
Todoc works with libconfig to create tasks and display them for the user. It should be noted a few words that might be thrown arround while using the program:

- 'Lables' are the separation word for tasks. Todoc stores tasks in diferent files regarding those labels.

All the other stuff is intended to be easy to understand. If you have any problem while trying to use the application, either send me a message or create an Issue.


## Functionalities
- [X] Create/Read/Update/Delete Tasks

- [X] Simple commands for CRUD operations

- [X] Works without a Database

- [ ] Works with a Database

- [ ] Relational data from a 'Label' to another


## Requirements
- **Linux**
- C++ compiler 
- Make and CMake
- Libconfig

### Installation
```bash
git clone https://github.com/RyanQueirozS/ToDo-List.git
cd ToDo-List
cmake .
make
./todoc (To run the executable)
```

## Commands

```
show <args>                   --displays tasks in a table | <args> = "all" or "task_label"
create                        --creates task
edit                          --edits tasks
set                           --sets environment
```

## Configuration
run the application with `./todoc` and use the `set` command, it will guide you
through the process. DO NOT use `$HOME` or `~` to assing your
`/home/yourprofile`, it will not work. Since this is a work in progress, the
option "Date Format" doesn't work properly.

## Todo:
### Implementations:
- [ ] Use it with a database if user wants to
- [ ] Easier configuration(Maybe even a config script)
- [ ] Make DueDate  work
- [ ] Order tasks based on their ID from < to >
- [ ] Create a relation between task Labels

### In regards of the program itself:
- [ ] Make it cross-platform (Windows/Maybe Mac)
- [ ] Make it an installable
- [ ] Easier Install(Maybe a package in the AUR, or a install script)#
