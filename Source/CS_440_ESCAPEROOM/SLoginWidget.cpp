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
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.Padding(FMargin(300.f))
		[
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
