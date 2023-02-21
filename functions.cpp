#include "functions.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <map>
#include<numeric>

#include "converTo.h"

//constructors


functions::functions() {
	this->fridge = readIngredientsFromFile("Fridge.txt");
	this->recipes = readRecipes("directions.txt");
}

std::vector<ingredients> functions::setAmount(int place, double amount) {
	ingredients temp(amount, fridge[place].getUnit(), fridge[place].getName());
	fridge.erase(fridge.begin() + place);
	this->fridge.push_back(temp);
	return fridge;
}

std::vector<ingredients> functions::addFridge(ingredients temp) {
	fridge.push_back(temp);
	return fridge;
}






//add ingredient

void functions::editValues(wxWindow* parent, int &selected,char FoR,int iListSelection) {
	wxDialog* editor = new wxDialog(parent, wxID_ANY, "Edit ", wxDefaultPosition, wxSize(600, 100));
	if (FoR == 'f') {
		editor = new wxDialog(parent, wxID_ANY, "Edit " + fridge[selected].getName(), wxDefaultPosition, wxSize(600, 100));
	}
	else {
		editor = new wxDialog(parent, wxID_ANY, "Edit " + recipes[selected].getiList()[iListSelection].getName(), wxDefaultPosition, wxSize(600, 100));
	}
	wxButton* exitBtn = new wxButton(editor, wxID_CANCEL, "Exit");
	
	wxButton* deleteBtn = new wxButton(editor, wxID_ANY, "Delete Ingredient");

	deleteBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		if (FoR == 'f') {
			fridge.erase(fridge.begin() + selected);
			wxMessageBox("Ingredient Deleted", "Ingredient Deleted", wxOK | wxICON_INFORMATION);
			writeIngredientsToFile("fridge.txt", getFridge());
			editor->EndModal(wxID_OK);
		}
		else {
			std::vector<ingredients> tempiList = recipes[selected].getiList();
			tempiList.erase(tempiList.begin() + iListSelection);
			recipes[selected].setIlist(tempiList);
			wxMessageBox("Ingredient Deleted", "Ingredient Deleted", wxOK | wxICON_INFORMATION);
			writeIngredientsToFile2("recipes.txt", getRecipes());
			editor->EndModal(wxID_OK);
		}


		});
	wxButton* editAmntBtn = new wxButton(editor, wxID_ANY, "Edit Amount");
	editAmntBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int test = selected;
	if (test != wxNOT_FOUND) {
		// Show a editor to get the new amount and unit
		wxString amountStr = wxGetTextFromUser("Enter the new amount:", "Edit amount", "", editor);
		if (!amountStr.empty()) {
			double amount;
			if (amountStr.ToDouble(&amount)) {
				if (FoR == 'f') {
					fridge[test].setAmount(amount);
					wxMessageBox("Amount Changed", "Success", wxOK | wxICON_INFORMATION);
					writeIngredientsToFile("fridge.txt", getFridge());
					editor->EndModal(wxID_OK);
				}
				else {
					std::vector<ingredients> tempiList = recipes[selected].getiList();
					tempiList[iListSelection].setAmount(amount);
					recipes[selected].setIlist(tempiList);
					wxMessageBox("Amount Changed", "Success", wxOK | wxICON_INFORMATION);
					writeIngredientsToFile2("recipes.txt", getRecipes());
					editor->EndModal(wxID_OK);
				}

			}
			else {
				wxMessageBox("Invalid amount", "Error", wxOK | wxICON_ERROR, editor);
			}
		}
	}
	else {
		wxMessageBox("No item test", "Error", wxOK | wxICON_ERROR, editor);
	}
		});
	wxButton* editUnitBtn = new wxButton(editor, wxID_ANY, "Edit Measurement");
	editUnitBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int test = selected;
	if (test != wxNOT_FOUND) {
		wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
		if (fridge[test].getChoice() < 10) {
			wxString unitChoices[] = { "", "ml", "fl oz", "c", "pt", "qt", "gal", "tbsp", "tsp","L" };
			wxSingleChoiceDialog editUnit(editor, "Select the new unit:", "Edit unit", WXSIZEOF(unitChoices), unitChoices);
			wxFont font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
			editUnit.SetSize(wxSize(300, 300));
			if (editUnit.ShowModal() == wxID_OK) {
				int choice = editUnit.GetSelection();
				double amount = 0;
				ingredients temp(5.2, unitChoices[choice].ToStdString(), "temp");
				if (FoR == 'f') {
					amount = fridge[test].converToC(fridge[test], temp, 'e');
					fridge[test].setAmount(amount);
					fridge[test].getUnit(unitChoices[choice].ToStdString());
					wxMessageBox("Unit Changed", "Success", wxOK | wxICON_INFORMATION);
				}
				else {
					amount = fridge[test].converToC(recipes[selected].getiList()[iListSelection], temp, 'e');
					std::vector<ingredients> tempiList = recipes[selected].getiList();
					tempiList[iListSelection].setAmount(amount);
					tempiList[iListSelection].getUnit(unitChoices[choice].ToStdString());
					recipes[selected].setIlist(tempiList);

					wxMessageBox("Unit Changed", "Success", wxOK | wxICON_INFORMATION);
				}
			}


		}
		else {
			wxString unitChoices[] = { "mg","g", "kg", "oz", "lb" };
			wxSingleChoiceDialog editUnit(editor, "Select the new unit:", "Edit unit", WXSIZEOF(unitChoices), unitChoices);
			editUnit.SetFont(font);
			editUnit.SetSize(wxSize(300, 300));
			if (editUnit.ShowModal() == wxID_OK) {
				int choice = editUnit.GetSelection();
				double amount = 0;
				ingredients temp(5.2, unitChoices[choice].ToStdString(), "temp");
				if (FoR == 'f') {
					amount = fridge[test].converToG(fridge[test], temp, 'e');
					fridge[test].setAmount(amount);
					fridge[test].getUnit(unitChoices[choice].ToStdString());
					wxMessageBox("Unit Changed", "Success", wxOK | wxICON_INFORMATION);
				}
				else {
					amount = fridge[test].converToG(recipes[selected].getiList()[iListSelection], temp, 'e');
					std::vector<ingredients> tempiList = recipes[selected].getiList();
					tempiList[iListSelection].setAmount(amount);
					tempiList[iListSelection].getUnit(unitChoices[choice].ToStdString());
					recipes[selected].setIlist(tempiList);
					wxMessageBox("Unit Changed", "Success", wxOK | wxICON_INFORMATION);
				}
			}
			

		}
	if (FoR == 'f') {
		writeIngredientsToFile("fridge.txt", getFridge());
	}
	else {
		writeIngredientsToFile2("recipes.txt", getRecipes());
	}
		editor->EndModal(wxID_OK);

	}

	else {
		wxMessageBox("No item selected", "Error", wxOK | wxICON_ERROR, editor);
		editor->EndModal(wxID_OK);
	}
		});

	wxFont font = exitBtn->GetFont();
	font.SetPointSize(15);
	exitBtn->SetFont(font);
	editUnitBtn->SetFont(font);
	editAmntBtn->SetFont(font);
	deleteBtn->SetFont(font);
	wxBoxSizer* hSizer = new wxBoxSizer(wxHORIZONTAL);
	hSizer->Add(editUnitBtn, 0, wxALIGN_LEFT, 10);
	hSizer->Add(editAmntBtn, 0, wxALIGN_LEFT, 10);
	hSizer->Add(deleteBtn, 0, wxALIGN_LEFT, 10);
	hSizer->AddStretchSpacer(1);
	hSizer->Add(exitBtn, 0, 10);
	editor->SetSizer(hSizer);
	editor->ShowModal();



}

