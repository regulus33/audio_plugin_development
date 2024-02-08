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

 name:             PointLineRectangleTutorial
 version:          2.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores points lines and rectangles.

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
    MainContentComponent()
    {
        setSize (400, 400);
    }

    void mouseDown (const juce::MouseEvent&) override
    {
        repaint();
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::darkgrey);
        g.setColour (juce::Colours::orange);

        auto& random = juce::Random::getSystemRandom();

        juce::Range<int> rectRange (20, getWidth() / 2);
        juce::Rectangle<int> rectArea (random.nextInt (rectRange),
                                       random.nextInt (rectRange),
                                       random.nextInt (rectRange),
                                       random.nextInt (rectRange));

        g.drawRect (rectArea, 2);

        juce::Rectangle<int> pointArea (10, 10);
        juce::Point<int> point (random.nextInt (juce::Range<int> (0, getWidth())),
                                random.nextInt (juce::Range<int> (0, getHeight())));
        pointArea.setCentre (point);

        g.setColour (rectArea.contains (point) ? juce::Colours::limegreen
                                               : juce::Colours::cornflowerblue);

        g.fillRect (pointArea);
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
