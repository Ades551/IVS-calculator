#! /bin/bash

read -p "Project name: " PROJECT_NAME
read -p "Project version: " PROJECT_VER
read -p "Project revision: " PROJECT_REV
read -p "Project architecture: " PROJECT_ARCH

PROJECT_PACK_NAME="${PROJECT_NAME}_${PROJECT_VER}-${PROJECT_REV}_${PROJECT_ARCH}"

mkdir -p "installer/${PROJECT_PACK_NAME}/usr/local/bin" && cp ./build/calc "./installer/${PROJECT_PACK_NAME}/usr/local/bin" && mkdir -p "./installer/${PROJECT_PACK_NAME}/DEBIAN"

read -p "Create auto generated control file? [Y/n]: " input

printf "Package: ${PROJECT_NAME}\nVersion: ${PROJECT_VER}\nArchitecture: ${PROJECT_ARCH}\nMaintainer: Not set\nDescription: Not set\n" > "./installer/${PROJECT_PACK_NAME}/DEBIAN/control"

if [ "$input" == "n" ] || [ "$input" == "N" ]; then
    nano "./installer/${PROJECT_PACK_NAME}/DEBIAN/control"
fi

wait
cd ./installer && dpkg-deb --build --root-owner-group "${PROJECT_PACK_NAME}"
