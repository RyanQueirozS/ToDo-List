# ToDoC - A simple, terminal, C++ based task manager

## About
<div style="margin-left: auto;
margin-right: auto;
width: 40%">

**TODOC IS STILL IN DEVELOPMENT**\
        </div>

<div style="margin-left: auto;
margin-right: auto;
width: 90%">

**IT SHOULD WORK, BUT DONT EXPECT FULL FUNCIONALITY OR TO NOT GET ERRORS**
</div>

\
ToDoC is a easy to use Todo-list that uses little to no resources, while
allowing for good usability and tasks tracking.

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
```
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
- [ ] Implement it to a database if user wants to
- [ ] Easier configuration(Maybe even a config script)

### In regards of the program itself:
- [ ] Make it cross-platform (Windows/Maybe Mac)
- [ ] Make it an installable
- [ ] Easier Install(Maybe a package in the AUR, or a install script)
