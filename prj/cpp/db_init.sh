#!/bin/bash


#  mysql - start service 
#--------------------------
service mysql start  

    # Note : On "systemd" (ubuntu standard), one would start the service via
    # > systemctl start mysql.service
    # but this docker image uses "sysvinit" 
    
    

# ensure mysql database exists
------------------------------
mysql -uroot -proot -e "CREATE DATABASE IF NOT EXISTS my_db;" 
