REM set HTTPS_PROXY=https://10.110.15.6:8080


REM  download copy of packages (wheels) 
CALL .\venv\Scripts\pip download --dest .\down\win --no-cache  -r pip_reqs.txt



