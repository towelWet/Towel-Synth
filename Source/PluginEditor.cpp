// PluginEditor.cpp
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JX11AudioProcessorEditor::JX11AudioProcessorEditor (JX11AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), keyboardComponent (audioProcessor.keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
    // Set the size of the plugin window
    setSize (500, 400);

    // Make the editor resizable
    setResizable (true, true);
    setResizeLimits (400, 300, 800, 600);

    // Add the keyboard component
    addAndMakeVisible (keyboardComponent);

    // Define the gray color you want to use
    juce::Colour sliderColour = juce::Colours::grey;

    // Attack Slider
    attackSlider.setSliderStyle(juce::Slider::LinearVertical);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    attackSlider.setColour(juce::Slider::thumbColourId, sliderColour);
    attackSlider.setColour(juce::Slider::trackColourId, sliderColour);
    addAndMakeVisible(attackSlider);

    attackLabel.setText("Attack", juce::dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, false);
    attackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(attackLabel);

    attackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "envAttack", attackSlider);

    // Decay Slider
    decaySlider.setSliderStyle(juce::Slider::LinearVertical);
    decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    decaySlider.setColour(juce::Slider::thumbColourId, sliderColour);
    decaySlider.setColour(juce::Slider::trackColourId, sliderColour);
    addAndMakeVisible(decaySlider);

    decayLabel.setText("Decay", juce::dontSendNotification);
    decayLabel.attachToComponent(&decaySlider, false);
    decayLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(decayLabel);

    decayAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "envDecay", decaySlider);

    // Sustain Slider
    sustainSlider.setSliderStyle(juce::Slider::LinearVertical);
    sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    sustainSlider.setColour(juce::Slider::thumbColourId, sliderColour);
    sustainSlider.setColour(juce::Slider::trackColourId, sliderColour);
    addAndMakeVisible(sustainSlider);

    sustainLabel.setText("Sustain", juce::dontSendNotification);
    sustainLabel.attachToComponent(&sustainSlider, false);
    sustainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(sustainLabel);

    sustainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "envSustain", sustainSlider);

    // Release Slider
    releaseSlider.setSliderStyle(juce::Slider::LinearVertical);
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    releaseSlider.setColour(juce::Slider::thumbColourId, sliderColour);
    releaseSlider.setColour(juce::Slider::trackColourId, sliderColour);
    addAndMakeVisible(releaseSlider);

    releaseLabel.setText("Release", juce::dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, false);
    releaseLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(releaseLabel);

    releaseAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "envRelease", releaseSlider);
}

JX11AudioProcessorEditor::~JX11AudioProcessorEditor()
{
}

//==============================================================================
// Paint method
void JX11AudioProcessorEditor::paint (juce::Graphics& g)
{
    // Clear the background
    g.fillAll (juce::Colours::darkgrey);

    // Optional: Draw a rectangle around the keyboard component
    g.setColour (juce::Colours::black);
    g.drawRect (keyboardComponent.getBounds());
}

//==============================================================================
// Resized method
void JX11AudioProcessorEditor::resized()
{
    // Define the layout of the GUI components
    const int padding = 20;
    int keyboardHeight = getHeight() * 0.3f; // 30% of window height

    // Position the keyboard component
    keyboardComponent.setBounds (0, getHeight() - keyboardHeight, getWidth(), keyboardHeight);

    // Calculate the area for sliders
    int slidersAreaHeight = getHeight() - keyboardHeight - 2 * padding;
    int slidersY = padding;

    // Calculate the width for each slider based on the total available width
    int sliderWidth = (getWidth() - 5 * padding) / 4;

    // Position the sliders horizontally with equal spacing
    attackSlider.setBounds(padding, slidersY, sliderWidth, slidersAreaHeight);
    decaySlider.setBounds(2 * padding + sliderWidth, slidersY, sliderWidth, slidersAreaHeight);
    sustainSlider.setBounds(3 * padding + 2 * sliderWidth, slidersY, sliderWidth, slidersAreaHeight);
    releaseSlider.setBounds(4 * padding + 3 * sliderWidth, slidersY, sliderWidth, slidersAreaHeight);
}
