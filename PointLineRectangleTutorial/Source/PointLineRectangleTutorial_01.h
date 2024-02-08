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
 version:          1.0.0
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
    
    void paint (juce::Graphics& g) override
    {
        /*!
         creates a trapezoid. All this is a bunch of dots (points) that you connect with paths and then close so you can fill it
         */
        //            g.fillAll (juce::Colours::darkgrey);
        //           g.setColour (juce::Colours::orange);
        //
        //           juce::Path path;
        //           path.startNewSubPath (juce::Point<float> (20, 10));
        //           path.lineTo (juce::Point<float> (50, 10));
        //           path.lineTo (juce::Point<float> (60, 50));
        //           path.lineTo (juce::Point<float> (10, 50));
        //           path.closeSubPath();
        //
        //           g.fillPath (path);
        
        //        g.fillAll (juce::Colours::darkgrey);
        //        g.setColour (juce::Colours::orange);
        
        /* !
         this just creates three random points (not Points but just x,y coordinates) and also lengths within the window bounds
         */
        //
        //        auto& random = juce::Random::getSystemRandom();
        //        juce::Range<int> rectRange (20, getWidth() / 2);
        //        juce::Rectangle<int> rectArea (random.nextInt (rectRange),
        //                                       random.nextInt (rectRange),
        //                                       random.nextInt (rectRange),
        //                                       random.nextInt (rectRange));
        //
        //        g.drawRect (rectArea, 2);
        
        /* !
         this creates a 10 by 10 square in a random place,
         if it happens to be inside the rectangle above its green otherwise cornflower
         */
        //
        //        juce::Rectangle<int> pointArea (10, 10);
        //
        //        juce::Point<int> point (random.nextInt (juce::Range<int> (0, getWidth())),
        //                                random.nextInt (juce::Range<int> (0, getHeight())));
        //        pointArea.setCentre (point);
        //
        //        g.setColour (rectArea.contains (point) ? juce::Colours::limegreen
        //                                               : juce::Colours::cornflowerblue);
        //
        //        g.fillRect (pointArea);
        
        
//        g.fillAll (juce::Colours::darkgrey);
//        g.setColour (juce::Colours::orange);
//
//        juce::Line<float> line (juce::Point<float> (10, 10),
//                                juce::Point<float> (50, 50));
//
//        g.drawLine (line, 2.0f);
//
//        g.fillAll (juce::Colours::darkgrey);
//        g.setColour (juce::Colours::orange);
//
//        auto& random = juce::Random::getSystemRandom();
//
//        juce::Range<int> lineRange (0, getWidth());
//        juce::Array<juce::Line<float>> lines;
//        auto numLines = 10;
//
//        for (auto i = 0; i < numLines; ++i)
//        {
//            juce::Line<float> line ((float) random.nextInt (lineRange),
//                                    (float) random.nextInt (lineRange),
//                                    (float) random.nextInt (lineRange),
//                                    (float) random.nextInt (lineRange));
//
//            lines.add (line);
//            g.drawLine (line, 2.0f);
//        }
//
//        g.setColour (juce::Colours::palegreen);
//        juce::Rectangle<float> pointArea (8, 8);
//
//        for (auto lineI : lines)
//               {
//                   for (auto lineJ : lines)
//                   {
//                       if (lines.indexOf (lineI) != lines.indexOf (lineJ))
//                       {
//                           juce::Point<float> intersection;
//
//                           if (lineI.intersects (lineJ, intersection)) // [2]
//                           {
//                               pointArea.setCentre (intersection);
//                               g.fillEllipse (pointArea);
//                           }
//                       }
//                   }
//               }
        
        
//        g.fillAll (juce::Colours::darkgrey);
//
//        juce::Rectangle<int> area (10, 10, 40, 40);
//
//        auto numSquares = 10;
//
//        for (auto i = 0; i < numSquares; ++i)
//        {
//            g.setColour (getRandomColour());
//            g.fillRect (area);
//
//            area.translate (30, 30); // [3]
//        }
        
        
   
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
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
