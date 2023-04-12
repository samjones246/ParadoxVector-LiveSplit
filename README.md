# ParadoxVector-LiveSplit
A plugin for the [GameStudio A8](http://3dgamestudio.net/english/gstudio/index.php) engine which allows [Paradox Vector](https://store.steampowered.com/app/1051840/Paradox_Vector/) to communicate with [LiveSplit](https://livesplit.org).

## Purpose
### Autosplitters
LiveSplit is a timer application widely used by speedrunners. This application has the ability to read the memory of a running application and, with the help of a game specific script, automatically control the timer based on in game events. These scripts are referred to as autosplitters. For example, the timer could automatically:
 - Start when the player creates a new game
 - Split on reaching the end of every level
 - Pause while the game is loading
 - Stop when the player reaches the end of the game

This functionality is very useful for speedrunners. It removes the need to manually start/stop the timer, which as well as involving extra inputs which could hamper gameplay would also introduce inaccuracies to the timing due to human error. In cases where the game has variable length loading screens which should not be included in the final time, this also removes the need for the time consuming chore of manually retiming.

### Reverse Engineering
Developing an autosplitter requires locating addresses of important variables in memory. The autosplitter developer typically does not have access to the source code of the game, so does not know exactly which variables exist or which values are assigned to them. Also, variables which are not static will be dynamically allocated, so the address which needs to be read will change every time the game is launched. To overcome this, the developer must identify a pointer path, which starts at a static address and follows a series of pointers at fixed offsets to eventually locate the target value.

The process described above is challenging, and can sometimes result in an autosplitter which lacks all the desired functionality. The 'perfect world' scenario when developing an autosplitter is that the game maintains a static structure of all the relevant game state, that the specifications of this structure are publically available, and that it is easily locatable in memory. This scenario is typically only achieved by co-operation on the part of the game's developer.

### Conclusion
This project is my half of the collaboration with the developer of Paradox Vector, Schmidt Workshops. The engine in which Paradox Vector was built, GameStudio A8, uses a simplified version of C called Lite-C for programming game behaviour. We found that the runtime for this language does not easily allow creating static variables which are allocated in memory in the expected way. This project overcomes this using a DLL, written in C++, which can hold the state we need in a static location and expose methods which access or mutate this state to the game's Lite-C scripts.

## Structure
This repository includes two directories:
 - `litec` contains the Lite-C header file which should be included in a GameStudio A8 project in order to access the functions exposed by the plugin. This header simply contains the function signatures, documentation, and relevant boilderplate to bind to the DLL.
 - `plugin` contains the source code for `livesplitdata.dll`, the engine plugin which implements the methods and manages the data. This is a Visual Studio project, created with Visual Studio 2019.

## Usage
### Requirements
 - GameStudio A8.
 - If you're Schmidt Workshops, source code for Paradox Vector. Otherwise, source code for a dummy project on which you'd like to test this plugin.

### Installation
 - Download `livesplitdata.h` and `livesplitdata.dll` from this repository's releases page.
 - Place `livesplitdata.dll` into the `acknex_plugins` folder in the installation folder of GameStudio A8. By default, this is `C:\Program Files (x86)\GStudio8\acknex_plugins`.
 - Place `livesplitdata.h` into the source or include directory for your project.

### Usage
 - Add `#include <livesplitdata.h>` to the top of any files which need to read or update the game state accessed by LiveSplit.
 - Use the methods defined in `livesplitdata.h`.

## Building
### Requirements
 - GameStudio A8 (at least the contents of `sdk_plguin` folder included with the installation)

### Building
 - Clone this repository.
 - Open `plugin\ParadoxVector-LiveSplit.sln` with Visual Studio 2019+.
 - If your installation of GameStudio A8 is not in the default location (`C:\Program Files (x86)\GStudio8`), you'll need to modify the additional directories for headers and libraries to point to your installation's `sdk_plugin` folder. These settings can be accessed via:
   - `Project -> ParadoxVector-LiveSplit Properties -> C/C++ -> General -> Additional Include Directories`
   - `Project -> ParadoxVector-LiveSplit Properties -> Linker -> General -> Additional Library Directories`
 - Build the solution.