void functions::addIngredient(wxWindow* parent) {
	wxDialog* dialog = new wxDialog(parent, wxID_ANY, "Add Ingredient", wxDefaultPosition, wxSize(500, 500));
	wxButton* addButton = new wxButton(dialog, wxID_CANCEL, "Add");

	// Create labels for the double inputs
	wxStaticText* wholeNumLabel = new wxStaticText(dialog, wxID_ANY, "Whole Number:");
	wxStaticText* fractionLabel = new wxStaticText(dialog, wxID_ANY, "Fraction (Optional):");
	wxStaticText* fractionDivider = new wxStaticText(dialog, wxID_ANY, "/");

	// Create double inputs for whole number and fraction

	wxTextCtrl* doubleInput = new wxTextCtrl(dialog, wxID_HIGHEST + 1, wxEmptyString, wxPoint(), wxSize(150, -1), 0, wxDefaultValidator, wxTextCtrlNameStr);
	wxTextCtrl* doubleInput2 = new wxTextCtrl(dialog, wxID_HIGHEST + 2, wxEmptyString, wxPoint(), wxSize(50, -1), 0, wxDefaultValidator, wxTextCtrlNameStr);
	wxTextCtrl* doubleInput3 = new wxTextCtrl(dialog, wxID_HIGHEST + 3, wxEmptyString, wxPoint(), wxSize(50, -1), 0, wxDefaultValidator, wxTextCtrlNameStr);


	// Create label for unit input
	wxStaticText* unitLabel = new wxStaticText(dialog, wxID_ANY, "Unit:");

	wxString unitChoices[] = { "", "ml", "fl oz", "c", "pt", "qt", "gal", "tbsp", "tsp","L", "mg","g", "kg", "oz", "lb" };
	wxChoice* unitInput = new wxChoice(dialog, wxID_ANY, wxDefaultPosition, wxSize(100, -1), WXSIZEOF(unitChoices), unitChoices);
	unitInput->SetSelection(0);



	// Create a label for the string input
	wxStaticText* stringLabel = new wxStaticText(dialog, wxID_ANY, "Ingredient:");
	wxTextCtrl* stringInput = new wxTextCtrl(dialog, wxID_ANY, wxEmptyString, wxPoint(), wxSize(150, -1), 0, wxDefaultValidator, wxTextCtrlNameStr);
	wxListBox* ingredientListBox = new wxListBox(dialog, wxID_ANY, wxDefaultPosition, wxSize(200, 150));







	wxButton* exitButton = new wxButton(dialog, wxID_ANY, "Exit");
	exitButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		dialog->EndModal(wxID_CANCEL);
		});


	addButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		if (stringInput->GetValue().IsEmpty() || doubleInput->GetValue().IsEmpty()) {
			wxMessageBox("All fields must be filled in", "Error", wxOK | wxICON_ERROR);
			return;
		}
	double wholNum = wxAtof(doubleInput->GetValue());
	double amnt1 = 1, amnt2 = 1;
	double quantity = wholNum;
	if (doubleInput2->GetValue().empty() && doubleInput3->GetValue().empty()) {
	}
	else if (doubleInput2->GetValue().empty() || doubleInput3->GetValue().empty()) {
		// Only one fraction field is filled
		wxMessageBox("Both fraction fields must be filled", "Error", wxOK | wxICON_ERROR);
		return;
	}
	else {
		// Both fraction fields are filled
		amnt1 = wxAtof(doubleInput2->GetValue());
		amnt2 = wxAtof(doubleInput3->GetValue());
		quantity = wholNum + (amnt1 / amnt2);
		if (amnt1 == 0 || amnt2 == 0) {
			wxMessageBox("Both fraction fields must be non-zero", "Error", wxOK | wxICON_ERROR);
			return;
		}
	}
	int choice = unitInput->GetSelection();
	std::string unit = unitChoices[choice].ToStdString();
	std::string name = stringInput->GetValue().ToStdString();
	std::transform(name.begin(), name.end(), name.begin(), ::tolower); // convert name to lowercase
	name[0] = toupper(name[0]);
	ingredients newIngredient(quantity, unit, name);
	unsigned int place = 0, place2 = 0, place3 = 0;
	bool found = false;
	for (unsigned int i = 0; i < fridge.size(); i++) {
		if (name == fridge[i].getName()) {
			found = true;
			place = i;
			break;
		}
	}
	if (found) {
		for (int i = 0; i < 15; i++) {
			if (unit == unitChoices[i]) {
				place2 = i;
			}
			if (fridge[place].getUnit() == unitChoices[i]) {
				place3 = i;
			}
		}
		if (place2 < 10 && place3 < 10) {
			double d = fridge[place].converToC(fridge[place], newIngredient, 'n');
			fridge = setAmount(place, d);
			wxMessageBox("Ingredient added to fridge", "Success", wxOK | wxICON_INFORMATION);
			ingredientListBox->AppendString(wxString::Format("%.2f %s %s", quantity, unit, name));
			writeIngredientsToFile("fridge.txt", getFridge());



		}
		else if (place2 >= 10 && place3 >= 10) {
			double d = fridge[place].converToG(fridge[place], newIngredient, 'n');
			fridge = setAmount(place, d);
			wxMessageBox("Ingredient added to fridge", "Success", wxOK | wxICON_INFORMATION);
			ingredientListBox->AppendString(wxString::Format("%.2f %s %s", quantity, unit, name));
			writeIngredientsToFile("fridge.txt", getFridge());


		}
		else {
			wxMessageBox("Unit must be compatable with the unit stored. (volume -> volume and mass -> mass)", "Please try again", wxOK | wxICON_INFORMATION);
			dialog->EndModal(wxID_OK);
		}

	}
	else {
		fridge.push_back(newIngredient);
		writeIngredientsToFile("fridge.txt", getFridge());
		wxMessageBox("Ingredient added to fridge", "Success", wxOK | wxICON_INFORMATION);
		ingredientListBox->AppendString(wxString::Format("%.2f %s %s", quantity, unit, name));


	}

		});

	dialog->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
		dialog->EndModal(wxID_CANCEL);
		});
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);


	wxBoxSizer* doubleSizer = new wxBoxSizer(wxHORIZONTAL);
	doubleSizer->Add(wholeNumLabel, 0, wxALL, 5);
	doubleSizer->Add(doubleInput, 0, wxALL, 5);
	doubleSizer->Add(fractionLabel, 0, wxALL, 5);
	doubleSizer->Add(doubleInput2, 0, wxALL, 5);
	doubleSizer->Add(fractionDivider, 0, wxALL, 5);
	doubleSizer->Add(doubleInput3, 0, wxALL, 5);
	topSizer->Add(doubleSizer, 0, wxEXPAND);


	wxBoxSizer* unitSizer = new wxBoxSizer(wxHORIZONTAL);
	unitSizer->Add(unitLabel, 0, wxALL, 5);
	unitSizer->Add(unitInput, 0, wxALL, 5);
	topSizer->Add(unitSizer, 0, wxEXPAND);

	wxBoxSizer* stringSizer = new wxBoxSizer(wxHORIZONTAL);
	stringSizer->Add(stringLabel, 0, wxALL, 5);
	stringSizer->Add(stringInput, 0, wxALL, 5);
	stringSizer->Add(addButton, 0, wxALL, 5);
	stringSizer->Add(exitButton, 0, wxALL, 5);
	topSizer->Add(stringSizer, 0, wxEXPAND);


	topSizer->Add(ingredientListBox, 1, wxEXPAND | wxALL, 5);


	dialog->SetSizer(topSizer);
	topSizer->Fit(dialog);
	topSizer->SetSizeHints(dialog);

	dialog->ShowModal();

}


