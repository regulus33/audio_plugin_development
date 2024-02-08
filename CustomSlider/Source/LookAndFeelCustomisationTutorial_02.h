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

 name:             LookAndFeelCustomisationTutorial
 version:          2.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores look and feel customisations.

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
class OtherLookAndFeel : public juce::LookAndFeel_V4
{
public:
    OtherLookAndFeel()
    {
        setColour (juce::Slider::thumbColourId, juce::Colours::red);
    }

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&) override
    {
        auto radius = (float) juce::jmin (width / 2, height / 2) - 4.0f;
        auto centreX = (float) x + (float) width  * 0.5f;
        auto centreY = (float) y + (float) height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto rw = radius * 2.0f;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

        // fill
        g.setColour (juce::Colours::orange);
        g.fillEllipse (rx, ry, rw, rw);

        // outline
        g.setColour (juce::Colours::red);
        g.drawEllipse (rx, ry, rw, rw, 1.0f);

        juce::Path p;
        auto pointerLength = radius * 0.33f;
        auto pointerThickness = 2.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));

        // pointer
        g.setColour (juce::Colours::yellow);
        g.fillPath (p);
    }
};

//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    MainContentComponent()
    {
        dial1.setLookAndFeel (&otherLookAndFeel);
        dial1.setSliderStyle (juce::Slider::Rotary);
        dial1.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
        addAndMakeVisible (dial1);

        dial2.setSliderStyle (juce::Slider::Rotary);
        dial2.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
        addAndMakeVisible (dial2);

        button1.setButtonText ("Button 1");
        addAndMakeVisible (button1);

        button2.setButtonText ("Button 2");
        addAndMakeVisible (button2);

        setSize (300, 200);
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::lightgrey);
    }

    void resized() override
    {
        auto border = 4;

        auto area = getLocalBounds();

        auto dialArea = area.removeFromTop (area.getHeight() / 2);
        dial1.setBounds (dialArea.removeFromLeft (dialArea.getWidth() / 2).reduced (border));
        dial2.setBounds (dialArea.reduced (border));

        auto buttonHeight = 30;

        button1.setBounds (area.removeFromTop (buttonHeight).reduced (border));
        button2.setBounds (area.removeFromTop (buttonHeight).reduced (border));
    }

private:
    OtherLookAndFeel otherLookAndFeel; // [2]
    juce::Slider dial1;
    juce::Slider dial2;
    juce::TextButton button1;
    juce::TextButton button2;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
