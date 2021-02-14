// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

#define LOCTEXT_NAMESPACE "SMainMenuWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;
	
	bCanSupportFocus = true;

	const FMargin padding = FMargin(200.f, 100.f);

	const FText gameTitle = LOCTEXT("gameTitle", "EscapeRoom");
	const FText playText = LOCTEXT("playBtn", "Play");
	const FText settingText = LOCTEXT("settingsBtn", "Settings");
	const FText quitText = LOCTEXT("quitBtn", "Quit");

	FSlateFontInfo titleFont = FCoreStyle::Get().GetFontStyle("Arial");
	titleFont.Size = 60.f;

	FSlateFontInfo btnFont = FCoreStyle::Get().GetFontStyle("Arial");
	btnFont.Size = 30.f;

	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Silver)
		]
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		.Padding(padding)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Text(gameTitle)
				.Font(titleFont)
				.ColorAndOpacity(FColor::Red)
				.Justification(ETextJustify::Center)
			]
			
			//play button
			+ SVerticalBox::Slot()
			.Padding(FMargin(10.f))
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnPlayClicked)
				[
					SNew(STextBlock)
					.Font(btnFont)
					.Text(playText)
					.Justification(ETextJustify::Center)
				]
			]

			//settings button
			+ SVerticalBox::Slot()
			.Padding(FMargin(10.f))
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnSettingsClicked)
				[
					SNew(STextBlock)
					.Font(btnFont)
					.Text(settingText)
					.Justification(ETextJustify::Center)
				]
			]

			//quit button
			+ SVerticalBox::Slot()
			.Padding(FMargin(10.f))
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Font(btnFont)
					.Text(quitText)
					.Justification(ETextJustify::Center)
					
				]
			]

		]
	];
}

//TODO: Set play functionality here
FReply SMainMenuWidget::OnPlayClicked() const
{
	return FReply::Handled();
}

//TODO: Set settings functionality here
FReply SMainMenuWidget::OnSettingsClicked() const
{
	return FReply::Handled();
}

//TODO: Set quit functionality here
FReply SMainMenuWidget::OnQuitClicked() const
{
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
