
## Dependencies

### ros-melodic-desktop-full
使用国内源安装步骤如下：
```sh
sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.tuna.tsinghua.edu.cn/ros/ubuntu/ $DISTRIB_CODENAME main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

sudo apt update

sudo apt install ros-melodic-desktop-full

echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc

source ~/.bashrc

sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential

sudo apt install python-rosdep

sudo rosdep init

rosdep update
```

### ros-melodic-base-local-planner

```
sudo apt install ros-melodic-base-local-planner
```

### ros-melodic-costmap-converter
```
sudo apt install ros-melodic-costmap-converter
```

sudo apt install ros-melodic-mbf-costmap-core

sudo apt install ros-melodic-mbf-msgs

sudo apt-get install libsuitesparse-dev
 
sudo apt-get install ros-melodic-libg2o

### lcm

```
git clone https://github.com/lcm-proj/lcm.git
cd lcm
mkdir build
cd build
cmake ..
mak -j4
sudo make install

cd ../lcm_python
python3 setup.py install
```

### libxmlrpcpp-dev
sudo apt install libxmlrpcpp-dev

sudo apt install librosconsole-dev
