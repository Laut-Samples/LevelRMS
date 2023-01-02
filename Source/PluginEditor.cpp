/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LevelMeterAudioProcessorEditor::LevelMeterAudioProcessorEditor (LevelMeterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    verticalgradientmeterL([&]() { return audioProcessor.getRmsValue(0); }),
    verticalgradientmeterR([&]() { return audioProcessor.getRmsValue(1); })
{
    setSize (400, 500);
    addAndMakeVisible(horizontalMeterL);
    addAndMakeVisible(horizontalMeterR);
    
    addAndMakeVisible(verticalgradientmeterL);
    addAndMakeVisible(verticalgradientmeterR);
    
    startTimerHz(24);
    
}

LevelMeterAudioProcessorEditor::~LevelMeterAudioProcessorEditor()
{
    
}

void LevelMeterAudioProcessorEditor::timerCallback()
{
    horizontalMeterL.setLevel(audioProcessor.getRmsValue(0));
    horizontalMeterR.setLevel(audioProcessor.getRmsValue(1));
    
    horizontalMeterL.repaint();
    horizontalMeterR.repaint();
    
}

//==============================================================================
void LevelMeterAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(Colours::darkgrey);
}

void LevelMeterAudioProcessorEditor::resized()
{
    horizontalMeterR.setBounds(100,100, 200, 15);
    horizontalMeterL.setBounds(100,120, 200, 15);
    
    verticalgradientmeterL.setBounds(100,200, 15, 200);
    verticalgradientmeterR.setBounds(120,200, 15, 200);
}
