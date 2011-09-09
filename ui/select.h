#ifndef UI_SELECT_H
#define UI_SELECT_H

#include "label.h"
#include "solidlayout.h"

class UISelect;

class UIOptionLabel : public UILabel {
    UISelect* select;
public:
    std::string value;

    UIOptionLabel(UISelect* select, const std::string& text, const std::string& value);

    void click();
};

class UISelect : public UISolidLayout {
    UILabel* label;
    UILayout* options_layout;

    UIOptionLabel* selected_option;
    
    bool open;
public:
    UISelect();
    ~UISelect();
    
    int getType() { return UI_SELECT; };

    void setUI(UI* ui);

    void selectOption(UIOptionLabel* option);

    UIOptionLabel* getSelectedOption();
    
    void addOption(const std::string& name, const std::string& value);

    void click();

    UIElement* elementAt(const vec2& pos);
        
    void updatePos(const vec2& pos);
    void update(float dt);

    void draw();
};

#endif
