REM set HTTPS_PROXY=https://10.110.15.6:8080

CALL .\venv\Scripts\python -m pip install --upgrade pip
CALL .\venv\Scripts\pip install --upgrade setuptools


REM from local (wheels)
REM CALL .\venv\Scripts\pip install --no-index --find-links=./down/win -r pip_reqs.txt	

REM from pypi (online)
CALL .\venv\Scripts\pip install -r pip_reqs.txt

 
