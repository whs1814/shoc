#ifndef CUDAPMSMEMMGR_H
#define CUDAPMSMEMMGR_H

#include <stdlib.h>
#include "cudacommon.h"
#include <hip/hip_runtime.h>
#include <hip/hip_runtime_api.h>
#include "PMSMemMgr.h"

template<typename T>
class CUDAPMSMemMgr : public PMSMemMgr<T>
{
public:
    virtual T* AllocHostBuffer( size_t nItems )
    {
        T* ret = NULL;
        size_t nBytes = nItems * sizeof(T);
        CUDA_SAFE_CALL(hipHostMalloc((void**)&ret, nBytes));
        return ret;
    }

    virtual void ReleaseHostBuffer( T* buf )
    {
        CUDA_SAFE_CALL(hipHostFree(buf));
    }
};

#endif // CUDAPMSMEMMGR_H
