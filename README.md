In blender executable file directory execute:
    ./blender -b -P "python file path"

################################################

Build blender:
    sudo bash ./build_files/build_environment/install_deps.sh --skip-python --skip-numpy

Insert 2 lines at CMakeLists.txt:63:
    set(PYTHON_LIBRARY /home/xie/miniconda3/bin/python3.6m)
    set(PYTHON_INCLUDE_DIR /home/xie/miniconda3/include/python3.6m)

Config makefile:
    cmake ../blender -DCMAKE_INSTALL_PREFIX=/opt/blender -DWITH_INSTALL_PORTABLE=OFF -DWITH_BUILDINFO=OFF -DWITH_GAMEENGINE=OFF -DWITH_IN_SOURCE_BUILD=ON

make