/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent (Audio& audio_) : audio (audio_), filePlayerGui(audio.getFilePlayer(0), audio.getFilePlayer(0).getEQ()), filePlayerGui1(audio.getFilePlayer(1), audio.getFilePlayer(1).getEQ())
{
    
    
    setSize(1250, 650);
    addAndMakeVisible(filePlayerGui);
    addAndMakeVisible(filePlayerGui1);
    
    filePan.addListener(this);
    addAndMakeVisible(&filePan);
    filePan.setRange(-1, 1);
    filePan.setValue(0);
    
    masterGain.addListener(this);
    masterGain.setValue(1);
    addAndMakeVisible(&masterGain);
    masterGain.setRange(0, 1);
}

MainComponent::~MainComponent()
{

}

void MainComponent::resized()
{
    filePlayerGui.setBounds (0, 0, getWidth()/2, getHeight()-20);
    filePlayerGui1.setBounds (getWidth()/2, 0, getWidth()/2, getHeight()-20);
    masterGain.setBounds(0, getHeight()-20, getWidth(), 20);
    filePan.setBounds(0, getHeight()-40, getWidth(), 20);
    
}

void MainComponent::sliderValueChanged(Slider* slider)
{
    if (slider == &masterGain)
    {
        audio.masterGain(masterGain.getValue());
    }
    else if (slider == &filePan)
    {
        audio.crossfadeGain(filePan.getValue(), filePlayerGui.crossfadeFileGainValue(), filePlayerGui1.crossfadeFileGainValue());
    }
    
    
}

//MenuBarCallbacks==============================================================
StringArray MainComponent::getMenuBarNames()
{
    const char* const names[] = { "File", 0 };
    return StringArray (names);
}

PopupMenu MainComponent::getMenuForIndex (int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    if (topLevelMenuIndex == 0)
        menu.addItem(AudioPrefs, "Audio Prefrences", true, false);
    return menu;
}

void MainComponent::menuItemSelected (int menuItemID, int topLevelMenuIndex)
{
    if (topLevelMenuIndex == FileMenu)
    {
        if (menuItemID == AudioPrefs)
        {
            AudioDeviceSelectorComponent audioSettingsComp (audio.getAudioDeviceManager(),
                                                            0, 2, 2, 2, true, true, true, false);
            audioSettingsComp.setSize (450, 350);
            DialogWindow::showModalDialog ("Audio Settings",
                                           &audioSettingsComp, this, Colours::lightgrey, true);
        }
    }
}

