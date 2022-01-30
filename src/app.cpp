#include "app.h"
#include "mainC.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/wait.h>
#include <stdio.h>



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


