#include "pch.h"
#include "TruncatedCone.h"

using namespace System;
using namespace System::Windows::Forms;

ref class TruncatedConeForm : public Form {
private:
    TextBox^ heightTextBox;
    TextBox^ bottomRadiusTextBox;
    TextBox^ topRadiusTextBox;

    TextBox^ heightTextBox2;
    TextBox^ bottomRadiusTextBox2;
    TextBox^ topRadiusTextBox2;

    Button^ calculateButton;
    TextBox^ resultTextBox;

public:
    TruncatedConeForm() {

        this->Text = "Truncated Cone Volume Calculator";
        this->Size = Drawing::Size(500, 500); 
        this->StartPosition = FormStartPosition::CenterScreen;

        Label^ cone1Label = gcnew Label();
        cone1Label->Text = "Cone 1";
        cone1Label->Location = Drawing::Point(10, 10);
        cone1Label->Font = gcnew System::Drawing::Font(cone1Label->Font->FontFamily, 14);
        this->Controls->Add(cone1Label);

        Label^ heightLabel = gcnew Label();
        heightLabel->Text = "Height:";
        heightLabel->Location = Drawing::Point(10, 40);
        heightLabel->Font = gcnew System::Drawing::Font(heightLabel->Font->FontFamily, 14);
        this->Controls->Add(heightLabel);

        heightTextBox = gcnew TextBox();
        heightTextBox->Location = Drawing::Point(150, 40);
        heightTextBox->Size = Drawing::Size(150, 30);
        heightTextBox->Font = gcnew System::Drawing::Font(heightTextBox->Font->FontFamily, 14);
        this->Controls->Add(heightTextBox);

        Label^ bottomRadiusLabel = gcnew Label();
        bottomRadiusLabel->Text = "Bottom R:";
        bottomRadiusLabel->Location = Drawing::Point(10, 80);
        bottomRadiusLabel->Font = gcnew System::Drawing::Font(bottomRadiusLabel->Font->FontFamily, 14);
        this->Controls->Add(bottomRadiusLabel);

        bottomRadiusTextBox = gcnew TextBox();
        bottomRadiusTextBox->Location = Drawing::Point(150, 80);
        bottomRadiusTextBox->Size = Drawing::Size(150, 30);
        bottomRadiusTextBox->Font = gcnew System::Drawing::Font(bottomRadiusTextBox->Font->FontFamily, 14);
        this->Controls->Add(bottomRadiusTextBox);

        Label^ topRadiusLabel = gcnew Label();
        topRadiusLabel->Text = "Top R:";
        topRadiusLabel->Location = Drawing::Point(10, 120);
        topRadiusLabel->Font = gcnew System::Drawing::Font(topRadiusLabel->Font->FontFamily, 14);
        this->Controls->Add(topRadiusLabel);

        topRadiusTextBox = gcnew TextBox();
        topRadiusTextBox->Location = Drawing::Point(150, 120);
        topRadiusTextBox->Size = Drawing::Size(150, 30);
        topRadiusTextBox->Font = gcnew System::Drawing::Font(topRadiusTextBox->Font->FontFamily, 14);
        this->Controls->Add(topRadiusTextBox);

        Label^ cone2Label = gcnew Label();
        cone2Label->Text = "Cone 2";
        cone2Label->Location = Drawing::Point(10, 170);
        cone2Label->Font = gcnew System::Drawing::Font(cone2Label->Font->FontFamily, 14);
        this->Controls->Add(cone2Label);

        Label^ heightLabel2 = gcnew Label();
        heightLabel2->Text = "Height:";
        heightLabel2->Location = Drawing::Point(10, 200);
        heightLabel2->Font = gcnew System::Drawing::Font(heightLabel2->Font->FontFamily, 14);
        this->Controls->Add(heightLabel2);

        heightTextBox2 = gcnew TextBox();
        heightTextBox2->Location = Drawing::Point(150, 200);
        heightTextBox2->Size = Drawing::Size(150, 30);
        heightTextBox2->Font = gcnew System::Drawing::Font(heightTextBox2->Font->FontFamily, 14);
        this->Controls->Add(heightTextBox2);

        Label^ bottomRadiusLabel2 = gcnew Label();
        bottomRadiusLabel2->Text = "Bottom R:";
        bottomRadiusLabel2->Location = Drawing::Point(10, 240);
        bottomRadiusLabel2->Font = gcnew System::Drawing::Font(bottomRadiusLabel2->Font->FontFamily, 14);
        this->Controls->Add(bottomRadiusLabel2);

        bottomRadiusTextBox2 = gcnew TextBox();
        bottomRadiusTextBox2->Location = Drawing::Point(150, 240);
        bottomRadiusTextBox2->Size = Drawing::Size(150, 30);
        bottomRadiusTextBox2->Font = gcnew System::Drawing::Font(bottomRadiusTextBox2->Font->FontFamily, 14);
        this->Controls->Add(bottomRadiusTextBox2);

        Label^ topRadiusLabel2 = gcnew Label();
        topRadiusLabel2->Text = "Top R:";
        topRadiusLabel2->Location = Drawing::Point(10, 280);
        topRadiusLabel2->Font = gcnew System::Drawing::Font(topRadiusLabel2->Font->FontFamily, 14);
        this->Controls->Add(topRadiusLabel2);

        topRadiusTextBox2 = gcnew TextBox();
        topRadiusTextBox2->Location = Drawing::Point(150, 280);
        topRadiusTextBox2->Size = Drawing::Size(150, 30);
        topRadiusTextBox2->Font = gcnew System::Drawing::Font(topRadiusTextBox2->Font->FontFamily, 14);
        this->Controls->Add(topRadiusTextBox2);

        calculateButton = gcnew Button();
        calculateButton->Text = "Calculate";
        calculateButton->Location = Drawing::Point(10, 340);
        calculateButton->Size = Drawing::Size(150, 40); 
        calculateButton->Font = gcnew System::Drawing::Font(calculateButton->Font->FontFamily, 16); 
        calculateButton->Click += gcnew EventHandler(this, &TruncatedConeForm::CalculateButton_Click);
        this->Controls->Add(calculateButton);

        resultTextBox = gcnew TextBox();
        resultTextBox->Location = Drawing::Point(10, 390);
        resultTextBox->Size = Drawing::Size(300, 30); 
        resultTextBox->Font = gcnew System::Drawing::Font(resultTextBox->Font->FontFamily, 14); 
        resultTextBox->ReadOnly = true;
        this->Controls->Add(resultTextBox);
    }
private:
    void CalculateButton_Click(Object^ sender, EventArgs^ e) {
        try {
            double height = Double::Parse(heightTextBox->Text);
            double bottomRadius = Double::Parse(bottomRadiusTextBox->Text);
            double topRadius = Double::Parse(topRadiusTextBox->Text);

            if (height <= 0 || bottomRadius <= 0 || topRadius <= 0) {
                throw gcnew Exception("Invalid input! Please enter positive numeric values.");
            }

            TruncatedCone cone(height, bottomRadius, topRadius);
            double volume = cone.volume();

            double height2 = Double::Parse(heightTextBox2->Text);
            double bottomRadius2 = Double::Parse(bottomRadiusTextBox2->Text);
            double topRadius2 = Double::Parse(topRadiusTextBox2->Text);

            if (height2 <= 0 || bottomRadius2 <= 0 || topRadius2 <= 0) {
                throw gcnew Exception("Invalid input! Please enter positive numeric values.");
            }

            TruncatedCone cone2(height2, bottomRadius2, topRadius2);
            double volume2 = cone2.volume();

            if (volume > volume2) {
                resultTextBox->Text = "Cone 1 has a larger volume.";
            }
            else if (volume < volume2) {
                resultTextBox->Text = "Cone 2 has a larger volume.";
            }
            else {
                resultTextBox->Text = "Both objects have the same volume.";
            }
        }
        catch (FormatException^) {
            MessageBox::Show("Invalid input! Please enter numeric values.");
        }
        catch (Exception^ ex) {
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }
};
