#include <iostream>

class ButtonListener;
class Dialer;

/* Client */
class Button
{
    public:
        ButtonListener *listener;
        Button(ButtonListener *l) : listener(l) {}
};

/* interface */
class ButtonListener
{
    public:
        virtual void buttonPressed() = 0;
};

/* adapter */
class ButtonDialerAdapter : public ButtonListener
{
    Dialer *dialer;
    int n; /* the digit this button represents */

    public:
        void buttonPressed(); //{ dialer->digit(n); }
        ButtonDialerAdapter(Dialer *d, int n) : dialer(d), n(n) {}
};

class Dialer
{
    public:
        void digit(int n);
};

void ButtonDialerAdapter::buttonPressed() {
    dialer->digit(n);
}

void Dialer::digit(int n){
    std::cout<< n <<std::endl;
}

int main(int argc, char const *argv[])
{
    Dialer dialer;
    ButtonDialerAdapter *bda = new ButtonDialerAdapter(&dialer, 7);
    Button button(bda);

    button.listener->buttonPressed();

    return 0;
}
