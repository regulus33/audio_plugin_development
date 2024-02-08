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
 
 name:             ListenersAndBroadcastersTutorial
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Explores listeners and broadcasters.
 
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
class MainContentComponent   : public juce::Component, public juce::Button::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible (checkTheTimeButton);
        checkTheTimeButton.setButtonText ("Check the time...");
        /*! here is the crucial part! HEADS UP! You need to actually tell the button you are listening */
        checkTheTimeButton.addListener (this); // [7]
        
        addAndMakeVisible (timeLabel);
        
        timeLabel.setColour (juce::Label::backgroundColourId, juce::Colours::black);
        timeLabel.setColour (juce::Label::textColourId, juce::Colours::white);
        timeLabel.setJustificationType (juce::Justification::centred);
        
        setSize (600, 110);
    }
    
    ~MainContentComponent()
    {
        checkTheTimeButton.removeListener (this);
    }
    
    void resized() override
    {
        checkTheTimeButton.setBounds (10, 10, getWidth() - 20, 40);
        timeLabel         .setBounds (10, 60, getWidth() - 20, 40);
    }
    
    // its an override from juce::Button::Listener
    void buttonClicked (juce::Button* button) override  // [2]
    {
        // check if its the same object. this would trigger in any case where any juce::Button was clicked.
        if (button == &checkTheTimeButton)                                                      // [3]
        {
            juce::Time currentTime = juce::Time::getCurrentTime();
            auto difference = currentTime - lastTime;
//            difference
//            timeLabel.setText(juce::String(difference), juce::dontSendNotification);
            // [6]
        }
    }
    
private:
    juce::TextButton checkTheTimeButton;
    juce::Label timeLabel;
    juce::Time lastTime;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