//list ingredients
void functions::listIngredients(wxWindow* parent) {
	wxDialog* dialog = new wxDialog(parent, wxID_ANY, "List of ingredients", wxDefaultPosition, wxSize(600, 600));
	wxListBox* listbox = new wxListBox(dialog, wxID_ANY);
	wxButton* exitBtn = new wxButton(dialog, wxID_CANCEL, "Exit");

	wxButton* changeValue = new wxButton(dialog, wxID_CANCEL, "Edit Value");

	if (!listbox) {
		std::cout << "Error: Unable to create listbox" << std::endl;
		return;
	}

	changeValue->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int selected = listbox->GetSelection();
	if (selected == wxNOT_FOUND) {
		wxMessageBox("No item selected");
		return;
	}
	editValues(dialog, selected,'f',0);
	listbox->Clear();
	for (unsigned int i = 0; i < fridge.size(); i++) {
		std::stringstream item;
		item << std::setw(2) << std::setfill('0') << i + 1 << ".) " << std::fixed << std::setprecision(2) << fridge[i].getAmount() << ' ';
		item << fridge[i].getUnit() << ' ' << fridge[i].getName();
		listbox->Append(item.str());
	}
		});


	listbox->Clear();
	if (fridge.empty()) {
		wxMessageBox("Fridge is Empty. Please add some ingredients.");
		return;
	}

	for (unsigned int i = 0; i < fridge.size(); i++) {
		std::stringstream item;
		item << std::setw(2) << std::setfill('0') << i + 1 << ".) " << std::fixed << std::setprecision(2) << fridge[i].getAmount() << ' ';
		item << fridge[i].getUnit() << ' ' << fridge[i].getName();
		listbox->Append(item.str());
	}

	wxFont font = listbox->GetFont();
	font.SetPointSize(15);
	listbox->SetFont(font);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	mainSizer->Add(listbox, 1, wxEXPAND | wxALL, 10);
	buttonSizer->Add(changeValue, 1, wxEXPAND | wxALL, 10);
	buttonSizer->Add(exitBtn, 1, wxEXPAND | wxALL, 10);
	mainSizer->Add(buttonSizer, 0, wxALIGN_RIGHT | wxALL, 10);

	dialog->SetSizer(mainSizer);

	dialog->ShowModal();
}






