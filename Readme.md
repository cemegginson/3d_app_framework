###Advanced Game Programming Final###

This originally started out as my final project in Advanced Game Programming,
but it's come a long way since then with 3D capabilities thanks to a new renderer
written in OpenGL, as well as greatly increased speed thanks to Bryan's Threaded
Event System that he originally wrote for his Advanced Game Programming class.

To compile this project you'll require SDL2, SDL2_image, GLM, GLEW, and an OpenGL 3.3
capable GPU and its accompanying graphics driver. You'll also need CMake and whichever
compiler toolchain you would prefer, be it Visual Studio, GCC, or Clang.

Extensive knowledge of CMake and how Windows handles paths is required to build 
the engine on Windows.  We strongly reccommend using any modern version of Linux
to easily install the requirements.  If using Linux, CMake will automatically
find the dependencies if they are installed.

The code is written in C++14 but uses some C99 compatible headers.  Make sure to
use a compiler toolchain that supports C++14 range loops and 
C++14 std::unique_lock<>.  C++14 condition variables are also required for 
runtime thread safety.
