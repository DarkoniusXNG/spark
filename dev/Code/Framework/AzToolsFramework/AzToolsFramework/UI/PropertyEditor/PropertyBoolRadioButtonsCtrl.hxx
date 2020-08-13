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

#include <AzCore/base.h>
#include <AzCore/Memory/SystemAllocator.h>
#include <AzToolsFramework/UI/PropertyEditor/PropertyEditorAPI.h>

#include <QtWidgets/QWidget>

class QRadioButton;

namespace AzToolsFramework
{
    /*
    * Class which handles displaying a boolean value as two radio buttons in the UI
    * Text defaults to "False" and "True", and the "False" radio button is rendered first, and has first tab order
    * To change the default display text for "False" and "True",
    * use AZ::Edit::Attributes::FalseText or AZ::Edit::Attributes::TrueText repsectively
    */
    class PropertyBoolRadioButtonsCtrl
        : public QWidget
    {
        Q_OBJECT
    public:
        AZ_CLASS_ALLOCATOR(PropertyBoolRadioButtonsCtrl, AZ::SystemAllocator, 0);

        explicit PropertyBoolRadioButtonsCtrl(QWidget* pParent = nullptr);
        ~PropertyBoolRadioButtonsCtrl() override = default;

        bool value() const;

        QWidget* GetFirstInTabOrder();
        QWidget* GetLastInTabOrder();
        void UpdateTabOrder();
        void SetButtonText(bool value, const char* description);

    signals:
        void valueChanged(bool newValue);

    public slots:
        void setValue(bool val);

    protected slots:
        void onRadioButtonSelected(int value);

    private:
        QButtonGroup* m_buttonGroup;
        static const int s_trueButtonIndex;
        static const int s_falseButtonIndex;
    };

    /*
    * Property handler for use with the PropertyBoolRadioButtonsCtrl
    * To use this handler, create a reflected boolean variable and use handler name AZ::Edit::Handlers::RadioButton
    */
    class BoolPropertyRadioButtonsHandler
        : QObject
        , public PropertyHandler<bool, PropertyBoolRadioButtonsCtrl>
    {
        Q_OBJECT
    public:
        AZ_CLASS_ALLOCATOR(BoolPropertyRadioButtonsHandler, AZ::SystemAllocator, 0);
        ~BoolPropertyRadioButtonsHandler() override = default;

        AZ::u32 GetHandlerName() const override;
        QWidget* GetFirstInTabOrder(PropertyBoolRadioButtonsCtrl* widget) override;
        QWidget* GetLastInTabOrder(PropertyBoolRadioButtonsCtrl* widget) override;
        void UpdateWidgetInternalTabbing(PropertyBoolRadioButtonsCtrl* widget) override;

        QWidget* CreateGUI(QWidget* pParent) override;
        void ConsumeAttribute(PropertyBoolRadioButtonsCtrl* GUI, AZ::u32 attrib, PropertyAttributeReader* attrValue, const char* debugName) override;
        void WriteGUIValuesIntoProperty(size_t index, PropertyBoolRadioButtonsCtrl* GUI, property_t& instance, InstanceDataNode* node) override;
        bool ReadValuesIntoGUI(size_t index, PropertyBoolRadioButtonsCtrl* GUI, const property_t& instance, InstanceDataNode* node)  override;
    };

    void RegisterBoolRadioButtonsHandler();
};
