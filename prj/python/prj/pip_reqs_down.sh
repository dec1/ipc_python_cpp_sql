#!/bin/bash

# export https_proxy=https://10.110.15.6:8080

# download copy of packages (wheels) 
./venv/bin/pip download --dest ./down/lin --no-cache  -r pip_reqs.txt
	## python3 -m pip download --dest ./down --no-cache  -r pip_reqs.txt