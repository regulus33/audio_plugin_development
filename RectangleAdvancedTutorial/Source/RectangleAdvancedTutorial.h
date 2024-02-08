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
 
 name:             RectangleAdvancedTutorial
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Displays rectangles.
 
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
        header.setColour (juce::TextButton::buttonColourId, juce::Colours::cornflowerblue);
        header.setButtonText ("Header");
        addAndMakeVisible (header);
        
        footer.setColour (juce::TextButton::buttonColourId, juce::Colours::cornflowerblue);
        footer.setButtonText ("Footer");
        addAndMakeVisible (footer);
        
        sidebar.setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
        sidebar.setButtonText ("Sidebar");
        addAndMakeVisible (sidebar);
        
        limeContent.setColour (juce::TextButton::buttonColourId, juce::Colours::lime);
        addAndMakeVisible (limeContent);
        
        grapefruitContent.setColour (juce::TextButton::buttonColourId, juce::Colours::yellowgreen);
        addAndMakeVisible (grapefruitContent);
        
        lemonContent.setColour (juce::TextButton::buttonColourId, juce::Colours::yellow);
        addAndMakeVisible (lemonContent);
        
        orangeContent.setColour (juce::TextButton::buttonColourId, juce::Colours::orange);
        addAndMakeVisible (orangeContent);
        
     
        sideItemA.setColour (juce::TextButton::buttonColourId, juce::Colours::maroon);
        sideItemB.setColour (juce::TextButton::buttonColourId, juce::Colours::maroon);
        sideItemC.setColour (juce::TextButton::buttonColourId, juce::Colours::maroon);
        sideItemA.setButtonText ("Item A");
        sideItemB.setButtonText ("Item B");
        sideItemC.setButtonText ("Item C");
        addAndMakeVisible (sideItemA);
        addAndMakeVisible (sideItemB);
        addAndMakeVisible (sideItemC);
        
        
        setSize (400, 400);
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::darkgrey);
    }
    
    void resized() override
    {
        auto area = getLocalBounds();
        
        auto headerFooterHeight = 50;
        header.setBounds (area.removeFromTop    (headerFooterHeight));
        footer.setBounds (area.removeFromBottom (headerFooterHeight));
        
        
        
        
        auto sideBarArea = area.removeFromRight (juce::jmax (80, area.getWidth() / 4));
          sidebar.setBounds (sideBarArea);
        
        auto sideItemHeight = 40;
          auto sideItemMargin = 5;
          sideItemA.setBounds (sideBarArea.removeFromTop (sideItemHeight).reduced (sideItemMargin));
          sideItemB.setBounds (sideBarArea.removeFromTop (sideItemHeight).reduced (sideItemMargin));
          sideItemC.setBounds (sideBarArea.removeFromTop (sideItemHeight).reduced (sideItemMargin));
        
        auto contentItemHeight = 24;
        lemonContent.setBounds      (area.removeFromTop (contentItemHeight));
        orangeContent.setBounds     (area.removeFromTop (contentItemHeight));
        limeContent.setBounds       (area.removeFromTop (contentItemHeight)); // [1]
        grapefruitContent.setBounds (area.removeFromTop (contentItemHeight));
        
        
        
    }
    
private:
    juce::TextButton header;
    juce::TextButton sidebar;
    
    juce::TextButton limeContent;
    juce::TextButton grapefruitContent;
    juce::TextButton lemonContent;
    juce::TextButton orangeContent;
    juce::TextButton footer;
    juce::TextButton sideItemA; // [3]
    juce::TextButton sideItemB; // [4]
    juce::TextButton sideItemC; // [5]
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
