#! /bin/bash

read -p "Project name: " PROJECT_NAME
read -p "Project version: " PROJECT_VER
read -p "Project revision: " PROJECT_REV
read -p "Project architecture: " PROJECT_ARCH


PROJECT_PACK_NAME="${PROJECT_NAME}_${PROJECT_VER}-${PROJECT_REV}_Linux"
INSTALL_DIR="${PROJECT_PACK_NAME}"
DEPENDS="libqt5widgets5"

mkdir -p "${INSTALL_DIR}/usr/local/bin" && cp "./../build/${PROJECT_NAME}" "${INSTALL_DIR}/usr/local/bin" && mkdir -p "${INSTALL_DIR}/DEBIAN" && mkdir -p "${INSTALL_DIR}/usr/share/applications/" && mkdir -p "${INSTALL_DIR}/opt/ivs-calc" && cp ivs-calc.png "${INSTALL_DIR}/opt/ivs-calc"

## CONTROL FILE
read -p "Create auto generated control file? [Y/n]: " input

printf "Package: ${PROJECT_NAME}
Version: ${PROJECT_VER}
Architecture: ${PROJECT_ARCH}
Maintainer: Not set
Description: Not set
Depends: ${DEPENDS}\n" > "${INSTALL_DIR}/DEBIAN/control"

if [ "$input" == "n" ] || [ "$input" == "N" ]; then
    nano "${INSTALL_DIR}/DEBIAN/control"
fi

wait

## DESKTOP FILE
read -p "Create auto generated desktop file? [Y/n]: " input

printf "[Desktop Entry]
Name=${PROJECT_NAME}
Version=${PROJECT_VER}
Icon=/opt/ivs-calc/ivs-calc.png
Type=Application
Exec=/usr/local/bin/ivs-calc\n" > "${INSTALL_DIR}/usr/share/applications/${PROJECT_NAME}.desktop"

if [ "$input" == "n" ] || [ "$input" == "N" ]; then
    nano "${INSTALL_DIR}/usr/share/application/${PROJECT_NAME}.desktop"
fi

wait

## POSTINST
read -p "Create auto generated postinst file? [Y/n]: " input

printf "#!/bin/bash

desktop-file-install /usr/share/applications/ivs-calc.desktop" > "${INSTALL_DIR}/DEBIAN/postinst"

chmod 0755 "${INSTALL_DIR}/DEBIAN/postinst"

if [ "$input" == "n" ] || [ "$input" == "N" ]; then
    nano "${INSTALL_DIR}/DEBIAN/postinst"
fi

wait

dpkg-deb --build --root-owner-group "${INSTALL_DIR}"