//list and show recipes
void functions::showRecipe(wxWindow* parent, int index, std::vector<recipesL>& recipes) {
	if (index < 0 || index >= recipes.size()) {
		std::cout << "Error: Invalid recipe index" << std::endl;
		return;
	}
	wxFont headerFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont normalFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	wxDialog* dialog = new wxDialog(parent, wxID_ANY, "Recipe Details", wxDefaultPosition, wxSize(600, 600));
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* nameLabel = new wxStaticText(dialog, wxID_ANY, "Name:");
	nameLabel->SetFont(headerFont);
	wxStaticText* nameValue = new wxStaticText(dialog, wxID_ANY, recipes[index].getName());
	nameValue->SetFont(normalFont);
	sizer->Add(nameLabel, 0, wxLEFT | wxTOP, 10);
	sizer->Add(nameValue, 0, wxLEFT | wxTOP, 10);

	wxStaticText* ingredientsLabel = new wxStaticText(dialog, wxID_ANY, "Ingredients:");
	ingredientsLabel->SetFont(headerFont);
	sizer->Add(ingredientsLabel, 0, wxLEFT | wxTOP, 10);

	for (const ingredients& ing : recipes[index].getiList()) {
		std::string number = doubleToStringAndFraction(ing.getAmount());

		wxStaticText* ingText = new wxStaticText(dialog, wxID_ANY, " -" + number +" " + ing.getUnit() + " of " + ing.getName());
		ingText->SetFont(normalFont);
		sizer->Add(ingText, 0, wxLEFT, 20);
	}

	wxStaticText* directionsLabel = new wxStaticText(dialog, wxID_ANY, "Directions:");
	directionsLabel->SetFont(headerFont);
	wxStaticText* directionsValue = new wxStaticText(dialog, wxID_ANY, recipes[index].getDirections());
	directionsValue->SetFont(normalFont);
	sizer->Add(directionsLabel, 0, wxLEFT | wxTOP, 10);
	sizer->Add(directionsValue, 0, wxLEFT | wxTOP, 10);

	wxButton* exitBtn = new wxButton(dialog, wxID_CANCEL, "Exit");
	exitBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		dialog->EndModal(wxID_CANCEL);
		});
	sizer->Add(exitBtn, 0, wxALL, 10);

	dialog->SetSizer(sizer);
	dialog->ShowModal();
}


