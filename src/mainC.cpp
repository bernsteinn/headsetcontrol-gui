#include "mainC.h"

wxBEGIN_EVENT_TABLE(MainC, wxApp) //We can't handle events without this.
	EVT_MENU(ID_About, MainC::OnAbout)
    EVT_BUTTON(10001, MainC::PowerLightsOn)
    EVT_BUTTON(10002, MainC::PowerLightsOff)
wxEND_EVENT_TABLE()


MainC::MainC() : wxFrame(nullptr, wxID_ANY, "Headset control GUI", wxPoint(500,500)){ //Specify the window size, name.
    lightsOn = new wxButton(this, 10001, "Lights ON", wxPoint(10,10), wxSize(130,30)); //Power the headset lights on button design
    lightsOff = new wxButton(this, 10002, "Lights OFF", wxPoint(10,50), wxSize(130,30));//Power the headset lights off button design
    getBattery = new wxButton(this, wxID_ANY, "Get battery %", wxPoint(10, 90), wxSize(130,30));//Get the battery % button design
    status = new wxListBox(this, wxID_ANY, wxPoint(10, 200), wxSize(300, 30));
    m_pMenuBar = new wxMenuBar(); //Define the menu bar for the about button
    // About menu
    m_pHelpMenu = new wxMenu(); //Define the help and about section
    m_pHelpMenu->Append(wxID_ABOUT, _T("&About"));
    m_pMenuBar->Append(m_pHelpMenu, _T("&Help"));

    SetMenuBar(m_pMenuBar);
}

MainC::~MainC(){

}

void MainC::PowerLightsOn(wxCommandEvent& event){
    char command[50];
    sprintf(command, "%s", "headsetcontrol -l 1");
    int ret = system(command);
    if (WEXITSTATUS(ret) == 1){
        status->AppendString("Error connecting to headset!");
    }
    else{
      status->AppendString("Succesfully Connected!");
    }
}
void MainC::PowerLightsOff(wxCommandEvent& event){
    char command[50];
    sprintf(command, "%s", "headsetcontrol -l 0");
    int ret = system(command);
    if (WEXITSTATUS(ret) == 1){
        status->Freeze();
        if(status->GetCount() == 0){
            status->Append("Error connecting to headset!");
        }
        else{
            status->SetString(status->GetCount()-1, "Error connecting to headset!");
        }
        status->SetSelection(status->GetCount()-1);
        status->Thaw();
    }
    else{
        status->Freeze();
        if(status->GetCount() == 0){
            status->Append("Succesfully connected!");
        }
        else{
            status->SetString(status->GetCount()-1, "Succesfully connected!");
        }
        status->SetSelection(status->GetCount()-1);
        status->Thaw();

    }
}
void MainC::OnAbout(wxCommandEvent& event){ //Define about window data.
            wxAboutDialogInfo aboutInfo;
            aboutInfo.SetName("Headset Gui Control");
            aboutInfo.SetVersion("1.0");
            aboutInfo.SetDescription(_("Headsetcontrol GUI version. Based on the cli tool developed by Sapd (Denis Arnst) https://github.com/Sapd"));
            aboutInfo.SetWebSite("http://github/bernsteinn/headset_gui");
            aboutInfo.AddDeveloper("bernsteinn, Sapd");
            wxAboutBox(aboutInfo);
}

