/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <ScriptCanvas/Data/Data.h>

namespace ScriptCanvas
{
    namespace Data
    {
        AZ_INLINE NumberType One() { return 1.0; }
        AZ_INLINE NumberType ToleranceEpsilon() { return FromVectorFloat(AZ::g_fltEps); }
        AZ_INLINE NumberType ToleranceSIMD() { return 0.01; }
        AZ_INLINE NumberType Zero() { return 0.0; }
    }
} // namespace ScriptCanvas