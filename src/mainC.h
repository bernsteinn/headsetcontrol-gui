#pragma once

#include<wx/wx.h>
#include <wx/aboutdlg.h>
enum{
    ID_About = wxID_ABOUT
};


class MainC : public wxFrame{
    public:
        MainC();
        ~MainC();
    private:
    //Window components
        wxTextCtrl *m_pTextCtrl;
        wxMenuBar *m_pMenuBar;
        wxMenu *m_pFileMenu;
        wxMenu *m_pHelpMenu;

    public:
    //All the windows components are listed here.
        wxButton *lightsOn1 = nullptr;
        wxListBox *status = nullptr;
        wxButton *lightsOff = nullptr;
        wxButton *lightsOn = nullptr;
        wxButton *getBattery = nullptr;

        void OnAbout(wxCommandEvent& event); //Define about function
        void PowerLightsOn(wxCommandEvent &event); //Define the button pressed function
        void PowerLightsOff(wxCommandEvent &event); //Define the button pressed function



        DECLARE_EVENT_TABLE();
        
    
};