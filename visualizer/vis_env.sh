#!/bin/bash

# Check Python version

if ! hash python3; then
    echo "python is not installed"
    exit 1
fi

ver=$(python3 -V 3>&1 | sed 's/.* \([0-9]\).\([0-9]\).*/\1\2/')

if [ "$ver" -lt "38" ]; then
    echo "This script requires python 3.8 or greater"
    exit 1
fi

# Initialize the environment

python3 -m venv visualizer/venv-vis
source visualizer/venv-vis/bin/activate
pip3 install -r visualizer/requirements.txt

deactivate
