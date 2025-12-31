#!/usr/bin/env bash
set -e

echo "Where should the library be installed?"
echo "1) /usr/lib (for sdl2 and raylib builds)"
echo "2) /opt/devkitpro/portlibs/wii/lib (for wii builds)"
echo
read -rp "Choose [1]: " choice
cd ..
case "$choice" in
    2)
        PREFIX="/opt/devkitpro/portlibs/wii"
        ;;
    ""|1)
        PREFIX="/usr"
        ;;
    *)
        echo "Invalid option"
        exit 1
        ;;
esac

echo "Installing to: $PREFIX"
echo

# --- build ---
case "$choice" in
    2)
        make clean
        if ! make -j"$(nproc)"; then
            echo "Build failed"
            exit 1
        fi
        echo "Installing library..."
        sudo cp build/libBeloveEngine.a "$PREFIX/lib/"
        sudo cp -r include/BeloveEngine.hpp "$PREFIX/include/"

        # check if any of the above commands failed
        if [ $? -ne 0 ]; then
            echo "Installation failed, check for errors above"
            exit 1
        else
            echo "All set, thanks for using Belove!"
        fi
        ;;
    ""|1)
        rm -rf build
        mkdir build
        cd build
        # needs to check if cmake .. was successful
        if ! cmake .. -DCMAKE_INSTALL_PREFIX="$PREFIX"; then
            echo "CMake configuration failed, check for errors above"
            exit 1
        fi
        make -j"$(nproc)"
        echo "Installing library..."
        sudo make install

        # check if any of the above commands failed
        if [ $? -ne 0 ]; then
            echo "Installation failed, check for errors above"
            exit 1
        else
            echo "All set, thanks for using Belove!"
        fi
        ;;
esac