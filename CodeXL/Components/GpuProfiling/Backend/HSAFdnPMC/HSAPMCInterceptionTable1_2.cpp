//==============================================================================
// Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  This file defines the interceptor helpers for the 1.2 runtime
//==============================================================================

#include <cstdlib>
#include <cstring>

#include "AutoGenerated/HSAPMCInterception.h"
#include "HSAPMCInterceptionTable1_2.h"

#ifdef FUTURE_ROCR_VERSION

/// Intercepts HSA APIs for this HSA Profiler agent
void InitHSAAPIInterceptPMC1_2(HsaApiTable1_2* pTable)
{
    // minor_id gets set to the size of the struct
    g_pRealCoreFunctions = (CoreApiTable*)malloc(pTable->core_->version.minor_id);
    memcpy(g_pRealCoreFunctions, pTable->core_, pTable->core_->version.minor_id);

    g_pRealFinalizerExtFunctions = (FinalizerExtTable*)malloc(pTable->finalizer_ext_->version.minor_id);
    memcpy(g_pRealFinalizerExtFunctions, pTable->finalizer_ext_, pTable->finalizer_ext_->version.minor_id);

    g_pRealImageExtFunctions = (ImageExtTable*)malloc(pTable->image_ext_->version.minor_id);
    memcpy(g_pRealImageExtFunctions, pTable->image_ext_, pTable->image_ext_->version.minor_id);

    g_pRealAmdExtFunctions = (AmdExtTable*)malloc(pTable->amd_ext_->version.minor_id);
    memcpy(g_pRealAmdExtFunctions, pTable->amd_ext_, pTable->amd_ext_->version.minor_id);

    pTable->core_->hsa_agent_get_info_fn = HSA_PMC_hsa_agent_get_info;
    pTable->core_->hsa_queue_create_fn = HSA_PMC_hsa_queue_create;
    pTable->core_->hsa_queue_destroy_fn = HSA_PMC_hsa_queue_destroy;
    pTable->core_->hsa_executable_get_symbol_fn = HSA_PMC_hsa_executable_get_symbol;
    pTable->core_->hsa_iterate_agents_fn = HSA_PMC_hsa_iterate_agents;
}

#endif
