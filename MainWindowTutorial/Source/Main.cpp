/*
 ==============================================================================
 
 This file contains the basic startup code for a JUCE application.
 
 ==============================================================================
 */

#include <JuceHeader.h>
#include "MainComponent.h"

//==============================================================================
class MainWindowTutorialApplication  : public juce::JUCEApplication
{
public:
    //==============================================================================
    MainWindowTutorialApplication() {}
    
    const juce::String getApplicationName() override       { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }
    
    //==============================================================================
    void initialise (const juce::String& commandLine) override
    {
        // Add your application's initialisation code here..
        mainWindow.reset(new MainWindow (getApplicationName()));
    }
    
    void shutdown() override
    {
        // Add your application's shutdown code here..
        mainWindow = nullptr;
    }
    
    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }
    
    void anotherInstanceStarted (const juce::String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }
    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow(juce::String name) : juce::DocumentWindow(name, juce::Colours::orange, DocumentWindow::closeButton | DocumentWindow::minimiseButton)
        {
            centreWithSize(getWidth(), getHeight());
            // x start (percent), y start(percent), ratio to window w, ratio to window height
            // 0,0 upper left corner top
//            setBoundsRelative(0, 0, 1, 1);
            setResizable(true, true);
            setUsingNativeTitleBar(true);
            setVisible(true);
            setContentOwned(new MainComponent(), true);
            
        }
        
        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };
    
private:
    std::unique_ptr<MainWindow> mainWindow;
    juce::Component* childComponent;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (MainWindowTutorialApplication)
