# make_tutorial
Based on https://www.udemy.com/course/make-and-makefile-for-cc-projects-2022-edition/ and <br>
https://github.com/franneck94/UdemyMakefile

## Compilation steps

Usually, to build the project binary, it involves preprocessing,<br>
generation of object files against each source file and finally <br>
linking the libs and all the generated objects, to generate <br>
executable binary.

### Compilation
- To produce object file `main.o` <br>
- command: <br>
``` g++ main.cpp -c ```

### Compiler Flags

- Debug: ```-g```, includes the following in the exec binary:
  - debug information: help debugging tools to enable debug.
  - Symbol Tables: names, types of var, functions, symbols.
  - Line numbers: map breakpoints to specific line in src.
  - Function names.

- Release: ```-O0 -O1 -O2 -O3 -Og -Os```
  - ``-O0``: No optimization, for debugging.
  - ``-O1``: Basic performance optimization.
  - ``-O2``: Higher performance optimization.
  - ``-O3``: Advanced performance optimization.
  - ``-Os``: Optimize for smaller code size.
  - ``-Og``: Optimize for debugging.
- Includes: ```-I```
  - Include directory path for header files
- Warnings: ```-Wall -Wextra -Wpedantic -Wconversion```
  - ``-Wall``: Enable most warnings.
  - ``-Wextra``: Enable extra warnings.
  - ``-Wpedantic``: Enforce strict standards.
  - ``-Wconversion``: Warn about type conversions.

### Linker
- Link object files, generate exec/binary.
- command: ``` g++ main.o -o main```.
- ```-L```: flag to indicate path to libraries.
- ```-l```: flag to pass a library to link. Example: ```-lpthread```.
- ```-T```: linker script ```linker_script.ld``` file.


## About Makefile

### Makefile basics
- In a Makefile, we have
  - ```targets``` and
  - ```dependencies```.
- Generally, ```targets``` are expected to be files.
- so it is ```make file```, but they can also be just names.
- Dependecies can be other targets or files. To run make:
```shell 
    $ make target (a.k.a file)
```
- Inside a makefile, we have:
```make
    target: depedency1 depedency2
        command1
        command2
```
- The tab after the target line is important for make to parse the ```Makefile```.
- ```%``` is wildcard operator, for more details, refer ```04_variables```.

### .PHONY
When a ```target``` is not to be associated with a file (name), and we declare the target as ```.PHONY```. For example, in our project we have target ```build``` and we have build folder. Without ```.PHONY```, running ```make build``` would results in "upto date", as there is no change on build folder.
To just run it as target and not associate it with this folder, declare it as .PHONY .

- Use ``.PHONY`` in a Makefile to declare a ``target`` that must not related to a file.
- Example: You have a ``"build"`` target and a ``"build"`` folder in your project.
- Without ``.PHONY``, running ```make build``` may result in "up to date", i.e., no build, because the folder as a file doesn't change.
- To run it as a ```target``` only, without associating it to the folder (file), declare it as ``.PHONY``.

```make
    .PHONY: build clean
```

### Fetching Target, dependencies in Target command statements
- Let us go with an example:
  ```make
    build_target: dependecy1 dependecy2 depdency3
  ``` 
- ```$@```: gives the name of the target, i.e.,```"build_target"```.
- ```$<```: gives the name of the first dependency, i.e.,```"dependecy1"```.
- ```$^```: gives the name of all dependencies, i.e.,```"dependecy1 dependecy2 depdency3"```.


### Makefile variables
```make
VARIABLE_NAME = Value
```
- ```Value``` is always a string.
- They can be referred by ```$(VARIABLE_NAME)``` in  makefile.
- To get global pre-defined make variables, just run:
```shell 
$ make -p
```
- They can be overidded by passing over at make command.
```shell 
$ make VARIABLE_NAME=ValueA
```
