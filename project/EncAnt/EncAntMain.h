/***************************************************************
 * Name:      EncAntMain.h
 * Purpose:   Defines Application Frame
 * Author:    hhh ()
 * Created:   2019-03-02
 * Copyright: hhh ()
 * License:
 **************************************************************/

#ifndef ENCANTMAIN_H
#define ENCANTMAIN_H

//(*Headers(EncAntFrame)
#include <wx/button.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class EncAntFrame: public wxFrame
{
    public:

        EncAntFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~EncAntFrame();

    private:

        //(*Handlers(EncAntFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnInstruction(wxCommandEvent& event);
        void OnTextCtrl1Text1(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnTextCtrl1Text2(wxCommandEvent& event);
        void OnButton2Click2(wxCommandEvent& event);
        //*)

        //(*Identifiers(EncAntFrame)
        static const long ID_FILEPICKERCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICBITMAP2;
        static const long idInstuction;
        static const long idMenuQuit;
        //*)

        //(*Declarations(EncAntFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxFilePickerCtrl* FilePickerCtrl1;
        wxMenuItem* MenuItem2;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ENCANTMAIN_H
