# World IMaker

World IMaker is a Voxel Editor created in the context of studies in [IMAC](https://www.ingenieur-imac.fr/). 

## Table of contents

* [Getting Started](#getting-started)
* [Install and Build](#install-build)
* [Let's play !](#lets-play)


<a name="getting-started"></a>
## Getting started

### On MAC OSX

Use the package manager [Homebrew](https://brew.sh/index_fr).
Install the package manager.

```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

Then install some libraries on your computer.

```bash
brew install cmake
```
```bash
brew install glew
```
```bash
brew install sdl2
```
```bash
brew install eigen
```

Now your computer is ready to run the project ! 

### On Linux

The package manager is native on Linux and his name is [apt-get](https://doc.ubuntu-fr.org/apt-get).

```bash
sudo apt-get install cmake
```
```bash
sudo apt-get install libglew-dev
```
```bash
sudo apt-get install libsdl2-dev
```
```bash
sudo apt install libeigen3-dev
```

Now your computer is ready to run the project ! 

<a name="build"></a>
## Install and Build

Now you can clone the repository in your folder.

```bash
git clone https://github.com/bmangeat/IMAC2-OGL-PROJET.git
```

In the same folder, create one folder called **build**.

````
├── build
└── IMAC2-OGL-PROJET
     ├─ assets
     ├─ doc
     ├─ include
     ├─ libs
     ├─ src
     ├─ CMakeLists.txt
     └─ README.MD
````

```bash
mkdir build
cd build
cmake ../IMAC2-OGL-PROJET
make
```
Find the executable in the folder *build/bin*. You can open it thanks to the next command.

```bash
./bin/WorldIMaker
```
<a name="lets-play"></a>
## Let's play ! How to use it ?

###Basis Command
* Movement of camera on x-axis and y-axis : Left click down and drag - Mouse
* Movement of camera on z-axis | Zoom-in and Zoom-out : Scroll click - Mouse
* Move the cursor to the left : Press Q - Keyboard
* Move the cursor to the right : Press D - Keyboard
* Move the cursor to the top : Press Z - Keyboard
* Move the cursor to the bottom : Press S - Keyboard
* Move the cursor to the front : Press A - Keyboard
* Move the cursor to the back : Press E - Keyboard

###Main Features
* Select your cube : Right click - Mouse
* Apply some color to your cube : Press R, G or B - Keyboard
* Create or Delete Cube selected : Press Space - Keyboard
* Extrude cube : Press Space - Press W - Keyboard
* Dig cube : Press Space - Press X - Keyboard
* Generate random scene : Press J - Keyboard
* Switch on/off the point light : Press V - Keyboard
* Refresh the scene : Press C - Keyboard


###Additional Features
* Save your world : Press K - Keyboard
* Open saved world : Press L - Keyboard

