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
 version:          4.0.0
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

    static juce::Colour getRandomColour()
    {
        auto& random = juce::Random::getSystemRandom();

        return juce::Colour ((juce::uint8) random.nextInt (256),
                             (juce::uint8) random.nextInt (256),
                             (juce::uint8) random.nextInt (256));
    }

    void mouseDown (const juce::MouseEvent&) override
    {
        repaint();
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::darkgrey);

        juce::Rectangle<int> area (10, 10, 40, 40);

        auto& random = juce::Random::getSystemRandom();
        juce::Range<int> rectRandomRange (20, 40);
        auto numSquares = 10;

        for (auto i = 0; i < numSquares; ++i)
        {
            auto nextArea = area + juce::Point<int> (random.nextInt (rectRandomRange),  // [5]
                                                     random.nextInt (rectRandomRange));

            g.setColour (getRandomColour());
            g.fillRect (area.getIntersection (nextArea));                               // [6]

            g.setColour (getRandomColour());
            g.drawRect (area, 2);                                                       // [7]

            area = nextArea;
        }
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
