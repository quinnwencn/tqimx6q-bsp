#!/bin/bash
set -e

echo "[INFO] Building uboot..."
cd uboot_imx && ./build.sh
echo "[INFO] Successfully build uboot!"

cd ../
echo "[INFO] Building kernel..."
cd kernel_imx && ./build.sh
echo "[INFO] Successfully build kernel"
 
