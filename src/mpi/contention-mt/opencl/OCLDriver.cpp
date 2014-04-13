#include <iostream>
#include <stdlib.h>

#include "OpenCLDeviceInfo.h"
#include "OpenCLNodePlatformContainer.h"
#include "Event.h"
#include "support.h"
#include "ResultDatabase.h"
#include "OptionParser.h"

using namespace std;
using namespace SHOC;

void addBenchmarkSpecOptions(OptionParser &op);

void RunBenchmark(cl::Device& id,
                  cl::Context& ctx,
                  cl::CommandQueue& queue,
                  ResultDatabase &resultDB,
                  OptionParser &op);


cl::Device* _mpicontention_ocldev = NULL;
cl::Context* _mpicontention_ocldriver_ctx = NULL;
cl::CommandQueue* _mpicontention_ocldriver_queue = NULL;
OptionParser _mpicontention_gpuop;
ResultDatabase _mpicontention_gpuseqrdb, _mpicontention_gpuwuprdb, _mpicontention_gpusimrdb;

// ****************************************************************************
// Function: GPUSetup
//
// Purpose:
//  do the necessary OpenCL setup for GPU part of the test
//
// Arguments:
//   op: the options parser / parameter database
//   mympirank: for printing errors in case of failure
//   mynoderank: this is typically the device ID (the mapping done in main)
//
// Returns: success/failure
//
// Creation: 2009
//
// Modifications:
//
// ****************************************************************************
//
int GPUSetup(OptionParser &op, int mympirank, int mynoderank)
{
    addBenchmarkSpecOptions(op);

    if (op.getOptionBool("infoDevices"))
    {
        OpenCLNodePlatformContainer ndc1;
        ndc1.Print (cout);
        return (0);
    }

    // The device option supports specifying more than one device
    int platform = op.getOptionInt("platform");
    int deviceIdx = mynoderank;
    if( deviceIdx >= op.getOptionVecInt( "device" ).size() )
    {
        std::ostringstream estr;
        estr << "Warning: not enough devices specified with --device flag for task "
            << mympirank
            << " ( node rank " << mynoderank
            << ") to claim its own device; forcing to use first device ";
        std::cerr << estr.str() << std::endl;
        deviceIdx = 0;
    }
    int device = op.getOptionVecInt("device")[deviceIdx];

    // Initialization
    _mpicontention_ocldev = new cl::Device( ListDevicesAndGetDevice(platform, device) );
    std::vector<cl::Device> ctxDevices;
    ctxDevices.push_back( *_mpicontention_ocldev );
    _mpicontention_ocldriver_ctx   = new cl::Context( ctxDevices );
    _mpicontention_ocldriver_queue = new cl::CommandQueue( *_mpicontention_ocldriver_ctx, *_mpicontention_ocldev, CL_QUEUE_PROFILING_ENABLE );
    _mpicontention_gpuop = op;
    return 0;
}

// ****************************************************************************
// Function: GPUCleanup
//
// Purpose:
//  do the necessary OpenCL cleanup for GPU part of the test
//
// Arguments:
//
// Returns:  nothing
//
// Creation: 2009
//
// Modifications:
//
// ****************************************************************************
//
int GPUCleanup()
{
    delete _mpicontention_ocldriver_queue;
    delete _mpicontention_ocldriver_ctx;
    delete _mpicontention_ocldev;

    return 0;
}

// ****************************************************************************
// Function: GPUDriverwrmup
//
// Purpose:
//  drive the GPU test for the warmup run (no simultaneous MPI)
//
// Arguments:
//
// Returns:  nothing
//
// Creation: 2010
//
// Modifications:
//
// ****************************************************************************
//
void GPUDriverwrmup()
{
    // Run the benchmark
    RunBenchmark(*_mpicontention_ocldev, *_mpicontention_ocldriver_ctx,
                    *_mpicontention_ocldriver_queue, _mpicontention_gpuwuprdb,
                    _mpicontention_gpuop);
}


// ****************************************************************************
// Function: GPUDriverseq
//
// Purpose:
//  drive the GPU test in the standalone case (no simultaneous MPI)
//
// Arguments:
//
// Returns:  nothing
//
// Creation: 2009
//
// Modifications:
//
// ****************************************************************************
//
void GPUDriverseq()
{
    // Run the benchmark
    RunBenchmark( *_mpicontention_ocldev, *_mpicontention_ocldriver_ctx,
                    *_mpicontention_ocldriver_queue, _mpicontention_gpuseqrdb,
                    _mpicontention_gpuop);
}

// ****************************************************************************
// Function: GPUDriversim
//
// Purpose:
//  drive the GPU test in the simultaneous run (with MPI)
//
// Arguments:
//
// Returns:  nothing
//
// Creation: 2009
//
// Modifications:
//
// ****************************************************************************
//
void GPUDriversim()
{
    // Run the benchmark
    RunBenchmark( *_mpicontention_ocldev, *_mpicontention_ocldriver_ctx,
                    *_mpicontention_ocldriver_queue, _mpicontention_gpusimrdb,
                    _mpicontention_gpuop);

}

ResultDatabase &GPUGetsimrdb()
{
    return _mpicontention_gpusimrdb;
}

ResultDatabase &GPUGetseqrdb()
{
    return _mpicontention_gpuseqrdb;
}
