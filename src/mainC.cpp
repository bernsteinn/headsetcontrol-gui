#include "mainC.h"

MainC::MainC() : wxFrame(nullptr, wxID_ANY, "Headset control GUI", wxPoint(300,300)){ //Specify the window size, name.
    lightsOn = new wxButton(this, 10001, "Lights ON", wxPoint(10,10), wxSize(130,30)); //Power the headset lights on button design
    lightsOff = new wxButton(this, 10002, "Lights OFF", wxPoint(10,50), wxSize(130,30));//Power the headset lights off button design
    getBattery = new wxButton(this, wxID_ANY, "Get battery %", wxPoint(10, 90), wxSize(130,30));//Get the battery % button design
    m_pMenuBar = new wxMenuBar(); //Define the menu bar for the about button
    // About menu
    m_pHelpMenu = new wxMenu(); //Define the help and about section
    m_pHelpMenu->Append(wxID_ABOUT, _T("&About"));
    m_pMenuBar->Append(m_pHelpMenu, _T("&Help"));

    SetMenuBar(m_pMenuBar);
}

MainC::~MainC(){

}