## simple 2d engine demo

This repo is a demo of how to use the [simple 2d engine](https://github.com/jonatasschagas/simple-2d-engine). When checking out the repo, make sure to pull the submodules too:

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
```

After installing all the dependencies, to build and run the game, use **cmake** and **make**:
```sh
cd projects/osx
cmake .
make
./simple-2d-engine-demo //execute the game
```

If you use **VS Code** there's a launch configuration called **(lldb) Launch Sample Game** that does the steps described above for you.


