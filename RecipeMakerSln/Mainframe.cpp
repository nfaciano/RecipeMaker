#include "Mainframe.h"
#include <wx/wx.h>
#include <memory>
#include "functions.h"



MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    ShowMenu();
    CreateStatusBar();
}


void MainFrame::OnExitButtonClick(wxCommandEvent& event)
{
    Close();
}
MyDialog::MyDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, "My Dialog") {
}

void MainFrame::OnClose(wxCloseEvent& event) {

    event.Skip();
}




void MyDialog::OnOKButtonClick(wxCommandEvent& event){
    EndModal(wxID_OK);
}

void MainFrame::ShowMenu() {
    // Create the radio box
    wxString choices[] = { "1.) List or Modify Ingredient", "2.) Add an Ingredient", "3.) Review and Edit Your Recipes",
                           "4.) Add Recipe", "5.) List Makeable Recipes", "6.) Choose Recipe to Make","7.) Instructions"};
    m_radiobox = new wxRadioBox(this, wxID_ANY, "Options", wxDefaultPosition, wxDefaultSize, WXSIZEOF(choices), choices, 1, wxRA_SPECIFY_COLS);
    wxFont font = m_radiobox->GetFont();
    font.SetPointSize(20);
    m_radiobox->SetFont(font);
    m_radiobox->Bind(wxEVT_RADIOBOX, &MainFrame::OnRadioBox, this);
    m_radiobox->SetSelection(0);
    m_selectedOption = 0;

    // Create the "OK" button
    wxButton* button = new wxButton(this, wxID_OK, "OK");
    button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnButtonClick, this);
    button->SetForegroundColour(*wxBLUE);
    button->SetBackgroundColour(*wxLIGHT_GREY);
    button->SetMinSize(wxSize(100, 50));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_radiobox, 0, wxALL, 10);
    sizer->AddSpacer(20);
    sizer->Add(button, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->AddStretchSpacer();

    // Create the exit button
    wxButton* exitButton = new wxButton(this, wxID_ANY, "Exit");
    exitButton->SetMinSize(wxSize(150, 50));
    exitButton->SetForegroundColour(*wxRED);
    exitButton->SetBackgroundColour(*wxLIGHT_GREY);

    // Bind the button's click event to the OnExit function
    exitButton->Bind(wxEVT_BUTTON, &MainFrame::OnExitButtonClick, this);

    // Add the exit button to the sizer
    sizer->Add(exitButton, 0, wxALIGN_RIGHT | wxBOTTOM | wxRIGHT, 10);

    // Set the MainFrame's sizer
    SetSizer(sizer);
    Fit();
}




void MainFrame::OnRadioBox(wxCommandEvent& event)
{
    m_selectedOption = m_radiobox->GetSelection();
}
void MainFrame::OnButtonClick(wxCommandEvent& event)
{   
    functions lists;
    MyDialog dlg(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);  // Declare sizer here


    switch (m_selectedOption)
    {
    case 0:
        lists.listIngredients(static_cast<wxWindow*>(this));
        break;
    case 1:
        lists.addIngredient(static_cast<wxWindow*>(this));

        break;

    case 2:
        // Do something for option 3
        // ...
        lists.listRecipes(static_cast<wxWindow*>(this), 'n');
        break;

    case 3:
        lists.addRecipe(static_cast<wxWindow*>(this));
        break;
    case 4:
        lists.listRecipes(static_cast<wxWindow*>(this), 'y');

        break;
    case 5:
        lists.makeRecipe(static_cast<wxWindow*>(this));
        break;

    case 6:
        lists.displayInstructions(static_cast<wxWindow*>(this));
        break;
    }

}

