// Fill out your copyright notice in the Description page of Project Settings.


#include "SLoginWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLoginWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;
	FSlateFontInfo font = FCoreStyle::Get().GetFontStyle("Arial");
	font.Size = 30.f;
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Blue)
		]
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		.Padding(FMargin(50.f))
		[

			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Left)
			[

				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					//input box for username
					SNew(SEditableTextBox)
					.HintText(FText::FromString("username"))
					.Font(font)
				]
				
				//password input box
				+ SVerticalBox::Slot()
				.Padding(FMargin(10.f))
				[
					SNew(SEditableTextBox)
					.HintText(FText::FromString("password"))
					.Font(font)
				]

				//Login Button
				+ SVerticalBox::Slot()
				.Padding(FMargin(5.f))
				[
					SNew(SButton)
					.OnClicked(this, &SLoginWidget::OnLoginClick)
					[
						SNew(STextBlock)
						.Text(FText::FromString("Login"))
						.Font(font)
					]

				]
			]
			
			//create account widgets
			+ SHorizontalBox::Slot()
			.Padding(FMargin(100.f))
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Right)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(SEditableTextBox)
					.HintText(FText::FromString("Email"))
					.Font(font)
				]
				+ SVerticalBox::Slot()
				.Padding(FMargin(10.f))
				[
					SNew(SEditableTextBox)
					.HintText(FText::FromString("Username"))
					.Font(font)
				]
				+ SVerticalBox::Slot()
				.Padding(FMargin(10.f))
				[
					SNew(SEditableTextBox)
					.HintText(FText::FromString("Password"))
					.Font(font)
				]
				+ SVerticalBox::Slot()
				.Padding(FMargin(10.f))
				[
					SNew(SButton)
					[
						SNew(STextBlock)
						.Text(FText::FromString("Create Account"))
						.Font(font)
						.Justification(ETextJustify::Center)
					]
				]


			]

		    /*
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				//input box for username
				SNew(SEditableTextBox)
				.HintText(FText::FromString("username"))
				.Font(font)
			]
			+ SVerticalBox::Slot()
			.Padding(FMargin(10.f))
			[
				SNew(SEditableTextBox)
				.HintText(FText::FromString("password"))
				.Font(font)
			]
			+ SVerticalBox::Slot()
			.Padding(FMargin(5.f))
			[
				SNew(SButton)
				.OnClicked(this, &SLoginWidget::OnLoginClick)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Login"))
					.Font(font)
				]
				
			]
			*/

		]
	];
	
}

FReply SLoginWidget::OnLoginClick() const
{
	if (OwnerHUD.IsValid())
	{
		OwnerHUD->removeLogin();
		OwnerHUD->showMainMenu();
	}
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
