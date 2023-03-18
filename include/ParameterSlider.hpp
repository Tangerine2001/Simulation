#ifndef PARAMETERSLIDER_HPP
#define PARAMETERSLIDER_HPP

#include <Vector2.hpp>
#include <TGUI/TGUI.hpp>

class ParameterSlider
{
    public:
        ParameterSlider(tgui::Gui& gui, std::string name, float min, float max, float step, float value, Vector2 position, Vector2 size);

        void Init(tgui::Gui& gui, std::string name, float min, float max, float step, float value, Vector2 position, Vector2 size);
        void SetPosition(Vector2 position);
    protected:
    private:
        tgui::Gui* gui;

        tgui::Slider::Ptr slider;
        tgui::Label::Ptr label;
        tgui::Label::Ptr valueLabel;

        void UpdateValueLabel();
};

#endif