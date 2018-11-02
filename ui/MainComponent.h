/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../audio/Audio.h"
#include "FilePlayerGui.h"


//==============================================================================
/**
    Main Component contains two versions of a graphical user interface for each file player along with a master gain control and crossfade option
*/
class MainComponent   : public Component,
                        public MenuBarModel,
                        public Slider::Listener

{
public:
    //==============================================================================
    /** Constructor */
    MainComponent (Audio& audio_);

    /** Destructor */
    ~MainComponent();

    /** Used to arrange objects in the window*/
    void resized() override;

    /** Slider Listener - called when a slider is moved*/
    void sliderValueChanged(Slider* slider) override;
    
    //MenuBarEnums/Callbacks========================================================
    enum Menus
    {
        FileMenu=0,
        
        NumMenus
    };
    
    enum FileMenuItems
    {
        AudioPrefs = 1,
        
        NumFileItems
    };
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int topLevelMenuIndex, const String& menuName) override;
    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override;
    
private:
    Audio& audio;
    FilePlayerGui filePlayerGui;
    FilePlayerGui filePlayerGui1;
    Slider masterGain;
    Slider filePan;
    

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
