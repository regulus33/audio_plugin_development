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

 name:             FlexBoxGridTutorial
 version:          3.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Responsive layouts using FlexBox and Grid.

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
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public juce::Component
{
public:
    //==============================================================================
    MainContentComponent()
        : rightPanel (juce::Colours::lightgrey),
          leftPanel  (juce::Colours::lightblue)
    {
        addAndMakeVisible (rightPanel);
        addAndMakeVisible (leftPanel);
        addAndMakeVisible (mainPanel);

        setSize (600, 400);
    }

    void paint (juce::Graphics& g) override
    {
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    }

    void resized() override
    {
        juce::FlexBox fb;

        juce::FlexItem left  ((float) getWidth() / 4.0f, (float) getHeight(), leftPanel);
        juce::FlexItem right ((float) getWidth() / 4.0f, (float) getHeight(), rightPanel);
        juce::FlexItem main  ((float) getWidth() / 2.0f, (float) getHeight(), mainPanel);

        fb.items.addArray ( { left, main, right } );
        fb.performLayout (getLocalBounds());
    }

private:
    //==============================================================================
    struct RightSidePanel    : public Component
    {
        RightSidePanel (juce::Colour c) : backgroundColour (c)
        {
            for (int i = 0; i < 10; ++i)
                addAndMakeVisible (buttons.add (new juce::TextButton (juce::String (i))));
        }

        void paint (juce::Graphics& g) override
        {
            g.fillAll (backgroundColour);
        }

        void resized() override
        {
            juce::FlexBox fb;                                               // [1]
            fb.flexWrap = juce::FlexBox::Wrap::wrap;                        // [2]
            fb.justifyContent = juce::FlexBox::JustifyContent::center;      // [3]
            fb.alignContent = juce::FlexBox::AlignContent::center;          // [4]

            for (auto* b : buttons)                                         // [5]
                fb.items.add (juce::FlexItem (*b).withMinWidth (50.0f).withMinHeight (50.0f));

            fb.performLayout (getLocalBounds());                            // [6]
        }

        juce::Colour backgroundColour;
        juce::OwnedArray<juce::TextButton> buttons;
    };

    struct LeftSidePanel    : public Component
    {
        LeftSidePanel (juce::Colour c) : backgroundColour (c)
        {
            for (int i = 0; i < 6; ++i)
            {
                auto* slider = new juce::Slider();
                slider->setSliderStyle (juce::Slider::SliderStyle::Rotary);
                slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);

                addAndMakeVisible (knobs.add (slider));
            }
        }

        void paint (juce::Graphics& g) override
        {
            g.fillAll (backgroundColour);
        }

        void resized() override
        {
            //==============================================================================
            juce::FlexBox knobBox;
            knobBox.flexWrap = juce::FlexBox::Wrap::wrap;
            knobBox.justifyContent = juce::FlexBox::JustifyContent::spaceBetween;                                   // [1]

            for (auto* k : knobs)
                knobBox.items.add (juce::FlexItem (*k).withMinHeight (50.0f).withMinWidth (50.0f).withFlex (1));    // [2]

            //==============================================================================
            juce::FlexBox fb;                                                                                       // [3]
            fb.flexDirection = juce::FlexBox::Direction::column;

            fb.items.add (juce::FlexItem (knobBox).withFlex (2.5));                                                 // [4]

            fb.performLayout (getLocalBounds());
        }

        juce::Colour backgroundColour;
        juce::OwnedArray<juce::Slider> knobs;
    };

    struct MainPanel    : public Component
    {
        MainPanel()
        {
            for (int i = 0; i < 5; ++i)
            {
                addAndMakeVisible (sliders.add (new juce::Slider()));
                sliders.getLast()->setTextBoxStyle (juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
            }
        }

        void paint (juce::Graphics& g) override
        {
            g.fillAll (juce::Colours::hotpink);
        }

        void resized() override
        {
            auto isPortrait = getLocalBounds().getHeight() > getLocalBounds().getWidth();                   // [1]

            juce::FlexBox fb;
            fb.flexDirection = isPortrait ? juce::FlexBox::Direction::column                                // [2]
                                          : juce::FlexBox::Direction::row;

            for (auto* s : sliders)
            {
                s->setSliderStyle (isPortrait ? juce::Slider::SliderStyle::LinearHorizontal                 // [3]
                                              : juce::Slider::SliderStyle::LinearVertical);

                fb.items.add (juce::FlexItem (*s).withFlex (0, 1, isPortrait ? (float) getHeight() / 5.0f   // [4]
                                                                             : (float) getWidth()  / 5.0f));
            }

            fb.performLayout (getLocalBounds());
        }

        juce::OwnedArray<juce::Slider> sliders;
    };

    //==============================================================================
    RightSidePanel rightPanel;
    LeftSidePanel leftPanel;
    MainPanel mainPanel;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