void functions::listRecipes(wxWindow* parent,char makeable){
	
	 
	wxDialog* dialog = new wxDialog(parent, wxID_ANY, "List of Recipes",
		wxDefaultPosition, wxSize(600, 600));

	wxListBox* listbox = new wxListBox(dialog, wxID_ANY);
	wxFont font = listbox->GetFont();
	font.SetPointSize(15);
	listbox->SetFont(font);

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(listbox, 1, wxEXPAND | wxALL, 10);

	wxButton* exitBtn = new wxButton(dialog, wxID_CANCEL, "Exit");
	exitBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		dialog->EndModal(wxID_CANCEL);
		});

	wxButton* viewRecipeBtn = new wxButton(dialog, wxID_ANY, "View Recipe");
	wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
	if (makeable != 'y') {
	
	wxButton* deleteRecipe = new wxButton(dialog, wxID_ANY, "Delete Recipe");
	deleteRecipe->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int place = listbox->GetSelection();
	if (place == wxNOT_FOUND) {
		wxMessageBox("Nothing selected", "Error", wxOK | wxICON_ERROR);
		return;
	}
	recipes.erase(recipes.begin() + place);
	wxMessageBox("Recipe deleted", "Complete", wxOK);
	writeRecipesToFile3("directions.txt", getRecipes());
	writeIngredientsToFile2("recipes.txt", getRecipes());
	dialog->EndModal(wxID_CANCEL);
		});
	
		btnSizer->Add(deleteRecipe, 0, wxALL, 10);
	}

	wxButton* editRecipeBtn = new wxButton(dialog, wxID_ANY, "Edit Recipe");
	editRecipeBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int place = listbox->GetSelection();
	if (place == wxNOT_FOUND) {
		wxMessageBox("Nothing selected", "Error", wxOK | wxICON_ERROR);
		return;
	}
	editRecipe(dialog, place);
	listbox->Clear();
	for (unsigned int i = 0; i < recipes.size(); i++) {
		std::stringstream item;
		item << std::setw(2) << std::setfill('0') << i + 1 << ".) " << recipes[i].getName();
		listbox->Append(item.str());
	}
		});

	btnSizer->Insert(0, editRecipeBtn, 0, wxALL, 10);
	btnSizer->Add(viewRecipeBtn, 0, wxALL, 10);
	btnSizer->Add(exitBtn, 0, wxALL, 10);

	sizer->Add(btnSizer, 0, wxALIGN_RIGHT);

	dialog->SetSizer(sizer);
	std::vector<recipesL> list = findMakeableRecipes();
	if (makeable == 'y') {
		viewRecipeBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
			int selectedIndex = listbox->GetSelection();
			if (selectedIndex == wxNOT_FOUND) {
				std::cout << "Error: No recipe selected" << std::endl;
				return;
			}
			showRecipe(parent, selectedIndex, list);
			});

		listbox->Bind(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, [&](wxCommandEvent& event) {
			showRecipe(parent, event.GetInt(), list);
			});
	}
	else {
		viewRecipeBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
			int selectedIndex = listbox->GetSelection();
			if (selectedIndex == wxNOT_FOUND) {
				std::cout << "Error: No recipe selected" << std::endl;
				return;
			}
			showRecipe(parent, selectedIndex, recipes);
			});

		listbox->Bind(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, [&](wxCommandEvent& event) {
			showRecipe(parent, event.GetInt(), recipes);
			});
	}

	if (recipes.empty()) {
		listbox->Append("You have no recipes");
		return;
	}
	if (makeable == 'y') {
		for (unsigned int i = 0; i < list.size(); i++) {
			std::stringstream item;
			item << std::setw(2) << std::setfill('0') << i + 1 << ".) " << list[i].getName();
			listbox->Append(item.str());
		}

	}
	else {
		for (unsigned int i = 0; i < recipes.size(); i++) {
			std::stringstream item;
			item << std::setw(2) << std::setfill('0') << i + 1 << ".) " << recipes[i].getName();
			listbox->Append(item.str());
		}
	}

	dialog->ShowModal();
}

void functions::editRecipe(wxWindow* parent,int &selection) {
	wxDialog* editor = new wxDialog(parent, wxID_ANY, "Edit " + recipes[selection].getName(), wxDefaultPosition, wxSize(600, 100));	
	wxButton* exitBtn = new wxButton(editor, wxID_CANCEL, "Exit");

	wxButton* deleteBtn = new wxButton(editor, wxID_ANY, "Delete Recipe");

	deleteBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		recipes.erase(recipes.begin() + selection);
	wxMessageBox("Recipe Deleted", "Recipe Deleted", wxOK | wxICON_INFORMATION);
	writeRecipesToFile3("directions.txt", getRecipes());
	writeIngredientsToFile2("recipes.txt", getRecipes());
	
	editor->EndModal(wxID_OK);


		});
	wxButton* editName = new wxButton(editor, wxID_ANY, "Edit Recipe Name");
	editName->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		wxTextEntryDialog dialog(editor, "Enter the new name for the recipe:", "Edit Recipe Name");
	if (dialog.ShowModal() == wxID_OK) {
		std::string name = dialog.GetValue().ToStdString();
		std::transform(name.begin(), name.end(), name.begin(), ::tolower); // convert name to lowercase
		name[0] = toupper(name[0]);
		if (name.empty()) {
			wxMessageBox("Error: Recipe name cannot be empty!", "Error", wxOK | wxICON_ERROR);
			return;
		}
		recipes[selection].setName(name);
		wxMessageBox("Recipe name updated!", "Update Successful", wxOK | wxICON_INFORMATION);
		writeRecipesToFile3("directions.txt", getRecipes());
		editor->EndModal(wxID_OK);
		return;

	}
		});


	wxButton* editDirectionsBtn = new wxButton(editor, wxID_ANY, "Edit Directions");
	editDirectionsBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		wxTextEntryDialog directionsDialog(editor, "Enter or edit the directions for the recipe:", "Edit Directions", recipes[selection].getDirections(), wxOK | wxCANCEL | wxTE_MULTILINE);
	directionsDialog.SetSize(wxSize(800, 800));
	directionsDialog.Centre();
	if (directionsDialog.ShowModal() == wxID_OK) {
		recipes[selection].setDirections(directionsDialog.GetValue().ToStdString());
		writeRecipesToFile3("directions.txt", getRecipes());
	}
		});
	wxButton* editIngredients = new wxButton(editor, wxID_ANY, "Edit Ingredients");
	editIngredients->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		std::vector<ingredients> ingredientsList = recipes[selection].getiList();
	wxArrayString choices;
	for (auto& ingredient : ingredientsList) {
		choices.Add(ingredient.getName());
	}

	wxSingleChoiceDialog selectIngredientDialog(editor, "Select an ingredient to edit:", "Edit Ingredients", choices);
	if (selectIngredientDialog.ShowModal() == wxID_OK) {
		int selectedIndex = selectIngredientDialog.GetSelection();

		editValues(parent, selection,'r', selectedIndex);
		}
		});



	wxFont font = exitBtn->GetFont();
	font.SetPointSize(10);
	exitBtn->SetFont(font);
	editName->SetFont(font);
	editDirectionsBtn->SetFont(font);
	deleteBtn->SetFont(font);
	wxBoxSizer* hSizer = new wxBoxSizer(wxHORIZONTAL);
	hSizer->Add(editName, 0, wxALIGN_LEFT, 10);
	hSizer->Add(editDirectionsBtn, 0, wxALIGN_LEFT, 10);
	hSizer->Add(editIngredients, 0, wxALIGN_LEFT, 10);
	hSizer->Add(deleteBtn, 0, wxALIGN_LEFT, 10);
	hSizer->AddStretchSpacer(1);
	hSizer->Add(exitBtn, 0, 10);
	editor->SetSizer(hSizer);
	editor->ShowModal();



}




