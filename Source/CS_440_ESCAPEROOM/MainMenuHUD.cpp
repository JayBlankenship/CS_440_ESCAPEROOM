// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "SMainMenuWidget.h"
#include "SLoginWidget.h"
#include "SMultiplayerWidget.h"
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
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(LoginWidget.ToSharedRef()));
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


	if (GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());
		
	}

}

void AMainMenuHUD::showMainMenu()
{
	if (GEngine && GEngine->GameViewport) {
		MainMenuWidget = SNew(SMainMenuWidget).OwnerHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(MainMenuWidget.ToSharedRef()));
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
	if (GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMainMenuHUD::showMultiMenu()
{
	if (GEngine && GEngine->GameViewport) {
		MultiWidget = SNew(SMultiplayerWidget).OwnerHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget).PossiblyNullContent(MultiWidget.ToSharedRef()));
		MultiWidget->SetVisibility(EVisibility::Visible);
	}

	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AMainMenuHUD::removeMultiMenu()
{

	if (GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());

		if (PlayerOwner) {
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
			
		}
	}
}


