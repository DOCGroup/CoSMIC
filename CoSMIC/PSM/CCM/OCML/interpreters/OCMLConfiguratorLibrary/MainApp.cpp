#include "MainApp.hpp"
#include "MainFrame.hpp"

IMPLEMENT_APP_NO_MAIN(MainApp)

MainApp::MainApp()
{
}

bool
MainApp::OnInit()
{
  return true;
}

void
MainApp::new_instance(const char* values, size_t values_size,
                      MainFrameValueChangeListener* l)
{
  MainFrame *win = new MainFrame("Frame", wxPoint (100, 100),
                                 wxSize(500, 500),
                                 "orb_tree.xml",
                                 values, values_size);
  win->add_value_change_listener(l);
  win->Show(TRUE);
}

MainApp::~MainApp()
{
}
