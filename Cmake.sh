#!/bin/bash

################################################################################
# Description: Script to build shoc heterogeneous benchmark.
# Author     : WangHongsheng [NSCCZZ].
# Time       : 2022-07-07 17:24:00
# Note       : CMake 3.21 or higher is required while building for hip.
#              Only one target (HIP or CUDA) can be specified at a time.
################################################################################

#cmake ../shoc -DENABLE_HIP=ON -DENABLE_MPI=ON -DENABLE_CUDA=OFF -DHIP_ARCH=gfx906:sramecc-:xnack-
SHOC_SRC=$HOME/Workspace/BenchMark/shoc
SHOC_BUILD_DIR=$HOME/Workspace/BenchMark/shoc_build_hip_nompi

if [ ! -d $SHOC_BUILD_DIR ]; then
  mkdir -p $SHOC_BUILD_DIR
else
  rm -rf $SHOC_BUILD_DIR
  mkdir -p $SHOC_BUILD_DIR
fi

cd $SHOC_BUILD_DIR
cmake -G "Unix Makefiles" $SHOC_SRC \
  -DCMAKE_INSTALL_PREFIX=$HOME/Workspace/BenchMark/shoc_tools_hip_nompi \
  -DCMAKE_BUILD_TYPE="Release" \
  -DHIP_ARCH=gfx906:sramecc-:xnack- \
  -DENABLE_CUDA=OFF \
  -DENABLE_MPI=OFF \
  -DENABLE_HIP=ON #--trace
#  -DCMAKE_HIP_FLAGS="-save-temps " \
#  -DCUDA_ARCH=70 \

#  -DCMAKE_CXX_LINK_EXECUTABLE="mpicxx" \
#  -DCMAKE_LINKER=/opt/hpc/software/mpi/hpcx/v2.7.4/gcc-7.3.1/bin/mpicxx \
