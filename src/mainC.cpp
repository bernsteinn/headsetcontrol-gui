#include "mainC.h"
#include<iostream>
#include<string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>


wxBEGIN_EVENT_TABLE(MainC, wxApp) //We can't handle events without this.
	EVT_MENU(ID_About, MainC::OnAbout)
    EVT_BUTTON(10001, MainC::PowerLightsOn)
    EVT_BUTTON(10002, MainC::PowerLightsOff)
    EVT_BUTTON(10003, MainC::getBatteryStatus)
    EVT_CLOSE(MainC::OnClose)
wxEND_EVENT_TABLE()


MainC::MainC() : wxFrame(nullptr, 10000, "Headset control GUI", wxPoint(500,500)){ //Specify the window size, name.
    lightsOn = new wxButton(this, 10001, "Lights ON", wxPoint(10,10), wxSize(130,30)); //Power the headset lights on button design
    lightsOff = new wxButton(this, 10002, "Lights OFF", wxPoint(10,50), wxSize(130,30));//Power the headset lights off button design
    getBattery = new wxButton(this, 10003, "Get battery %", wxPoint(10, 90), wxSize(130,30));//Get the battery % button design
    status = new wxListBox(this, wxID_ANY, wxPoint(10, 200), wxSize(300, 30));//Is the headset connected/detected?
    batStatus = new wxStaticText(this, wxID_ANY, "Detecting...", wxPoint(250,10), wxSize(100,50));
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
    event.Skip();

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
    event.Skip();

}
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
void MainC::getBatteryStatus(wxCommandEvent& event){
        char command[300];
    sprintf(command, "%s", "/home/b3rnie/path2/projects/headsetcontrol-gui/src/HeadsetControl/bui/headsetcontrol -b");
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
            std::string label = exec("../src/HeadsetControl/bui/headsetcontrol -b");
            batStatus->SetLabel(label+"%");
        }
        else{
            std::string label = exec("../src/HeadsetControl/bui/headsetcontrol -b");
            status->SetString(status->GetCount()-1, "Succesfully connected!");
            batStatus->SetLabel(label+"%");
        }
        status->SetSelection(status->GetCount()-1);
        status->Thaw();

    }
    //event.Skip();

}
void MainC::OnAbout(wxCommandEvent& event){ //Define about window data.
            wxAboutDialogInfo aboutInfo;
            aboutInfo.SetName("Headset Gui Control");
            aboutInfo.SetVersion("1.0");
            aboutInfo.SetDescription(_("Headsetcontrol GUI version. Based on the cli tool developed by Sapd (Denis Arnst) https://github.com/Sapd"));
            aboutInfo.SetWebSite("http://github/bernsteinn/headset_gui");
            aboutInfo.AddDeveloper("bernsteinn, Sapd");
            wxAboutBox(aboutInfo);
            event.Skip();

}
void MainC::OnClose(wxCloseEvent& event)
{
 Destroy();
}

void MainC::OnExit(wxCommandEvent& event)
{
 Destroy();
}

