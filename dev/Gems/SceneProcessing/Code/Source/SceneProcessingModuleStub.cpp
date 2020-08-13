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

#if !defined(SCENE_PROCESSING_EDITOR)
#include <AzCore/RTTI/RTTI.h>
#include <AzCore/Module/Module.h>

namespace AZ
{
    namespace SceneProcessing
    {
        class SceneProcessingModuleStub
            : public Module
        {
        public:
            AZ_RTTI(SceneProcessingModuleStub, "{23438D63-EA7F-425B-82F2-5B45C072B4E5}", Module);

            SceneProcessingModuleStub()
                : Module()
            {
            }
        };
    } // namespace SceneProcessing
} // namespace AZ

AZ_DECLARE_MODULE_CLASS(SceneProcessing_7c2578f634df4345aca98d671e39b8ab, AZ::SceneProcessing::SceneProcessingModuleStub)
#endif
