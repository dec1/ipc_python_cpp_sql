#!/bin/bash

# export https_proxy=https://10.110.15.6:8080

 ./venv/bin/python -m pip install --upgrade pip
 ./venv/bin/pip install --upgrade setuptools



# from local (wheels)
# ./venv/bin/pip install --no-index --find-links=./down/lin -r pip_reqs.txt	

# from pypi (online)
 ./venv/bin/pip install -r pip_reqs.txt



 
