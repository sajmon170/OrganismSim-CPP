# Organism Simulator - C++ edition
An organism simulator written for an Object Oriented Programming class assignment.

<p align="center">
  <img src="/docs/resources/screenshot.png" width="75%">
</p>

## Controls
- Use WASD to move the character
- Use the arrow keys to move the camera 
- Use the space key to advance time without moving

You can perform additional actions as specified in the status bar

## Build instructions
This project depends on Curses and is built with Meson.

> [!WARNING]
> This project depends on [libcursespp](https://github.com/sajmon170/libcursespp) as a git submodule.

Clone this repo with the `--recurse-submodules` flag. If the repo was cloned in a normal fashion it needs to be initialized manually:
```bash
git submodule update --init
```

After entering the repo create a Meson builddir and compile the project:
```
meson setup builddir
cd builddir
meson compile
```

This will output a `simulator` executable inside builddir.

## Additional notes
This project also has a [Java counterpart](https://github.com/sajmon170/OrganismSim-Java).