//add and make recipe
std::vector<recipesL> functions::findMakeableRecipes() {
	std::vector<recipesL> makeableRecipes;
	for (int i = 0; i < recipes.size(); i++) {
		bool makeable = true; // assume the recipe is makeable
		for (int j = 0; j < recipes[i].getiList().size(); j++) {
			bool ingredientFound = false;
			for (int k = 0; k < fridge.size(); k++) {
				if (recipes[i].getiList()[j].getName() == fridge[k].getName()) {
					if (fridge[k].getChoice() < 10) {
						if (fridge[k].converToC(fridge[k], recipes[i].getiList()[j], 'r') >= 0)
							ingredientFound = true;
						break;
					}
					else {
						if (fridge[k].converToG(fridge[k], recipes[i].getiList()[j], 'r') >= 0)
							ingredientFound = true;
						break;
					}
				}
			}
			if (!ingredientFound) {
				makeable = false;
				break;
			}
		}
		if (makeable) {

			makeableRecipes.push_back(recipes[i]);
			// Mark the recipe as makeable
		}
	}

	return makeableRecipes;
}


void functions::addRecipe(wxWindow* parent) {

	wxDialog* dialog = new wxDialog(parent, wxID_ANY, "Add a recipe",
		wxDefaultPosition, wxSize(600, 600));
	// Create a double input
	wxStaticText* doubleLabel = new wxStaticText(dialog, wxID_ANY, "Amount:");
	wxTextCtrl* doubleInput = new wxTextCtrl(dialog, wxID_ANY);

	wxStaticText* unitLabel = new wxStaticText(dialog, wxID_ANY, "Unit:");
	wxString unitChoices[] = { "", "ml", "fl oz", "c", "pt", "qt", "gal", "tbsp", "tsp","L", "mg","g", "kg", "oz", "lb" };
	unitInput = new wxChoice(dialog, wxID_ANY, wxDefaultPosition, wxDefaultSize, WXSIZEOF(unitChoices), unitChoices);
	unitInput->SetSelection(0);

	wxStaticText* stringLabel = new wxStaticText(dialog, wxID_ANY, "Ingredient:");
	wxTextCtrl* stringInput = new wxTextCtrl(dialog, wxID_ANY);

	wxStaticText* nameLabel = new wxStaticText(dialog, wxID_ANY, "Recipe Name:");
	wxTextCtrl* nameInput = new wxTextCtrl(dialog, wxID_ANY);

	wxStaticText* directionsBox = new wxStaticText(dialog, wxID_ANY, "Directions:");
	wxTextCtrl* directionsInput = new wxTextCtrl(dialog, wxID_ANY, "", wxDefaultPosition, wxSize(500, 200), wxTE_MULTILINE);

	

	wxListBox* listbox = new wxListBox(dialog, wxID_ANY);
	wxFont font = listbox->GetFont();
	font.SetPointSize(11);
	listbox->SetFont(font);


	std::vector<ingredients> tempList;


	wxButton* exitBtn = new wxButton(dialog, wxID_CANCEL, "Exit");
	exitBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		dialog->EndModal(wxID_CANCEL);
		}); //Exit dialog

	wxButton* addIngredient = new wxButton(dialog, wxID_CANCEL, "Add Ingredient to Recipe");
	addIngredient->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		std::string stringamount = doubleInput->GetValue().ToStdString();
	wxString tempV = doubleInput ->GetValue();
	int choice = unitInput->GetSelection();
	tempV = stringInput->GetValue();
	if (tempV.empty() || stringamount.empty()) {
		wxMessageBox("Please fill out all fields");
		return;
	}

	std::string name = tempV.ToStdString();

	double quantity = wxAtof(tempV);
	std::string unit = unitChoices[choice].ToStdString();
	double amount = std::stof(doubleInput->GetValue().ToStdString());
	;
	
	std::transform(name.begin(), name.end(), name.begin(), ::tolower); // convert name to lowercase
	name[0] = toupper(name[0]);
	
	for (unsigned int i = 0; i < tempList.size(); i++) {
		if (tempList[i].getName() == name) {
			wxMessageBox("This ingredient has already been added");
			return;
		}
	}
	tempList.push_back(ingredients(amount, unit, name));
	listbox->AppendString(wxString::Format("%.2f %s %s", amount, unit, name));
	doubleInput->Clear();
	stringInput->Clear();
	unitInput->SetSelection(0);
		});


	wxButton* saveRecipe = new wxButton(dialog, wxID_OK, "Save Recipe");
	saveRecipe->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		std::string recipeTitle = nameInput->GetValue().ToStdString();
		std::transform(recipeTitle.begin(), recipeTitle.end(), recipeTitle.begin(), ::tolower); // convert name to lowercase
		recipeTitle[0] = toupper(recipeTitle[0]);
		for (int i = 0; i < recipes.size(); i++) {
			if (recipeTitle == recipes[i].getName()) {
				wxMessageBox("Recipe exists already. Please delete or rename");
				return;
			}
		}
		if (recipeTitle.empty()) {
			wxMessageBox("Please fill out recipe name");
			return;
		}
		std::string directions = directionsInput->GetValue().ToStdString();
		if (tempList.empty() || directions.empty()) {
			wxMessageBox("Please fill out ingredients and directions");
			return;
		}
		recipes.push_back(recipesL(tempList, recipeTitle, directions));
		wxMessageBox("Recipe saved");
		writeRecipesToFile3("directions.txt", getRecipes());
		writeIngredientsToFile2("recipes.txt", getRecipes());
		dialog->EndModal(wxID_OK);
		}); // save recipe


	wxButton* deleteIng = new wxButton(dialog, wxID_OK, "Delete Ingredient");
	deleteIng->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int place = listbox->GetSelection();
	if (place == wxNOT_FOUND) {
		wxMessageBox("Error: No ingredient selected", "Error", wxOK | wxICON_ERROR);
		return;
	}
	tempList.erase(tempList.begin() + place);
	listbox->Delete(place);
		}); //delete ingredient from listbox


	//layout

	wxFlexGridSizer* flexSizer = new wxFlexGridSizer(8, 3, 3, 3);

	flexSizer->Add(doubleLabel, 0, wxALL, 5);
	flexSizer->Add(doubleInput, 0, wxALL, 5);
	flexSizer->AddSpacer(1);

	flexSizer->Add(unitLabel, 0, wxALL, 5);
	flexSizer->Add(unitInput, 0, wxALL, 5);
	flexSizer->AddSpacer(1);

	flexSizer->Add(stringLabel, 0, wxALL, 5);
	flexSizer->Add(stringInput, 0, wxALL, 5);
	flexSizer->AddSpacer(1);

	flexSizer->Add(addIngredient, 0, wxALL | wxALIGN_CENTER, 5);
	flexSizer->AddSpacer(1);
	flexSizer->AddSpacer(1);

	flexSizer->Add(nameLabel, 0, wxALL, 5);
	flexSizer->Add(nameInput, 0, wxALL, 5);
	flexSizer->AddSpacer(1);
	

	flexSizer->Add(directionsBox, 0, wxALL, 5);
	flexSizer->Add(directionsInput, 0, wxALL, 5);
	flexSizer->AddSpacer(1);

	flexSizer->Add(new wxStaticText(dialog, wxID_ANY, "Ingredients added: "), 0, wxALL, 5);
	flexSizer->Add(listbox, 1, wxALL | wxEXPAND, 5);
	flexSizer->AddSpacer(1);

	wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);
	btnSizer->Add(deleteIng, 0, wxALL | wxALIGN_LEFT, 5);
	btnSizer->Add(saveRecipe, 0, wxALL | wxALIGN_LEFT, 5);
	btnSizer->Add(exitBtn, 0, wxALL | wxALIGN_LEFT, 5);
	flexSizer->Add(btnSizer, 0, wxALL | wxALIGN_LEFT, 5);

	flexSizer->AddGrowableCol(1);
	flexSizer->AddGrowableRow(5);
	dialog->SetSizer(flexSizer);
	dialog->ShowModal();


}

