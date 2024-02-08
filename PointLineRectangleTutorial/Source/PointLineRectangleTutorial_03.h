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
 version:          3.0.0
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

        juce::Range<int> lineRange (0, getWidth());
        juce::Array<juce::Line<float>> lines;
        auto numLines = 10;

        for (auto i = 0; i < numLines; ++i)
        {
            juce::Line<float> line ((float) random.nextInt (lineRange),
                                    (float) random.nextInt (lineRange),
                                    (float) random.nextInt (lineRange),
                                    (float) random.nextInt (lineRange));

            lines.add (line);
            g.drawLine (line, 2.0f);
        }

        g.setColour (juce::Colours::palegreen);
        juce::Rectangle<float> pointArea (8, 8);

        for (auto lineI : lines)
        {
            for (auto lineJ : lines)
            {
                if (lines.indexOf (lineI) != lines.indexOf (lineJ))
                {
                    juce::Point<float> intersection;

                    if (lineI.intersects (lineJ, intersection)) // [2]
                    {
                        pointArea.setCentre (intersection);
                        g.fillEllipse (pointArea);
                    }
                }
            }
        }
    }

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
