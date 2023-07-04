#!/bin/sh -e

info() { printf "\e[1;34m$1\e[0m\n"; }

INSTALL_DIR=~/programs/roboptim
DOWNLOAD_DIR=~/Downloads
cores=$(nproc --all)

info "Installing dependencies..."
sudo apt install -y libeigen3-dev cmake gcc g++ doxygen libboost-all-dev \
    liblog4cxx-dev libtool pkg-config


info "Cloning RobOptim repository..."
if [ ! -d $DOWNLOAD_DIR/roboptim-core ]; then
    git clone --recursive https://github.com/roboptim/roboptim-core.git $DOWNLOAD_DIR/roboptim-core
fi
mkdir -p $DOWNLOAD_DIR/roboptim-core/_build
cd $DOWNLOAD_DIR/roboptim-core/_build
mkdir -p $INSTALL_DIR
info " ---> Cmake configuration"
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR ..
info " ---> Make compile"
make -j$cores
info " ---> Make test"
make test
info " ---> Make install"
make install
