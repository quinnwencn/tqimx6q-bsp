#!/bin/bash

log() {
    echo "$(date '+%Y-%m-%d %H:%M:%S') - $1"
}

utils_check_ret() {
    if [ $1 -eq 0 ]; then
        log "[INFO] $2 done!"
    else 
        log "[ERROR] Failed on $2!"
    fi
}

log "[INFO] Starting to run docker container"
docker run \
    --cap-add NET_ADMIN \
    --hostname buildserver \
    -it \
    -v `pwd`/../tqimx6q-bsp:/home/$(whoami)/imx6q \
    builder_1604
utils_check_ret $? "Docker container run"