void functions::makeRecipe(wxWindow* parent) {
	wxDialog* dialog = new wxDialog(parent, wxID_ANY, "Add a recipe");
	std::vector<recipesL> makeable = findMakeableRecipes();

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* recipeChoice = new wxStaticText(dialog, wxID_ANY, "Choose a recipe to make: ");
	wxChoice* recipeList = new wxChoice(dialog, wxID_ANY);

	for (unsigned int i = 0; i < makeable.size(); i++) {
		recipeList->Append(makeable[i].getName());
	}

	wxButton* make = new wxButton(dialog, wxID_ANY, "Make");
	wxButton* exitButton = new wxButton(dialog, wxID_ANY, "Exit");
	exitButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		dialog->EndModal(wxID_CANCEL);
		});
	

	wxButton* showRecipeBtn = new wxButton(dialog, wxID_ANY, "Show Recipe");
	showRecipeBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int choice = recipeList->GetSelection();
	if (choice == wxNOT_FOUND) {
		wxMessageBox("Please select a recipe to show.");
		return;
	}
		showRecipe(parent, choice, makeable);


		});

	hbox1->Add(recipeChoice, 1);
	hbox1->Add(recipeList, 1);

	hbox2->Add(showRecipeBtn, 1, wxALIGN_LEFT, 10);
	hbox2->Add(make, 1, wxALIGN_LEFT, 10);
	hbox2->Add(exitButton,1, wxALIGN_LEFT, 10);

	vbox->Add(hbox1, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(hbox2, 1, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

	dialog->SetSizer(vbox);

	make->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
		int choice = recipeList->GetSelection();
	if (choice == wxNOT_FOUND) {
		wxMessageBox("Please select a recipe to make.");
		return;
	}
	showRecipe(parent, choice, makeable);
	makeRecipeFunction(makeable[choice]);
	wxMessageBox("Recipe Made!");
	dialog->Close();
		});

	dialog->ShowModal();
}


