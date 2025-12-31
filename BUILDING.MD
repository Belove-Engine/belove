# Building
To build and install the Belove Engine, you can use the provided build scripts located in the `tools` directory. There are two scripts available: one for Unix-like systems (`build_install.sh`) and another for Windows systems (`build_install.bat`).

### Requirements (Windows and Unix-like systems)
- CMake 3.10 or higher
- A C++ compiler (GCC, Clang, or MSVC)
- SDL2 development libraries (for SDL2 builds)
- Raylib development libraries (for Raylib builds)

### Requirements (Wii builds)
- devkitPro with the `wii-dev` package installed
- [GRRLIB][grrlib repo]

### Building on Unix-like Systems
1. Open a terminal and navigate to the `tools` directory.
2. Run the build script:
   ```bash
   ./build_install.sh
   ```
3. Follow the prompts to select the desired location and complete the installation.

### Building on Windows Systems
1. Open a Command Prompt and navigate to the `tools` directory.
2. Run the build script:
   ```cmd
   build_install.bat
   ```
3. Follow the prompts to select the desired location and complete the installation.

### Additional Notes:
- **For Wii builds, you need to choose the the path when prompted during the build process.**
```
/opt/devkitpro/portlibs/wii (unix)
C:\devkitpro\portlibs\wii (windows)
```

### Post-Installation
After installation, you can include the Belove Engine headers and link against the installed libraries in your projects. Make sure to refer to the documentation for specific usage instructions and examples.

### Troubleshooting
If you encounter any issues during the build or installation process, please check the output messages for errors. If problems persist, you can write an issue in the GitHub repo with the tag "help", or just contact me at discord: [@raic.e][discord link]

[discord link]: https://discord.com/users/570693486500773888
[grrlib repo]: https://github.com/GRRLIB/GRRLIB