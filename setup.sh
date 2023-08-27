#!/bin/bash -e
info() { printf "\e[1;34m$1\e[0m\n"; }

VENV_DIR=".env"

info "This script will create a new python virtual environment."
info "The target version of python is:"
info "  - Python 3.10.X"
info "If this is not installed, please call the script with \"--full\" argument"
echo
echo "Make also sure that script is executed in the root directory of the project."
echo

if [ "$1" == "--full" ]; then
    info "Installing python 3.10.X"
    sudo apt install python3.10 python3.10-venv python3-pip
fi

if [ -d $VENV_DIR ]; then
    info "Virtual environment already existing"
else
    info "Creating virtual environment..."
    python3.10 -m venv $VENV_DIR
fi

source $VENV_DIR/bin/activate

if [ -f "requirements.txt" ]; then
    info "Installing requirements..."
    pip3 install -r requirements.txt
fi

echo $PWD > $VENV_DIR/lib/python3.10/site-packages/projectpath.pth

info "Procedure completed."
echo "You can now activate the virtual environment with:"
echo "   source .env/bin/activate"
