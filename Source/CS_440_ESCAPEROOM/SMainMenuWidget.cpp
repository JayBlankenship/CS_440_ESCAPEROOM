// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

#define LOCTEXT_NAMESPACE "SMainMenuWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;

	
	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
		[
		SNew(SOverlay)
		+ SOverlay::Slot()
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Title", "EscapeRoom"))
		]
	];
	
}

#undef LOCTEXT_NAMESPACE
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
