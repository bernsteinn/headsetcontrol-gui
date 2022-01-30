#pragma once

#include"wx/wx.h"
#include "mainC.h"

enum{
    ID_About = wxID_ABOUT
};
class headset_gui : public wxApp{
    public:
        headset_gui();
        ~headset_gui();

    private:
        MainC* m_frame1 = nullptr;
        DECLARE_EVENT_TABLE()

    public:
        virtual bool OnInit();
        void OnAbout(wxCommandEvent& event); //Define about function
        void PowerLightsOn(wxCommandEvent &event); //Define the button pressed function
        void PowerLightsOff(wxCommandEvent &event); //Define the button pressed function

};