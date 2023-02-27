#!/bin/bash

# export https_proxy=https://10.110.15.6:8080

python3 -m venv ./venv

echo ".....virtual environment created"

source ./venv/bin/activate

echo ".....pip reqs installing...."

source  ./pip_reqs_install.sh

echo ".....pip reqs installed"

deactivate

echo ".....venv ready"

