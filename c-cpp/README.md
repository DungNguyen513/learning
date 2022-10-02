# Learn C/C++

## VSCode

To run C/C++ on [VSCode](https://code.visualstudio.com/) requires MinGW GCC G++ Compiler

#### Setup MinGW GCC G++ Compiler

1. Download [this](../download/mingw-18.0-without-git.exe)
1. Double-click to open file
1. In the section `Extract to`, type `C:\env`, and then Click `Extract` button
1. Press `Windowx + R`, type `rundll32.exe sysdm.cpl,EditEnvironmentVariables`, and press `Enter`
1. In the section `User variables for <your-pc-name>`, find `Path` in column `Variable`, and double-click
1. Click `New` and type `C:\env\MinGW\bin`
1. Then click `OK` and `OK`

Check if gcc is working

1. Open `Command Prompt`
1. Type `gcc --version` and press `Enter`

#### How to run C/C++

1. Download extension [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
1. Go to `Setting`
1. Search `Code-runner: Run In Terminal` and check the box
