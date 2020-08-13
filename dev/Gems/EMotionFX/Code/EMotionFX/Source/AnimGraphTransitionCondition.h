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

#include "EMotionFXConfig.h"
#include "AnimGraphObject.h"


namespace EMotionFX
{
    // forward declarations
    class AnimGraphInstance;

    class EMFX_API AnimGraphTransitionCondition
        : public AnimGraphObject
    {
    public:
        AZ_RTTI(AnimGraphTransitionCondition, "{DD14D0C7-AC88-4F90-BB4C-0F6810A6BAE7}", AnimGraphObject)
        AZ_CLASS_ALLOCATOR_DECL

        AnimGraphTransitionCondition();
        virtual ~AnimGraphTransitionCondition();

        bool InitAfterLoading(AnimGraph* animGraph) override;

        virtual bool TestCondition(AnimGraphInstance* animGraphInstance) const = 0;
        virtual void Reset(AnimGraphInstance* animGraphInstance)       { MCORE_UNUSED(animGraphInstance); }

        ECategory GetPaletteCategory() const override;

        // Returns an attribute string (MCore::CommandLine formatted) if this condition is affected by a convertion of
        // node ids. The method will return the attribute string that will be used to patch this condition on a command
        virtual void GetAttributeStringForAffectedNodeIds(const AZStd::unordered_map<AZ::u64, AZ::u64>& convertedIds, AZStd::string& attributesString) const;

        static void Reflect(AZ::ReflectContext* context);        
    };
} // namespace EMotionFX