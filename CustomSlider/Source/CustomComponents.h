#pragma once
#include <JuceHeader.h>

class CustomSlider : public juce::Slider {
public:
    CustomSlider(juce::String test) : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
                                                   juce::Slider::TextEntryBoxPosition::NoTextBox),
    test(test)
    {
        setSliderStyle(SliderStyle::Rotary);
        
        auto imageBytes = BinaryData::SliderRed_png;
        auto imageSize = BinaryData::SliderRed_pngSize;
        
        juce::MemoryInputStream imageStream(imageBytes, imageSize, false);
        sliderImage = juce::PNGImageFormat().decodeImage(imageStream);
        
        // Check if the image loaded correctly
        if (!sliderImage.isValid())
        {
            // Handle error
            DBG("Slider image failed to load");
        }
        
    }
    
    void resized()
    {
        //        sliderImage.setBounds(getLocalBounds());
    }
    
    void paint (juce::Graphics& g) override
    {
        auto bounds = getLocalBounds().toFloat();
        auto size = juce::jmin(bounds.getWidth(), bounds.getHeight());
        auto squareBounds = bounds.withSizeKeepingCentre(size, size).toFloat();
        
        auto rotationPoint = squareBounds.getCentre();
        float angle = (float)getProportionOfLength() * 2.0f * juce::MathConstants<float>::pi; // Convert proportion to angle in radians
        
        g.addTransform(juce::AffineTransform::rotation(angle, rotationPoint.getX(), rotationPoint.getY()));
        g.drawImage(sliderImage, squareBounds);
    }
    
    
    float getProportionOfLength()
    {
        return (getValue() - getMinimum()) / (getMaximum() - getMinimum());
    }
    
protected:
    juce::String test;
    juce::Image sliderImage;
    
};

//==============================================================================
class MainContentComponent   : public juce::Component
{
public:
    MainContentComponent() : customSlider("test")
    {
        
        customSlider.setSliderStyle (juce::Slider::Rotary);
        addAndMakeVisible (customSlider);
        
        button1.setButtonText ("Button 1");
        addAndMakeVisible (button1);
        
        button2.setButtonText ("Button 2");
        addAndMakeVisible (button2);
        
        setSize (300, 200);
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colour::fromRGB(36,36,36));
    }
    
    void resized() override
    {
        auto border = 4;
        
        auto area = getLocalBounds();
        
        auto dialArea = area.removeFromTop (area.getHeight() / 2);
        customSlider.setBounds (dialArea.removeFromLeft (dialArea.getWidth() / 2).reduced (border));
        
        dial2.setBounds (dialArea.reduced (border));
        
        auto buttonHeight = 30;
        
        button1.setBounds (area.removeFromTop (buttonHeight).reduced (border));
        button2.setBounds (area.removeFromTop (buttonHeight).reduced (border));
    }
    
private:
    CustomSlider customSlider;
    juce::Slider dial2;
    juce::TextButton button1;
    juce::TextButton button2;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
