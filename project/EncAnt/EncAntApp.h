/***************************************************************
 * Name:      EncAntApp.h
 * Purpose:   Defines Application Class
 * Author:    Kirill Kotsko ()
 * Created:   2020-12-01
 * Copyright: Kirill Kotsko ()
 * License:
 **************************************************************/

#ifndef ENCANTAPP_H
#define ENCANTAPP_H

#include <wx/app.h>

class EncAntApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ENCANTAPP_H
