# Conway's Game of Life in C

C version of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) using [ncurses](https://en.wikipedia.org/wiki/Ncurses) to display the grid.

# How to Build

* OSX: ```brew install ncurses``` or ```port install ncurses```
* Debian: ```sudo apt-get install libncurses-dev```
* Run ```make``` to build ```bin/cnwy```
* Run ```make test``` to build and run all unit tests

# How to Use

Call ```bin/cnwy``` providing the designed frame rate, grid column count and grid row count.