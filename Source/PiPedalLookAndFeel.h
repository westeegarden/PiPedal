/*
  ==============================================================================

    PiPedalLookAndFeel.h
    Created: 4 Oct 2024 2:45:18pm
    Author:  weste

  ==============================================================================
*/
#include <JuceHeader.h>
#include <iostream>

#pragma once


class PiPedalLookAndFeel : public juce::LookAndFeel_V4
{
public:
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        float knobRadius = (height - 45) / 2;
        float perimRadius = width / 2;
        float centreX = x + perimRadius;
        float centreY = y + perimRadius;
        float rx = centreX - knobRadius;
        float ry = centreY - knobRadius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        juce::Rectangle<float> dialArea(rx, ry, knobRadius * 2, knobRadius * 2);
        juce::Rectangle<float> perimArea(x, y, width, width);

        g.setColour(juce::Colours::black);
        g.fillEllipse(dialArea);
        g.setColour(juce::Colours::grey.withBrightness(0.5));
        g.drawEllipse(dialArea, 2);
        g.setColour(juce::Colours::white);

        juce::Path dialTick;
        auto pointerLength = knobRadius * 0.5f;
        auto pointerThickness = 2.0f;
        dialTick.addRectangle(-pointerThickness * 0.5f, -knobRadius, pointerThickness, pointerLength);

        g.fillPath(dialTick, juce::AffineTransform::rotation(angle).translated(centreX, centreY));
    }


    /*void drawComboBox(juce::Graphics& g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, juce::ComboBox& combobox) override
    {

    }*/

private:

};