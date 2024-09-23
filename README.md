# Towel Synth

<img width="506" alt="Screen Shot 2024-09-23 at 1 35 21 AM" src="https://github.com/user-attachments/assets/d2556f02-8b2b-4db8-9431-83f7b5d0a87f">

Towel Synth is a simple yet powerful synthesizer plugin developed using the JUCE framework. It features an interactive graphical user interface with ADSR sliders and a resizable MIDI keyboard, allowing users to create and manipulate sounds with ease.

## Features

- **ADSR Envelope Control**: Adjustable Attack, Decay, Sustain, and Release sliders to shape the amplitude envelope of the sound.
- **Resizable MIDI Keyboard**: An integrated, resizable on-screen keyboard for triggering notes directly from the plugin interface.
- **Customizable GUI**: Sliders and components styled with a sleek gray color scheme for a modern look.
- **Polyphonic and Monophonic Modes**: Switch between polyphony for chords and monophony for lead or bass lines.
- **Parameter Automation**: Fully automatable parameters for dynamic sound modulation within your DAW.

## Getting Started

### Prerequisites

- **JUCE Framework**: Ensure you have the latest version of JUCE installed. You can download it from [juce.com](https://juce.com/get-juce).
- **C++17 Compatible Compiler**: A modern C++ compiler that supports C++17 features.
- **Supported IDEs**:
  - **Windows**: Visual Studio 2019 or later
  - **macOS**: Xcode 11 or later

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/yourusername/towel-synth.git
   ```

2. **Open the Projucer Project**:

   - Navigate to the project directory.
   - Open `TowelSynth.jucer` with Projucer.

3. **Configure the Project**:

   - In Projucer, check that all the modules paths are correctly set.
   - Ensure the **JUCE Modules** path points to your local JUCE installation.

4. **Save and Export**:

   - Click on **File** -> **Save Project**.
   - Click on **File** -> **Save and Open in IDE** to generate project files for your preferred IDE.

5. **Build the Plugin**:

   - In your IDE, select the desired build configuration (Debug or Release).
   - Build the project to generate the plugin binary.

## Usage

1. **Install the Plugin**:

   - Copy the built plugin file to your DAW's plugin directory.
     - **Windows (VST3)**: `\Program Files\Common Files\VST3`
     - **macOS (AU/VST3)**: `/Library/Audio/Plug-Ins/VST3` or `/Library/Audio/Plug-Ins/Components`

2. **Load in Your DAW**:

   - Open your Digital Audio Workstation.
   - Scan for new plugins if necessary.
   - Insert **Towel Synth** onto a MIDI track.

3. **Exploring the Interface**:

   - **ADSR Sliders**: Adjust the Attack, Decay, Sustain, and Release to shape the sound's envelope.
   - **MIDI Keyboard**: Use the on-screen keyboard to play notes, or use a MIDI controller connected to your DAW.
   - **Resizable Window**: Drag the edges of the plugin window to resize and adjust the layout to your preference.

4. **Creating Sounds**:

   - Experiment with different ADSR settings to create pads, leads, basses, and more.
   - Use automation in your DAW to modulate parameters over time for dynamic sound changes.

## Customization

### Changing Slider Colors

- The slider colors can be customized by modifying the `PluginEditor.cpp` file.
- The sliders currently use a gray color scheme for a modern appearance.
- To change the slider colors:
  - Locate the `setColour` method calls for each slider in `PluginEditor.cpp`.
  - Modify the color values using `juce::Colours` or custom RGB/HEX values.

### Renaming the Plugin

- The plugin name and identifiers are set in the Projucer project settings.
- To change the plugin name:
  - Open `TowelSynth.jucer` in Projucer.
  - Update the **Project Name** and **Plugin Name** fields in the project settings.
  - Save the project and rebuild to apply the changes.

## Contributing

Contributions are welcome! If you'd like to improve Towel Synth or report issues, please open an issue or submit a pull request on the GitHub repository.

## License

Towel Synth is released under the [MIT License](LICENSE).

## Acknowledgements

- **JUCE Framework**: Thanks to the JUCE team for providing an excellent framework for audio application development.
- **Community Support**: Appreciation to the open-source community for guidance and resources.

---
