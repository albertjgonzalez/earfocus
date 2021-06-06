/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
EarFocusAudioProcessorEditor::EarFocusAudioProcessorEditor (EarFocusAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(-60.0f,0.0f,0.01f);
    gainSlider.setValue(-20.0f);
    gainSlider.addListener(this);
    addAndMakeVisible (gainSlider);
    setSize (400, 300);
}

EarFocusAudioProcessorEditor::~EarFocusAudioProcessorEditor()
{
}

//==============================================================================
void EarFocusAudioProcessorEditor::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colours::black);

}

void EarFocusAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() /2 - 75 , 100, 150);
}

void EarFocusAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if(slider == &gainSlider){
        audioProcessor.gain = gainSlider.getValue();
    }
}
