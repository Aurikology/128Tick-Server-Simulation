# Modern C++ Project

Minimal Modern C++ project using CMake.

## Build (Windows, Visual Studio)

1. Create a build directory: `mkdir build && cd build`
2. Run CMake: `cmake -S .. -B . -G "Visual Studio 17 2022" -A x64`
3. Open the generated solution or build: `cmake --build . --config Release`

## Notes
- Build artifacts are ignored via `.gitignore`.
- To publish to GitHub, create a repo and run:

```
git remote add origin <git-url>
git push -u origin master
```
