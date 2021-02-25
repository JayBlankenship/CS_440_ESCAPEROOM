// Fill out your copyright notice in the Description page of Project Settings.


#include "SMultiplayerWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMultiplayerWidget::Construct(const FArguments& InArgs)
{
	
	FSlateFontInfo font = FCoreStyle::Get().GetFontStyle("Arial");
	font.Size = 40.f;
	OwnerHUD = InArgs._OwnerHUD;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Cyan)
		]
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		.Padding(FMargin(150.f))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				//host game button
				SNew(SButton)
				.ButtonColorAndOpacity(FColor::Yellow)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Host Game"))
					.Font(font)
					.Justification(ETextJustify::Center)
				]
			]

			//IP address input box
			+ SVerticalBox::Slot()
			.Padding(FMargin(10.f))
			[
				SNew(SEditableTextBox)
				.HintText(FText::FromString("I.P. Adress"))
				.Font(font)
			]

			//Join Server button
			+ SVerticalBox::Slot()
			.Padding(FMargin(10.f))
			[
				//host game button
				SNew(SButton)
				.ButtonColorAndOpacity(FColor::Yellow)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Join Game"))
					.Font(font)
					.Justification(ETextJustify::Center)
				]
			]

			//go back to main menu button
			+ SVerticalBox::Slot()
			.Padding(FMargin(20.f))
			[
				//host game button
				SNew(SButton)
				.ButtonColorAndOpacity(FColor::Yellow)
				.OnClicked(this, &SMultiplayerWidget::OnBackBtnClick)
				[
					SNew(STextBlock)
					.Text(FText::FromString("Back"))
					.Font(font)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
	
}

FReply SMultiplayerWidget::OnBackBtnClick() const
{
	if (OwnerHUD.IsValid())
	{
		OwnerHUD->removeMultiMenu();
		OwnerHUD->showMainMenu();
	}

	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
