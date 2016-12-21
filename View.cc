#include "View.h"

#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WMenu>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>

// https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WApplication.html#ae29a843f4d50159b17abfa9503c389db
// wApp->log("notice") << "User " << userName << " logged in successfully.";

// This is the top-level widget container of the application, and corresponds to entire browser window. The user interface of your application is represented by the content of this container.
// The root() widget is only defined when the application manages the entire window.

View::View(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
  setTitle("TonyKanBan");
  log("notice") << "DDD Is this on?";

  // Load the stylesheet.
  useStyleSheet("wt.css");

  // in a vertical box layout, widgets are given appropriate heights based on
  //  available space in the container and layout rules, while all widgets get
  //  the same width
  Wt::WVBoxLayout *layout = new Wt::WVBoxLayout();
  //layout->addWidget(new Wt::WText("Some text"));
  //layout->addWidget(new Wt::WImage("images/img.png"));


  /*
  * See: /usr/lib/Wt/examples/widgetgallery
  * Navigation.C
  * examples/Tab.cpp
  */
  Wt::WContainerWidget *container = new Wt::WContainerWidget();
  container->setLayout(layout);      // set the layout to the container.
  root()->addWidget(container);

  // create a menu
  /*
  Wt::WMenu *menu = new Wt::WMenu(containerWidget);
  menu->addItem("Download1", new Wt::WText("Not yet available"));
  menu->addItem("Download2", new Wt::WText("Not yet available"));

  layout->addWidget(menu);
  */
  container->resize(150, 150);
  container->setStyleClass("yellow-box centered");

  Wt::WText *item = new Wt::WText("Item 1");
  item->setStyleClass("green-box");
  layout->addWidget(item, 1);

  Wt::WHBoxLayout *hbox = new Wt::WHBoxLayout();
  layout->addLayout(hbox);

  item = new Wt::WText("Item 2");
  item->setStyleClass("green-box");
  hbox->addWidget(item);

  item = new Wt::WText("Item 3");
  item->setStyleClass("blue-box");
  hbox->addWidget(item);
/*
    root()->addWidget(new Wt::WText("Your name, please ? "));
    nameEdit_ = new Wt::WLineEdit(root());
    Wt::WPushButton *button = new Wt::WPushButton("Greet me.", root());
    root()->addWidget(new Wt::WBreak());
    greeting_ = new Wt::WText(root());
    button->clicked().connect(this, &HelloApplication::greet);
    */
}
