// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MainMenuHUD.h"
#include "SlateBasics.h"
#include "SlateExtras.h"


/**
 * 
 */
class  SMainMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwnerHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AMainMenuHUD> OwnerHUD;
	
	FReply OnPlayClicked() const;
	FReply OnSettingsClicked() const;
	FReply OnQuitClicked() const;

};
