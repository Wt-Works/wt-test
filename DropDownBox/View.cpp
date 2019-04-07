#include "View.h"

#include <Wt/WComboBox>
#include <Wt/WGridLayout>
#include <Wt/WSignal>
#include <Wt/WText>


/**
  Constructor for View

  /usr/lib/Wt/examples/widgetgallery/examples/ComboBoxModel.cpp
  https://www.webtoolkit.eu/widgets/forms/combo-box
  https://www.webtoolkit.eu/wt/doc/reference/html/classWt_1_1WComboBox.html

 */
View::View(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
  setTitle("DropDown Demo");


  log("info") << "Test";

  // This is the container for the full screen.
  Wt::WContainerWidget *pScreenContainer = new Wt::WContainerWidget();
  pScreenContainer->resize(Wt::WLength::Auto, Wt::WLength::Auto);
  // Add the primary container to the root widget?
  root()->addWidget(pScreenContainer);

  // Choose the grid layout.
  Wt::WGridLayout *pScreenLayout = new Wt::WGridLayout();
  pScreenContainer->setLayout(pScreenLayout);

  int nRow = 0;
  int nColoumn = 0;

 
  // Create the label
  Wt::WText *lblSeriesChoice = new Wt::WText("Series:");
  // set right align the label
  lblSeriesChoice->setTextAlignment(Wt::AlignRight);
  pScreenLayout->addWidget(lblSeriesChoice, nRow, nColoumn+0);

  // Create the dropdown
  Wt::WComboBox *cbSeries = new Wt::WComboBox();
  cbSeries->addItem("");
  cbSeries->addItem("New");
  cbSeries->addItem("Krakken awoke");
  cbSeries->addItem("Appocalypse survival");
  cbSeries->setCurrentIndex(0); // Empty string
  pScreenLayout->addWidget(cbSeries, nRow, nColoumn+1);


  // Create the connection
  cbSeries->activated().connect(this, &View::DropDownSelectionChangeOtherDropDown);
  cbSeries->activated().connect(this, &View::DropDownSelectionChangeTab);
  /* Signals connect to Slots.
  * You may specify up to 6 arguments which may be of arbitrary types that are Copyable, that may be passed through the signal to connected slots.
  *   https://www.webtoolkit.eu/wt/doc/reference/html/group__signalslot.html
  * I think the 
  *   first parm - is a pointer to the target class.
  *   second parm - is the name of the method?
  * 
  * See: Wt::Signal.
  */


  /*
  * Let row 1 and column 1 take the excess space.?
  */
  pScreenLayout->setRowStretch(0, 0);
  pScreenLayout->setColumnStretch(0, 0);
} // end


void View::DropDownSelectionChangeOtherDropDown(int nIndex) {
  log("info") << "DropDownSelectionChangeOtherDropDown";
}

void View::DropDownSelectionChangeTab(int nIndex) {
  log("info") << "DropDownSelectionChangeTab";
}