#!/bin/bash
ip_prefix=192.168.1

for ip in `seq 1 255`
do
    ping -c 2 ${ip_prefix}.$ip > /dev/null 2>&1
    if [ $? -eq 0 ]; then # if ping success, append this ip to file `ping_success.txt`
        echo "${ip_prefix}.$ip" >> up.txt
        echo "ping success: ${ip_prefix}.$ip"
    else    # if ping fails, append this ip to file `ping_failed.txt`
        echo "${ip_prefix}.$ip" >> ping_failed.txt
        echo "ping failed: ${ip_prefix}.$ip"
    fi
done

exit 0