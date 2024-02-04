#pragma once
#include <wx/wx.h>
#include "functions.h"

class MainFrame : public wxFrame
{
private:
    wxRadioBox* m_radiobox;
    int m_selectedOption;

public:
    MainFrame(const wxString& title);
    void ShowMenu();
    void OnRadioBox(wxCommandEvent& event);
    void OnButtonClick(wxCommandEvent& event);
    void OnExitButtonClick(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);



};
class MyDialog : public wxDialog
{
private:

public:
    MyDialog(wxWindow* parent);
    void OnOKButtonClick(wxCommandEvent& event);

};