// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class CS_440_ESCAPEROOM_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:

	TSharedPtr<class SMainMenuWidget> MainMenuWidget;
	TSharedPtr<class SLoginWidget> LoginWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;
	
	void BeginPlay();

public:
	void showLogin();
	void removeLogin();
	void showMainMenu();
	void removeMainMenu();
};
