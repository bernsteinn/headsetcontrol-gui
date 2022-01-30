#include "app.h"
#include "mainC.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

wxBEGIN_EVENT_TABLE(headset_gui, wxApp) //We can't handle events without this.
	EVT_MENU(ID_About, headset_gui::OnAbout)
    EVT_BUTTON(10001, headset_gui::PowerLightsOn)
    EVT_BUTTON(10002, headset_gui::PowerLightsOff)
wxEND_EVENT_TABLE()


wxIMPLEMENT_APP(headset_gui);

headset_gui::headset_gui(){

}

headset_gui::~headset_gui(){

}

bool headset_gui::OnInit(){

    m_frame1 = new MainC();//Start the frame
    m_frame1->Show();//Show the frame
    return true;
}
void headset_gui::OnAbout(wxCommandEvent& event){ //Define about window data.
            wxAboutDialogInfo aboutInfo;
            aboutInfo.SetName("Headset Gui Control");
            aboutInfo.SetVersion("1.0");
            aboutInfo.SetDescription(_("Headsetcontrol GUI version. Based on the cli tool developed by Sapd (Denis Arnst) https://github.com/Sapd"));
            aboutInfo.SetWebSite("http://github/bernsteinn/headset_gui");
            aboutInfo.AddDeveloper("bernsteinn, Sapd");
            wxAboutBox(aboutInfo);
}
void headset_gui::PowerLightsOn(wxCommandEvent& event){
    char command[50];
    sprintf(command, "%s", "headsetcontrol -l 1");
    system(command);
}
void headset_gui::PowerLightsOff(wxCommandEvent& event){
    char command[50];
    sprintf(command, "%s", "headsetcontrol -l 0");
    system(command);
}


