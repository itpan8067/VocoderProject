/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MyBuffer.h"
#include "VocoderProcess.h"
#include "PitchProcess.h"
#include <string>
#include <math.h>

#define GAIN_PITCH_ID "gainPitch"
#define GAIN_PITCH_NAME "GainPitch"


//==============================================================================
/**
*/
class VocoderAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    VocoderAudioProcessor();
    ~VocoderAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    /*
    float gainPitch;
    float gainSynth;
    float gainVocoder;
    float gainVoice;
    int orderVoice;
    int orderSynth;
    int orderMaxVoice;
    int orderMaxSynth;
    */

    AudioProcessorValueTreeState treeState;

    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

private:
    // To handle the variable buffer size and latency
    MyBuffer myBuffer;

    // Class with process function
    VocoderProcess vocoderProcess;
    PitchProcess pitchProcess;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VocoderAudioProcessor)
};
