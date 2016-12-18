#include "View.h"

View::View(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    setTitle("Hello world");
/*
    root()->addWidget(new Wt::WText("Your name, please ? "));
    nameEdit_ = new Wt::WLineEdit(root());
    Wt::WPushButton *button = new Wt::WPushButton("Greet me.", root());
    root()->addWidget(new Wt::WBreak());
    greeting_ = new Wt::WText(root());
    button->clicked().connect(this, &HelloApplication::greet);
    */
}
