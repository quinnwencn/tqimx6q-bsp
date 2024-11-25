FROM ubuntu:16.04
MAINTAINER Quinn Wen <quinnwen.cn@gmail.com>

ARG USER_ID=1002
ARG USER_NAME=builder
ARG DEBIAN_FRONTEND=noninteractive
RUN mv /etc/apt/sources.list /etc/apt/sources.list.bak

RUN \
    apt-get update && \
    apt-get install locales apt-transport-https ca-certificates curl wget sudo vim -y && \
	apt-get install tofrodos iproute2 gawk xvfb gcc git make net-tools libncurses5-dev zsh \     
	tftpd zlib1g-dev libssl-dev flex bison libselinux1 gnupg wget diffstat chrpath socat \     
	autoconf libtool tar unzip texinfo gcc-multilib build-essential libsdl1.2-dev libglib2.0-dev  \     
	libssl-dev screen pax gzip vim net-tools cmake  android-tools-adb android-tools-fastboot      \     
	autoconf  automake bc bison build-essential ccache codespell cscope curl device-tree-compiler \     
	expect flex ftp-upload gdisk libattr1-dev libcap-dev libfdt-dev libftdi-dev libglib2.0-dev   \     
	libgmp-dev libhidapi-dev libmpc-dev libpixman-1-dev libssl-dev libtool make mtools \     
	netcat ninja-build python-crypto python3-crypto python-pyelftools ntpdate \     
	python3-pyelftools rsync unzip uuid-dev xdg-utils xz-utils lzop cpio libcurl4-gnutls-dev \     
	zlib1g-dev proxychains libqt5qml5 libqt5quick5 libqt5quickwidgets5 qml-module-qtquick2 \     
	libgsettings-qt1 xinetd tftp-hpa aria2 minicom guake openssh-client openssh-server libncursesw5 -y
	
RUN useradd -m -s /bin/bash -u $USER_ID $USER_NAME
RUN groupadd -g $USER_ID builder
RUN echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && locale-gen
RUN LANG en_US.utf-8
USER $USER_NAME
WORKDIR /home/$USER_NAME
RUN git config --global user.email "quinnwen.cn@gmail.com" && git config --global user.name "Quinn Wen"
	
    
