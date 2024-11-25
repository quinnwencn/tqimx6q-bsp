# !/bin/bash
set -e

docker build --build-arg USER_ID=$(id -u) --build-arg USER_NAME=$(whoami) -t builder_1604 .
if [ $? -eq 0 ]; then 
	echo "Build docker builder_1604 successfully"
else
	echo "Failed to build docker builder_1604"
fi 
