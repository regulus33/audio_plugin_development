/*
  ==============================================================================

    MainComponent.cpp
    Created: 16 May 2023 1:50:10am
    Author:  zack

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize(800, 500);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint (juce::Graphics& g)
{
    juce::Font mainComponentFont("Times New Roman", 20.0f, juce::Font::italic);
    g.fillAll(juce::Colours::lightblue);
    g.setColour(juce::Colours::darkblue);
    g.setFont(mainComponentFont);
    /*! Kind of like absolute positioning. Means, render text into an area 200 px wide, 40 px high, 20 px to the right and 40 px from the top */
    /*! COORDINATES in Juce are always measured fromt the top left corner of the component, that is 0, 0 */
    g.drawText("Welcome home son!", 20, 40, 200, 40, juce::Justification::centred, true);
    
    g.setColour(juce::Colours::sandybrown);
//    g.fillRect(300, 120, 200, 170);
    juce::Rectangle<float> house (300, 120, 200, 170);
    juce::Rectangle<int> ground (0, 300, 800, 10);
    g.setColour(juce::Colours::sandybrown);
    g.fillCheckerBoard(house, 30, 10, juce::Colours::sandybrown, juce::Colours::saddlebrown);
    g.setColour(juce::Colours::green);
    g.fillRect(ground);
    g.setColour(juce::Colours::yellow);
    g.drawEllipse(getWidth() - 300, 10, 60, 60, 3);
    g.setColour(juce::Colours::red);
    juce::Path roof;
    roof.addTriangle(300, 110, 500, 110, 400, 70);
    g.fillPath(roof);
}


void MainComponent::resized()
{
    currentSizeAsString = juce::String(getWidth()) + " x " + juce::String(getHeight());
}
