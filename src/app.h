#pragma once

#include"wx/wx.h"
#include "mainC.h"

class headset_gui : public wxApp{
    public:
        headset_gui();
        ~headset_gui();

    private:
        MainC* m_frame1 = nullptr;

    public:
        virtual bool OnInit();

};