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

 name:             ColoursTutorial
 version:          2.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores colours.

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
    class CustomLookAndFeel  : public juce::LookAndFeel_V4
    {
    public:
        CustomLookAndFeel()
        {
            setColour (juce::Slider::thumbColourId, juce::Colours::red);
        }
    };

    MainContentComponent()
    {
        setLookAndFeel (&lf); // [4]

        label.setEditable (true);
        addAndMakeVisible (label);

        textEditor.setText ("This is a text editor.");
        addAndMakeVisible (textEditor);

        textButton.setClickingTogglesState (true);
        addAndMakeVisible (textButton);

        addAndMakeVisible (slider1);
        addAndMakeVisible (slider2);

        setSize (600, 210);
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::lightgreen);
        g.setColour (juce::Colours::orange);

        auto centralArea = getLocalBounds().toFloat().reduced (10.0f);
        g.drawRoundedRectangle (centralArea, 5.0f, 3.0f);

        juce::Array<juce::Colour> colours { juce::Colours::red, juce::Colours::green, juce::Colours::blue };

        auto colourBarArea = centralArea.reduced (4.0f).withHeight (20.0f);
        auto colourArea = colourBarArea.withWidth (colourBarArea.getWidth() / (float) colours.size());

        for (auto colour : colours)
        {
            g.setColour (colour);
            g.fillRect (colourArea);

            colourArea.translate (colourArea.getWidth(), 0.0f);
        }
    }

    void resized() override
    {
        label     .setBounds (20, 40,  getWidth() - 40, 20);
        textEditor.setBounds (20, 70,  getWidth() - 40, 20);
        textButton.setBounds (20, 100, getWidth() - 40, 20);
        slider1   .setBounds (20, 130, getWidth() - 40, 20);
        slider2   .setBounds (20, 160, getWidth() - 40, 20);
    }

private:
    CustomLookAndFeel lf; // [3]
    juce::Label label            { {}, "This is some label text." };
    juce::TextButton textButton  { "This is a button" };
    juce::TextEditor textEditor;
    juce::Slider slider1;
    juce::Slider slider2;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
