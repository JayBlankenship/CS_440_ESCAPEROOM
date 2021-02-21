// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "SMainMenuWidget.h"
#include "SLoginWidget.h"
#include "Engine.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	showLogin();
}

void AMainMenuHUD::showLogin()
{
	if (GEngine && GEngine->GameViewport) {
		LoginWidget = SNew(SLoginWidget).OwnerHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(LoginWidget.ToSharedRef()));
		LoginWidget->SetVisibility(EVisibility::Visible);
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AMainMenuHUD::removeLogin()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
		LoginWidget->SetVisibility(EVisibility::Hidden);

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}

	showMainMenu();
}

void AMainMenuHUD::showMainMenu()
{
	if (GEngine && GEngine->GameViewport) {
		MainMenuWidget = SNew(SMainMenuWidget).OwnerHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MainMenuWidget.ToSharedRef()));
		MainMenuWidget->SetVisibility(EVisibility::Visible);
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AMainMenuHUD::removeMainMenu()
{

}


