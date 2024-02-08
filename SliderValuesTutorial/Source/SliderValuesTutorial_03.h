/*
  ==============================================================================

   This file is part of the JUCE tutorials.
   Copyright (c) 2020 - Raw Material Software Limited

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             SliderValuesTutorial
 version:          3.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores slider values.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2019, linux_make, xcode_iphone, androidstudio

 type:             Component
 mainClass:        MainContentComponent

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/


#pragma once

//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible (frequencySlider);
        frequencySlider.setRange (50, 5000.0);
        frequencySlider.setTextValueSuffix (" Hz");
        frequencySlider.onValueChange = [this] { durationSlider.setValue (1.0 / frequencySlider.getValue(), juce::dontSendNotification); };

        addAndMakeVisible (frequencyLabel);
        frequencyLabel.setText ("Frequency", juce::dontSendNotification);
        frequencyLabel.attachToComponent (&frequencySlider, true);

        addAndMakeVisible (durationSlider);
        durationSlider.setRange (1.0 / frequencySlider.getMaximum(),
                                 1.0 / frequencySlider.getMinimum());
        durationSlider.setTextValueSuffix (" s");
        durationSlider.onValueChange = [this] { frequencySlider.setValue (1.0 / durationSlider.getValue(), juce::dontSendNotification); };

        addAndMakeVisible (durationLabel);
        durationLabel.setText ("Duration", juce::dontSendNotification);
        durationLabel.attachToComponent (&durationSlider, true);

        frequencySlider.setValue (500.0);

        // make the text boxes wider
        frequencySlider.setTextBoxStyle (juce::Slider::TextBoxLeft, false, 160, frequencySlider.getTextBoxHeight());
        durationSlider .setTextBoxStyle (juce::Slider::TextBoxLeft, false, 160, durationSlider .getTextBoxHeight());

        // change the skew of the sliders
        frequencySlider.setSkewFactorFromMidPoint (500);
        durationSlider .setSkewFactorFromMidPoint (0.002);

        setSize (600, 90);
    }

    void resized() override
    {
        auto sliderLeft = 120;
        frequencySlider.setBounds (sliderLeft, 20, getWidth() - sliderLeft - 10, 20);
        durationSlider .setBounds (sliderLeft, 50, getWidth() - sliderLeft - 10, 20);
    }

private:
    juce::Slider frequencySlider;
    juce::Label  frequencyLabel;
    juce::Slider durationSlider;
    juce::Label  durationLabel;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
