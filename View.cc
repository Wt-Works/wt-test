#include "View.h"

#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WMenu>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WNavigationBar>
#include <Wt/WStackedWidget>
#include <Wt/WPopupMenu>
#include <Wt/WLineEdit>
#include <Wt/WTabWidget>
#include <Wt/WTextArea>
#include <Wt/WBorderLayout>

// https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WApplication.html#ae29a843f4d50159b17abfa9503c389db
// wApp->log("notice") << "User " << userName << " logged in successfully.";

// This is the top-level widget container of the application, and corresponds to entire browser window. The user interface of your application is represented by the content of this container.
// The root() widget is only defined when the application manages the entire window.

// The resource files in /usr/share/Wt/resources has to be available.

View::View(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
  setTitle("WtTest");
  //useStyleSheet("everywidget.css");
  //useStyleSheet("example1.css");


  log("info") << "Test";

  // This is the container for the full screen.
  Wt::WContainerWidget *pScreenContainer = new Wt::WContainerWidget();
  root()->addWidget(pScreenContainer);
  Wt::WBorderLayout *pBorderLayout = new Wt::WBorderLayout();
  pScreenContainer->setLayout(pBorderLayout);

  // Create the container for the North field
  Wt::WContainerWidget *pNorthContainer = new Wt::WContainerWidget();
  //container->setStyleClass("yellow-box");
  // root()->addWidget(pNorthContainer);
  CreateTopTab(this, pNorthContainer);

  pBorderLayout->addWidget(pNorthContainer, Wt::WBorderLayout::North);

  const char *cell = "{1} item";
  Wt::WText *item = new Wt::WText(Wt::WString(cell).arg("South"));
  item->setStyleClass("green-box");
  pBorderLayout->addWidget(item, Wt::WBorderLayout::South);

  item = new Wt::WText(Wt::WString(cell).arg("Center"));
  item->setStyleClass("green-box");
  pBorderLayout->addWidget(item, Wt::WBorderLayout::Center);
} // end


/**
 */
Wt::WHBoxLayout *View::CreateTopTab(Wt::WApplication *app, Wt::WContainerWidget *container) {
  //TODO N create destructors that delete all the 'new()' operations.
  Wt::WHBoxLayout *hbox = new Wt::WHBoxLayout();
  container->setLayout(hbox);

  // Things are getting added to the hbox.
  Wt::WTabWidget *tabW = new Wt::WTabWidget(container);
  tabW->addTab(new Wt::WTextArea("This is the contents of the first tab."),
	     "Capture", Wt::WTabWidget::PreLoading);
  tabW->addTab(new Wt::WTextArea("The contents of the tabs are pre-loaded in"
			       " the browser to ensure swift switching."),
	     "Chunk", Wt::WTabWidget::PreLoading);
  tabW->addTab(new Wt::WTextArea("You could change any other style attribute of the"
			       " tab widget by modifying the style class."
			       " The style class 'trhead' is applied to this tab."),
	     "Plan", Wt::WTabWidget::PreLoading);
  tabW->addTab(new Wt::WTextArea("The contents of the tabs are pre-loaded in"
     			       " the browser to ensure swift switching."),
     	     "Schedule", Wt::WTabWidget::PreLoading);
  tabW->addTab(new Wt::WTextArea("The contents of the tabs are pre-loaded in"
             			       " the browser to ensure swift switching."),
             	     "Execute", Wt::WTabWidget::PreLoading);
  tabW->addTab(new Wt::WTextArea("The contents of the tabs are pre-loaded in"
                     			       " the browser to ensure swift switching."),
                     	     "Complete", Wt::WTabWidget::PreLoading);
  tabW->addTab(new Wt::WTextArea("The contents of the tabs are pre-loaded in"
                             			       " the browser to ensure swift switching."),
                             	     "Celebrate", Wt::WTabWidget::PreLoading);
  tabW->setStyleClass("tabwidget");
  hbox->addWidget(tabW);

  app->log("info") << "DDD CreateTopTab() done";
  return(hbox);
} // end CreateTopTab