void functions::makeRecipeFunction(recipesL recipe) {
	std::vector<ingredients> iList = recipe.getiList();

	for (int i = 0; i < iList.size();i++){
		for (int j = 0; j < fridge.size();j++){
			if (iList[i].getName() == fridge[j].getName()) {
				int place2 = fridge[j].getChoice();
					if (place2 < 10) {
					double d = fridge[j].converToC(fridge[j], iList[i], 't');
					fridge = setAmount(j, d);
					break;

				}
					else if (place2 >= 10) {
						double d = fridge[j].converToG(fridge[j], iList[i], 't');
						fridge = setAmount(j, d);
						break;
					}

			}
		}
	}
	writeIngredientsToFile("fridge.txt", getFridge());
}








//secondary functions

void functions::displayInstructions(wxWindow* parent)
{
	wxDialog* dlg = new wxDialog(parent, wxID_ANY, "Instructions", wxDefaultPosition, wxSize(700, 720));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	dlg->SetSizer(sizer);

	wxFont font = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	wxTextCtrl* textCtrl = new wxTextCtrl(dlg, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
	textCtrl->SetFont(font);
	sizer->Add(textCtrl, wxSizerFlags(1).Expand().Border(wxALL, 20));

	// Here you can set the instructions text that you want to display
	wxString instructions = "Welcome to our Virtual Fridge program, a fun and easy way to keep track of your fridge inventory and recipes! With our program, you can easily add ingredients to your fridge, save recipes, and see what you can make with the ingredients you have on hand.\n\nTo get started, select option 2 from the main menu and add your ingredients. It's easy! Just enter the quantity of the ingredient, select the unit from the dropdown menu(this will be the ingredients main unit type. Cannot add volume to mass or mass to volume), and enter the name. Click \"add\" and the ingredient is instantly added to your fridge.\n\nWant to see all your ingredients in one place? Select option 1 from the main menu and you'll see a list of all the ingredients in your fridge. You can even edit the unit, name, and amount of each ingredient. If you change the unit of an ingredient, our program will automatically adjust the amount in your fridge accordingly.\n\nNext, let's add a recipe! Select option 4 from the main menu and enter each ingredient one at a time, adding its quantity, selecting the unit from the dropdown menu, and entering the name. Once you've added all the ingredients, you can review them in the list at the bottom of the screen. Enter the recipe name and add some directions. When you're finished, save the recipe by clicking the \"save\" button at the bottom left of the screen.\n\nNow you have a saved database of ingredients and recipes! To view all your saved recipes, select option 3 from the main menu. You can view and edit each recipe, including its ingredients and directions.\n\nWant to see what you can make with the ingredients you have on hand? Select option 5 from the main menu and our program will show you a list of all the recipes you can make with the ingredients in your fridge.\n\nReady to make a recipe? Select option 5 again from the main menu and choose a recipe from the dropdown menu. Click \"make\" and our program will delete the ingredients from your fridge and mark the recipe as \"made\".";

	// Set the text in the text control
	textCtrl->SetValue(instructions);

	// Add an "OK" button to close the dialog box
	wxButton* okButton = new wxButton(dlg, wxID_OK, "OK");
	okButton->SetFont(font);
	sizer->Add(okButton, wxSizerFlags().Center().Border(wxALL, 20));

	// Show the dialog box
	dlg->ShowModal();

	// Clean up
	delete dlg;
}



int functions::gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}



std::string functions::doubleToStringAndFraction(double number) {
	int whole = static_cast<int>(number);
	double decimal = number - whole;
	if (decimal == 0) {
		return std::to_string(whole);
	}
	int denominator = 1;
	std::map<double, int> decimals;
	while (decimal != 0) {
		if (decimals.count(decimal) > 0) {
			denominator = decimals[decimal];
			break;
		}
		decimals[decimal] = denominator;
		decimal *= 10;
		denominator *= 10;
		int new_whole = static_cast<int>(decimal);
		decimal -= new_whole;
	}

	int numerator = static_cast<int>(number * denominator) - (whole * denominator);
	int gcd2 = gcd(numerator, denominator);
	numerator /= gcd2;
	denominator /= gcd2;

	return std::to_string(whole) + " " + std::to_string(numerator) + "/" + std::to_string(denominator);
}


