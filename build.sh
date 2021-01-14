#!/bin/bash

keyboard_name=manta42

SCRIPT_DIR=$(cd $(dirname $0); pwd)
keyboard_dir=${SCRIPT_DIR}/${keyboard_name}/

cd ${SCRIPT_DIR}

rm -rf ../qmk_firmware/keyboards/${keyboard_name}
echo cp -rf ${keyboard_dir} ../qmk_firmware/keyboards/
cp -rf ${keyboard_dir} ../qmk_firmware/keyboards/

cd ../qmk_firmware
make ${keyboard_name}:default
#make ${keyboard_name}/rev2/sc:default

if [ ! $? ]; then
	exit 1
fi

cp ${keyboard_name}_rev2_default.hex ../${keyboard_name}
#cp ${keyboard_name}_rev2_sc_default.hex ../${keyboard_name}

echo ls -al ../qmk_firmware/keyboards/${keyboard_name}
ls -al ../qmk_firmware/keyboards/${keyboard_name}

# Qmk Toolboxがwsl上のファイルを書き込めないため
# wslでのビルドを実行したら、ビルド済みのhexファイルをwindows側に転送する
if [ -e /mnt/c/ ]; then # wslで動いていたら のつもり
	# C:\home\work\${keyboard_name}というディレクトリを勝手に掘ってそこに配置する
	dir=/mnt/c/home/work/${keyboard_name}
	if [ $dir ]; then
		mkdir -p $dir
	fi
	echo rm -rf $dir/*
	rm -rf $dir/*
	echo cp -rf ${SCRIPT_DIR}/*.hex $dir
	cp -rf ${SCRIPT_DIR}/*.hex $dir
	echo ls -al $dir
	ls -al $dir
fi


