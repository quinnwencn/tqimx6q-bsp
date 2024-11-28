FROM ubuntu:16.04

ARG USER_ID=1002
ARG USER_NAME=builder
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y software-properties-common
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN dpkg --add-architecture i386
RUN apt-get update

RUN \
    apt-get update && \
    apt-get install locales apt-transport-https ca-certificates curl wget sudo vim -y tofrodos iproute2 gawk xvfb gcc git make net-tools libncurses5-dev zsh \     
	tftpd zlib1g-dev libssl-dev flex bison libselinux1 gnupg diffstat chrpath socat \     
	autoconf libtool tar unzip texinfo gcc-multilib build-essential libsdl1.2-dev libglib2.0-dev  \     
	libssl-dev screen pax gzip net-tools cmake  android-tools-adb android-tools-fastboot      \     
	autoconf  automake bc bison build-essential ccache codespell cscope curl device-tree-compiler \     
	expect flex ftp-upload gdisk libattr1-dev libcap-dev libfdt-dev libftdi-dev libglib2.0-dev   \     
	libgmp-dev libhidapi-dev libmpc-dev libpixman-1-dev libssl-dev libtool make mtools \     
	netcat ninja-build python-crypto python3-crypto python-pyelftools ntpdate \     
	python3-pyelftools rsync unzip uuid-dev xdg-utils xz-utils lzop cpio libcurl4-gnutls-dev \     
	proxychains libqt5qml5 libqt5quick5 libqt5quickwidgets5 qml-module-qtquick2 \     
	libgsettings-qt1 xinetd tftp-hpa aria2 minicom guake \
	openssh-client openssh-server libncursesw5 uuid uuidcdef m4 g++-multilib lib32ncurses5-dev libreadline-dev lib32readline6-dev lib32z1-dev u-boot-tools libxml2-utils jack libz-dev gperf libc6-dev lib32z1 lib32stdc++6 -y

RUN cd /opt && wget https://releases.linaro.org/components/toolchain/binaries/5.3-2016.02/arm-linux-gnueabihf/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz 
RUN cd /opt && tar -xvf gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz
RUN echo "export PATH=$PATH:/opt/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf/bin" > /etc/environment
RUN rm /opt/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz

RUN groupadd -g $USER_ID builder
RUN useradd -m -s /bin/bash -u $USER_ID $USER_NAME && echo "${USER_NAME}:${USER_NAME}" | chpasswd
RUN echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && locale-gen
#RUN LANG en_US.utf-8
USER $USER_NAME
WORKDIR /home/$USER_NAME
RUN git config --global user.email "quinnwen.cn@gmail.com" && git config --global user.name "Quinn Wen"
CMD ["bash", "-c", "source /etc/environment && exec bash"]
