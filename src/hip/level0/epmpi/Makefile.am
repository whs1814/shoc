include $(top_builddir)/config/config.mk
include $(top_builddir)/config/targets.mk

# How to find source files
VPATH = $(srcdir)/..:$(srcdir)/../../common

# Which compiler to use to link
CXX = ${HIPCC}
CXXLD = ${HIPCC}

AM_LDFLAGS = $(HIP_LDFLAGS)
AM_CPPFLAGS = $(HIP_INC) $(MPI_CPPFLAGS) -I$(top_srcdir)/src/mpi/common -I$(top_srcdir)/src/hip/common -D__HIP_PLATFORM_HCC__ -I$(HIP_PATH)/include -I/usr/lib/openmpi/include -Wdeprecated-register 

# What is the destination for programs built from this directory?
epcudadir = $(bindir)/EP/HIP

# What programs should be installed in the destination?
epcuda_PROGRAMS = BusSpeedDownload \
						BusSpeedReadback \
						DeviceMemory \
						MaxFlops

BusSpeedDownload_SOURCES	= main.cpp
BusSpeedDownload_LDADD		= BusSpeedDownload.o  -lstdc++ -lSHOCCommon -L$(ROCM_PATH)/lib -L$(ROCM_PATH)/hsa/lib -lhsa-runtime64 -ldl -lpthread -lm -L/usr/lib/openmpi/lib -lmpi -lhwloc $(HIP_LIBS) $(LIBS) 

BusSpeedReadback_SOURCES	= main.cpp
BusSpeedReadback_LDADD		= BusSpeedReadback.o  -lstdc++ -lSHOCCommon -L$(ROCM_PATH)/lib -L$(ROCM_PATH)/hsa/lib -lhsa-runtime64 -ldl -lpthread -lm -L/usr/lib/openmpi/lib -lmpi -lhwloc $(HIP_LIBS) $(LIBS) 

DeviceMemory_SOURCES	= main.cpp
DeviceMemory_LDADD		= DeviceMemory.o  -lstdc++ -L$(ROCM_PATH)/lib -L$(ROCM_PATH)/hsa/lib -lhsa-runtime64 -ldl -lpthread -lm -lSHOCCommon -L/usr/lib/openmpi/lib -lmpi -lhwloc $(HIP_LIBS) $(LIBS) 

MaxFlops_SOURCES	= main.cpp
MaxFlops_LDADD		= MaxFlops.o  -lstdc++ -L$(ROCM_PATH)/lib -L$(ROCM_PATH)/hsa/lib -lhsa-runtime64 -ldl -lpthread -lm -lSHOCCommon -L/usr/lib/openmpi/lib -lmpi -lhwloc $(HIP_LIBS) $(LIBS) 

