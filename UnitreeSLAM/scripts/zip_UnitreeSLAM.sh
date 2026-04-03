#!/bin/bash
#author: Lingbo Meng
#date: 2022.01.20
#brief: This script backup UnitreeSLAM to a zip file

DOG="aliengo"
PLATFORM="x86"
SLAM_TYPE="3dslam"
LEGGED_SDK_VERSION="aliengosdk1.0.17"
DATE=$(date +%Y%m%d)

SRC_DIR="UnitreeSLAM"

DST_NAME="UnitreeSLAM_deploy_${DOG}_${PLATFORM}_${SLAM_TYPE}_sdk${LEGGED_SDK_VERSION}_v${DATE}"


#
cd ${HOME}
if [ -e "${DST_NAME}.zip" ]; then
  echo "The target file already exist! Removing it now ..."
  rm -rf "${DST_NAME}.zip"
  echo -e "Removed!!!\n"
fi

echo -e "Zipping files ..."
zip -r "${DST_NAME}.zip" ${SRC_DIR} &> /dev/null
echo -e "Finished!"

exit 0