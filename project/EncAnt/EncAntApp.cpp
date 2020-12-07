/***************************************************************
 * Name:      EncAntApp.cpp
 * Purpose:   Code for Application Class
 * Author:    hhh ()
 * Created:   2019-03-02
 * Copyright: hhh ()
 * License:
 **************************************************************/

#include "EncAntApp.h"

//(*AppHeaders
#include "EncAntMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(EncAntApp);

bool EncAntApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	EncAntFrame* Frame = new EncAntFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
