#pragma once

#include<wx/wx.h>
#include <wx/aboutdlg.h>

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
        wxTextCtrl *status = nullptr;
        wxButton *lightsOff = nullptr;
        wxButton *lightsOn = nullptr;
        wxButton *getBattery = nullptr;

        
    
};