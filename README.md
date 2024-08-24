## simple 2d engine demo

This repo is a demo of how to use the [simple 2d engine](https://github.com/jonatasschagas/simple-2d-engine). 

![Demo](demo-engine-osx.gif)

In this demo you can see:
 - How to wire up the engine by providing the right implementation of the "manager" classes depending on the platform you're running the engine on. Manager classes are: GraphicsManager, SoundManager, InputManager and ResourceManager. 
- How to setup *views*
- How to move, rotate and scale Sprites
- How to setup textured Sprites
- How to read player input (keyboard or touch screen)
- How to build a *scene graph* where the children sprites behave according to the position/scale/orientation of parent Sprites
- How to setup and use Shaders
- How to play songs and sounds

When checking out the repo, make sure to pull the submodules too:

```sh
git submodule update --init --recursive
```

The repo is structured as follows:
 - **src:**               code of the Sample Game. Here you can see how to implement things using the engine.
 - **assets:**           images and shaders used by the sample game
 - **projects:**         project files to run the sample game in different platforms
 - **simple-2d-engine:** code of the engine

### OSX

The osx build is in **projects/osx**. Here are the steps to run this project on OSX:
 - install and update Xcode
 - install xcode command line tools ``xcode-select --install``
 - install homebrew

Once homebrew is installed, use the terminal to install the following dependencies:
```sh
brew install cmake
brew install glfw
brew install sdl2
brew install sdl2_mixer
```

After installing all the dependencies, to build and run the game, use **cmake** and **make**:
```sh
cd projects/osx
cmake .
make
./simple-2d-engine-demo //execute the game
```

If you use **VS Code** there's a launch configuration called **(lldb) Launch Sample Game** that does the steps described above for you.

### Android

Install **Android Studio** on your system, open it, and open the project at ``projects/android/``. Then run "Build".

The cmake file "CMakeLists.txt" is located at: ``projects/android/app/src/main/cpp``. There you can find all the build configuration.

### Credits

Music: credits to https://patrickdearteaga.com. 

