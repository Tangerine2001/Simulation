#include <ParameterSlider.hpp>
#include <iostream>
#include <iomanip>
#include <sstream>

ParameterSlider::ParameterSlider(tgui::Gui& gui, std::string name, float min, float max, float step, float value, Vector2 position, Vector2 size) { Init(gui, name, min, max, step, value, position, size);}

void ParameterSlider::Init(tgui::Gui& gui, std::string name, float min, float max, float step, float value, Vector2 position, Vector2 size)
{
    this->gui = &gui;
    this->slider = tgui::Slider::create();
    this->label = tgui::Label::create();
    this->valueLabel = tgui::Label::create();

    this->slider->setPosition(position.x, position.y);
    this->slider->setSize(size.x, size.y);
    this->slider->setMinimum(min);
    this->slider->setMaximum(max);
    this->slider->setStep(step);
    this->slider->setValue(value);
    this->slider->onValueChange.connect([this] { UpdateValueLabel(); });

    this->label->setText(name);
    this->label->setPosition(position.x, position.y - 20);
    this->label->setTextSize(16);

    UpdateValueLabel();
    this->valueLabel->setPosition(position.x, position.y + 20);
    this->valueLabel->setTextSize(16);

    this->gui->add(slider);
    this->gui->add(label);
    this->gui->add(valueLabel);
}

void ParameterSlider::SetPosition(Vector2 position)
{
    this->slider->setPosition(position.x, position.y);
    this->label->setPosition(position.x, position.y - 20);
    this->valueLabel->setPosition(position.x, position.y + 20);
}

void ParameterSlider::UpdateValueLabel()
{
    int decimalPlaces = 1;
    
    std::stringstream stream;
    stream << std::fixed << std::setprecision(decimalPlaces) << this->slider->getValue() ;
    std::string s = stream.str();

    this->valueLabel->setText(s);
}
